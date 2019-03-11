#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "../Utilitys/Utility.h"
#include "../Vector/Vector.h"
#include "../VMT/Vmt.h"
#include "../SDK/IVEngineClient/IVEngineClient.h"
#include "../SDK/CHLClient/CHLClient.h"
#include "../SDK/IBaseClientDLL/IBaseClientDLL.h"

DWORD WINAPI ThreadLoop(LPVOID lpParameter);