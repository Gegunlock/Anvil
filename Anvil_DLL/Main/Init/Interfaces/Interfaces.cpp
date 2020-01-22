#include "Interfaces.h"

#include <d3d9.h>

#include "../../Tools/Utilitys/Utility.h"
#include "../../Tools/Utilitys/Patternscaning.h"

namespace Interfaces 
{
    SDK::IVEngineClient* pEngine = nullptr;
    SDK::IBaseClientDLL* pClient = nullptr;
    SDK::IClientModeShared* pClientMode = nullptr;
    DWORD pDirectXDevice = NULL;

    bool Initialize(void)
    {
        // Capture Interfaces
        pEngine = (SDK::IVEngineClient*)Tools::CreateInterface("engine.dll", "VEngineClient014");
        pClient = (SDK::IBaseClientDLL*)Tools::CreateInterface("client_panorama.dll", "VClient018");
        pClientMode = **(SDK::IClientModeShared***)((*(uintptr_t**)pClient)[10] + 0x5);  // https://www.unknowncheats.me/wiki/Hooking_CreateMove_from_IClientMode

        // Get DirectX pointer
        while (pDirectXDevice == NULL)
        {
            pDirectXDevice = **(DWORD**)(Tools::FindPattern("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1);
        }

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

        if (pDirectXDevice == NULL) 
        {
            return false;
        }

        return true;
    }
}
