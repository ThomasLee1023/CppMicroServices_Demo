# CMakeList.txt: CppMicroServices_Demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(CPPMICROSERVICES_BUILD ../../../../Third_Part/CppMicroServices/build)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # CppMicroServices头文件路径
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Debug/include/cppmicroservices4)
    set(CppMicroServices_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Debug/share/cppmicroservices4/cmake")
else()
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Release/include/cppmicroservices4)
    set(CppMicroServices_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${CPPMICROSERVICES_BUILD}/x64-Release/share/cppmicroservices4/cmake")
endif()

find_package(CppMicroServices REQUIRED)

# 将源代码添加到此项目的可执行文件。
add_executable (CppMicroServices_Demo "CppMicroServices_Demo.cpp" "CppMicroServices_Demo.h")

target_link_libraries(CppMicroServices_Demo CppMicroServices)


# TODO: 如有需要，请添加测试并安装目标。
