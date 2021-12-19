#ifndef ITMPDLL_H
#define ITMPDLL_H

#include <string>

#if defined(US_PLATFORM_WINDOWS)
#define TMPDLL_EXPORT __declspec(dllexport)
#define TMPDLL_IMPORT __declspec(dllimport)
#define TMPDLL_LOCAL
#elif defined(US_HAVE_VISIBILITY_ATTRIBUTE)
#define TMPDLL_EXPORT __attribute__ ((visibility ("default")))
#define TMPDLL_IMPORT __attribute__ ((visibility ("default")))
#define TMPDLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define TMPDLL_EXPORT
#define TMPDLL_IMPORT
#define TMPDLL_LOCAL
#endif


class TMPDLL_EXPORT ITmpDll
{
public:
    virtual std::string showPluginName() = 0;
};


#endif
