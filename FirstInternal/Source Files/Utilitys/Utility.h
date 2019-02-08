#pragma once
#include "../Main/Includes.h"

namespace NTypedefs
{
	//-------------------------------------------------------------------
	//					Usefull Typedefs 
	//-------------------------------------------------------------------
	typedef void* (*t_pfnCreateInterface)(const char *pName, int *pReturnCode);		//Function Prototype for CreateInterface
	typedef void*** t_pVmt;															//Cast InterfacePtr To this for its VMT
}


class CUtils 
{
public:
	//-------------------------------------------------------------------
	//							Utility Functions
	//-------------------------------------------------------------------
	static void*		CaptureInterface(const char *DLL, const char *InterfaceName);
	static HMODULE		GetModuleAddress(std::string ModuleName);
	static BOOL			SetupConsole();
	static DWORD		FindPattern(char* Pattern);
};