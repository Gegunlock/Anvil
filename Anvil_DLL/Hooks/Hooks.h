#pragma once

#include "../Math/QAngle/QAngle.h"
#include "../Interfaces/Interfaces.h"

namespace Hooks 
{
	//NOTE all hooks must be __fastcall with first param being the this ptr and second the edx register unless explicitly declared`quit
	void __fastcall GetViewAngles_hook(void* Self, int edx, QAngle & Angles);
}

