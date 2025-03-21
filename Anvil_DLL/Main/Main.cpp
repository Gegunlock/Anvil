#include <windows.h>

#include <iostream>
#include <string>

#include "../Tools/Utilities/Utility.h"
#include "Init/Interfaces/Interfaces.h"
#include "Init/Hooks/Hooks.h"

DWORD WINAPI Init(LPVOID lpThreadParameter)
{

    if (Interfaces::Initialize())
    {
        Hooks::Initialize();
    }
    else 
    {
        Tools::SetupConsole("Anvil");
        std::cout << "Failed To Capture Interfaces..." << std::endl;
    }

    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, Init, NULL, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
        break;
    }
    return TRUE;
}

