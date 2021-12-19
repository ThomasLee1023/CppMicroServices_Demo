#ifndef ACTIVATOR_HPP
#define ACTIVATOR_HPP

#include "cppmicroservices/BundleActivator.h"
using namespace cppmicroservices;

class Activator : public BundleActivator
{
public:
    Activator() {}

public:

    virtual void Start(BundleContext context) override;

    virtual void Stop(BundleContext context) override;

};




#endif // ACTIVATOR_HPP
