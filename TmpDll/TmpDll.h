#ifndef TMP_DLL_H
#define TMP_DLL_H

#include "ITmpDll.h"

class TmpDll : public ITmpDll
{
public:
    TmpDll();
    virtual ~TmpDll();

public:
    virtual std::string showPluginName();

};

#endif // TMP_DLL_H
