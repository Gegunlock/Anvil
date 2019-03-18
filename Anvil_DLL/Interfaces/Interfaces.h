#pragma once
#include "../SDK/IVEngineClient/IVEngineClient.h"
#include "../SDK/IBaseClientDLL/IBaseClientDLL.h"

class Interfaces 
{
public:
	Interfaces();
	~Interfaces();

	SDK::IVEngineClient* GetIVEngineClientInterface();
	SDK::IBaseClientDLL* GetIBaseClientDLL();

	SDK::IVEngineClient* pIVEngineClient;
	SDK::IBaseClientDLL* pIBaseClientDLL;

private:
	SDK::IVEngineClient* pIVEngineClient_GameVersion;
	SDK::IBaseClientDLL* pIBaseClientDLL_GameVersion;
};

extern Interfaces g_Interfaces;