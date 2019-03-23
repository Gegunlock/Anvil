#pragma once
#include <windows.h>
#include <string>

namespace Tools 
{    
    void*        CreateInterface(const char *DLL, const char *InterfaceName);
    HMODULE      GetModuleAddress(std::string ModuleName);
    BOOL         SetupConsole(const char* Title);
}