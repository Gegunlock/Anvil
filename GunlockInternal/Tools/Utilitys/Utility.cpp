#include "Utility.h"

namespace Tools
{
	typedef void* (*CreateInterface_type)(const char *pName, int *pReturnCode);

	void* CaptureInterface(const char *DLL, const char *InterfaceName)
	{
		CreateInterface_type CreateInterface = (CreateInterface_type)GetProcAddress(GetModuleHandle(DLL), "CreateInterface");
		return CreateInterface(InterfaceName, nullptr /*pReturnCode*/);
	}

	HMODULE GetModuleAddress(std::string ModuleName)
	{
		return GetModuleHandle(ModuleName.c_str());
	}

	BOOL SetupConsole()
	{
		if (!AllocConsole())
			return FALSE;
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		SetConsoleTitle("CSGOSimpleInternal");
		return TRUE;
	}
}
