#pragma once

#include <d3d9.h>

#include "../../SDK/Interfaces/IVEngineClient.h"
#include "../../SDK/Interfaces/IBaseClientDLL.h"

namespace Interfaces 
{
    extern SDK::IVEngineClient* pEngine;
    extern SDK::IBaseClientDLL* pHLClient;
    extern DWORD pDirectXDevice;

    bool Initialize(void);
    bool Validate(void);
}