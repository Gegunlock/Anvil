#include "Interfaces.h"

#include <d3d9.h>

#include "../../Tools/Utilities/Utility.h"
#include "../../Tools/Utilities/Patternscaning.h"

namespace Interfaces 
{
    SDK::IVEngineClient* pEngine = nullptr;
    SDK::IBaseClientDLL* pClient = nullptr;
    SDK::IClientMode* pClientMode = nullptr;
    SDK::IClientEntityList* pEntityList = nullptr;
    SDK::ISurface* pSurface = nullptr;
    SDK::IInputSystem* pInputSystem = nullptr;

    DWORD pDirectXDevice = NULL;

    bool Initialize(void)
    {
        // Capture Interfaces
        pEngine = (SDK::IVEngineClient*)Tools::CreateInterface("engine.dll", "VEngineClient014");
        pClient = (SDK::IBaseClientDLL*)Tools::CreateInterface("client_panorama.dll", "VClient018");
        pClientMode = **(SDK::IClientMode***)((*(uintptr_t**)pClient)[10] + 0x5);  // https://www.unknowncheats.me/wiki/Hooking_CreateMove_from_IClientMode
        pEntityList = (SDK::IClientEntityList*)Tools::CreateInterface("client_panorama.dll", "VClientEntityList003");
        pSurface = (SDK::ISurface*)Tools::CreateInterface("vguimatsurface.dll", "VGUI_Surface031");
        pInputSystem = (SDK::IInputSystem*)Tools::CreateInterface("inputsystem.dll", "InputSystemVersion001");


        // Get DirectX pointer
        pDirectXDevice = **(DWORD**)(Tools::FindPattern("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1);

        return Validate();
    }

    bool Validate(void) 
    {
        if (pEngine == nullptr)
        {
            return false;
        }

        if (pClient == nullptr) 
        {
            return false;
        }

        if (pClientMode == nullptr) 
        {
            return false;
        }

        if (pEntityList == nullptr) 
        {
            return false;
        }

        if (pSurface == nullptr) 
        {
            return false;
        }

        if (pInputSystem == nullptr) 
        {
            return false;
        }

        if (pDirectXDevice == NULL)
        {
            return false;
        }

        return true;
    }
}
