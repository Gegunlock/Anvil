#include "Interfaces.h"

#include "../../Tools/Utilitys/Utility.h"
#include "../../Tools/Utilitys/Patternscaning.h"

namespace Interfaces 
{
    SDK::IVEngineClient* pEngine = nullptr;
    SDK::IBaseClientDLL* pHLClient = nullptr;
    DWORD pDirectXDevice = NULL;

    bool Initialize(void)
    {
        // Capture Interfaces
        pEngine = (SDK::IVEngineClient*)Tools::CreateInterface("engine.dll", "VEngineClient014");
        pHLClient = (SDK::IBaseClientDLL*)Tools::CreateInterface("client_panorama.dll", "VClient018");

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

        if (pHLClient == nullptr) 
        {
            return false;
        }

        return true;
    }
}
