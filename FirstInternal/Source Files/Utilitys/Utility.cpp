
#include "Includes.h"

void* CUtils::CaptureInterface(const char *DLL, const char *InterfaceName)
{
	NTypedefs::t_pfnCreateInterface fnpCreateInterface = (NTypedefs::t_pfnCreateInterface)GetProcAddress(GetModuleHandle(DLL), "CreateInterface");
	return fnpCreateInterface(InterfaceName, nullptr /*pReturnCode*/);
}

HMODULE CUtils::GetModuleAddress(std::string ModuleName)
{
	return GetModuleHandle(ModuleName.c_str());
}

BOOL CUtils::SetupConsole()
{
	if (!AllocConsole())
		return FALSE;
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle("CSGOSimpleInternal");
	return TRUE;
}