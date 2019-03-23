#pragma once

#include <d3d9.h>

#include "../../../SDK/Math/QAngle/QAngle.h"
#include "../../Tools/VMT/VMTableHook.h"

namespace Hooks 
{
    const int ENDSCENE_INDEX = 42;

    void Initialize(void);
    void ShutDown(void);
}

