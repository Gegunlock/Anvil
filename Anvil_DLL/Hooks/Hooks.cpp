#include "Hooks.h"

#include <iostream>

#include "../Main/Init/Init.h"

namespace Hooks 
{
	void __fastcall GetViewAngles_hook(void* Self, int edx, QAngle & Angles)
	{
		g_Interfaces.pIVEngineClient->GetViewAngles(Angles);
		std::cout << "HOOK FUNCTION CALLED New: " << Angles.x << " " << Angles.y << std::endl;
	}
}
