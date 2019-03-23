#include "Utility.h"

#include <Psapi.h>

namespace Tools
{
    void* CreateInterface(const char *DLL, const char *InterfaceName)
    {
        using fCreateInterface_t = void*(*)(const char *, int *);
        return ((fCreateInterface_t)GetProcAddress(GetModuleHandle(DLL), "CreateInterface"))(InterfaceName, nullptr);
    }

    HMODULE GetModuleAddress(std::string ModuleName)
    {
        return GetModuleHandle(ModuleName.c_str());
    }

    BOOL SetupConsole(const char* Title)
    {
        if (!AllocConsole())
            return FALSE;
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout);
        SetConsoleTitle(Title);
        return TRUE;
    }
}
