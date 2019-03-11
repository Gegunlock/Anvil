#include "Includes.h"


DWORD WINAPI ThreadLoop(LPVOID lpParameter)
{
	//-------------------------------------------------------------------
	//					Initalize
	//-------------------------------------------------------------------
	CUtils::SetupConsole();
	IVEngineClient *EngineClient = (IVEngineClient*)CUtils::CaptureInterface("engine.dll", "VEngineClient014");
	IBaseClientDLL *BaseClientDLL = (IBaseClientDLL*)(CUtils::CaptureInterface("client_panorama.dll", "VClient018"));

	while (true)
	{
		EngineClient->PaintAllSurfaces('a');
		system("CLS");
	}

	return 0;
}