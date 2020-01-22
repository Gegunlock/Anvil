#pragma once

#include <windows.h>

#include "../../../SDK/Interfaces/IBaseClientDLL.h"
#include "../../../SDK/Interfaces/IVEngineClient.h"
#include "../../../SDK/Interfaces/IClientModeShared.h"


namespace Interfaces 
{
    extern SDK::IVEngineClient* pEngine;
    extern SDK::IBaseClientDLL* pClient;
    extern SDK::IClientModeShared* pClientMode;

    extern DWORD pDirectXDevice;

    bool Initialize(void);
    bool Validate(void);
}