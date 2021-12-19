
#include "Activator.hpp"
#include "TmpDll.h"

//#include <memory>

void Activator::Start(BundleContext context)
{
    auto pTmpDll = std::make_shared<TmpDll>();
    context.RegisterService<ITmpDll>(pTmpDll);

}

void Activator::Stop(BundleContext context)
{

}

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(Activator)
