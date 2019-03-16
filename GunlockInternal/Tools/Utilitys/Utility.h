#pragma once
#include <windows.h>
#include <string>

namespace Tools 
{	
	void*		CaptureInterface(const char *DLL, const char *InterfaceName);
	HMODULE		GetModuleAddress(std::string ModuleName);
	BOOL		SetupConsole();
	DWORD		FindPattern(char* Pattern);
}