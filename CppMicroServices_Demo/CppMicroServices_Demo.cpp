// CppMicroServices_Demo.cpp: 定义应用程序的入口点。
//

#include "CppMicroServices_Demo.h"

using namespace std;


#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/Framework.h"
#include "cppmicroservices/FrameworkFactory.h"

using namespace cppmicroservices;


class SomeInterface
{

};


void RegisterSomeService(BundleContext context, const std::shared_ptr<SomeInterface>& service)
{
	context.RegisterService<SomeInterface>(service);
}


void UseService(BundleContext context)
{
	auto serviceRef = context.GetServiceReference<SomeInterface>();
	if (serviceRef)
	{
		auto service = context.GetService(serviceRef);
		if (service)
		{
			// do something
			std::cout << "GetService Suc" << std::endl;
		}
	}
}


int main()
{

	Framework fw = FrameworkFactory().NewFramework();

	try {
		fw.Init(); // 初始化framework
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	auto context = fw.GetBundleContext();
	auto service = make_shared<SomeInterface>();

	RegisterSomeService(context, service);

	UseService(context);


	cout << "Hello CMake." << endl;
	return 0;
}
