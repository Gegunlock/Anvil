#include "Init.h"

#include <iostream>
#include <string>

#include "../../Interfaces/Interfaces.h"
#include "../../Tools/Utilitys/Utility.h"
#include "../../Tools/VMT/VMTableHook.h"
#include "../../Hooks/Hooks.h"

namespace Init
{
	DWORD WINAPI Init(LPVOID lpThreadParameter)
	{
		Tools::SetupConsole("Anvil Beta");
		std::cout << "INJECTED" << std::endl;

		Tools::VirtualMethodTableHook IVEngineClient_hook(g_Interfaces.GetIVEngineClientInterface());
		IVEngineClient_hook.Hook(Hooks::GetViewAngles_hook, 18);
		
		while (true) 
		{
		}
		return 0;
	}
}
