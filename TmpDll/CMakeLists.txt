
cmake_minimum_required (VERSION 3.8)


set(HEADER TmpDll.h
           Activator.hpp 
           ITmpDll.h)

set(SRC TmpDll.cpp
        Activator.cpp)

set(CPPMICROSERVICES_BUILD ../../../../Third_Part/CppMicroServices/build)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # CppMicroServices头文件路径
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Debug/include/cppmicroservices4)
    set(CppMicroServices_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Debug/share/cppmicroservices4/cmake")
else()
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Release/include/cppmicroservices4)
    set(CppMicroServices_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Release/share/cppmicroservices4/cmake")
endif()


add_library(TmpDll SHARED ${SRC} ${HEADER})

set(_bundle_name TmpDll)

set_target_properties(TmpDll PROPERTIES
  # This is required for every bundle
  COMPILE_DEFINITIONS US_BUNDLE_NAME=${_bundle_name}
  # This is for convenience, used by other CMake functions
  US_BUNDLE_NAME ${_bundle_name}
  )

find_package(CppMicroServices REQUIRED)
target_link_libraries(TmpDll CppMicroServices)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(TMPDLL_DLL_PATH ../out/build/x64-Debug/TmpDll/TmpDll.dll)
    set(USRESOURCE_COMPILE4_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Debug/bin")
else()
    set(TMPDLL_DLL_PATH ../out/build/x64-Release/TmpDll/TmpDll.dll)
    set(USRESOURCE_COMPILE4_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Release/bin")
endif()

#生成插件
add_custom_command(TARGET TmpDll
                   POST_BUILD
                   COMMAND ${USRESOURCE_COMPILE4_PATH}/usResourceCompiler4 -n ${_bundle_name}
                   -b "${CMAKE_CURRENT_SOURCE_DIR}/${TMPDLL_DLL_PATH}" -m "${CMAKE_CURRENT_SOURCE_DIR}/manifest.json")
