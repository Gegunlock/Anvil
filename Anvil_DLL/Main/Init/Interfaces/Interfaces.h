#pragma once

#include <windows.h>

#include "../../../SDK/Interfaces/IBaseClientDLL.h"
#include "../../../SDK/Interfaces/IVEngineClient.h"
#include "../../../SDK/Interfaces/IClientMode.h"
#include "../../../SDK/Interfaces/IClientEntityList.h"
#include "../../../SDK/Interfaces/ISurface.h"
#include "../../../SDK/Interfaces/IInputSystem.h"

namespace Interfaces 
{
    extern SDK::IVEngineClient* pEngine;
    extern SDK::IBaseClientDLL* pClient;
    extern SDK::IClientMode* pClientMode;
    extern SDK::IClientEntityList* pEntityList;
    extern SDK::ISurface* pSurface;
    extern SDK::IInputSystem* pInputSystem;

    extern DWORD pDirectXDevice;

    bool Initialize(void);
    bool Validate(void);
}