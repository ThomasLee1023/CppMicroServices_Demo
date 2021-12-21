// CppMicroServices_Demo.cpp: 定义应用程序的入口点。
//

#include "CppMicroServices_Demo.h"

using namespace std;


#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/Framework.h"
#include "cppmicroservices/FrameworkFactory.h"

using namespace cppmicroservices;

#include "../TmpDll/ITmpDll.h"

#include <memory>


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

	fw.Start();

	auto context = fw.GetBundleContext();
	auto service = make_shared<SomeInterface>();

	
	std::vector<Bundle> bundles;
	try {
		// location为相对于可执行程序的地址
		string location = "../TmpDll/TmpDll.dll";
		bundles = context.InstallBundles(location);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	//std::vector<Bundle> bundles = context.GetBundles();
	for (auto& x : bundles)
	{
		auto symName = x.GetSymbolicName();
		if (symName == "TmpDll")
		{
			x.Start();
			ServiceReference<ITmpDll> ref = context.GetServiceReference<ITmpDll>();
			shared_ptr<ITmpDll> pTmpDll = context.GetService<ITmpDll>(ref);

			std::cout << pTmpDll->showPluginName() << std::endl;
			x.Stop();
		}
	}


	RegisterSomeService(context, service);

	UseService(context);

	fw.Stop();

	cout << "Hello CMake." << endl;
	return 0;
}
