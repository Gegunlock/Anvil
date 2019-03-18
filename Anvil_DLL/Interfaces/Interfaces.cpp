#include "Interfaces.h"

#include <thread>
#include <iostream>

#include "../Tools/Utilitys/Utility.h"

Interfaces::Interfaces()
{
	typedef void*** pVMT_t;

	pIVEngineClient_GameVersion = (SDK::IVEngineClient*)Tools::CreateInterface("engine.dll","VEngineClient014");
	pIVEngineClient = new SDK::IVEngineClient;
	*(pVMT_t)pIVEngineClient = *(pVMT_t)pIVEngineClient_GameVersion;  // Overwrites the Copy pIVEngineClient VMT with working VMT

	pIBaseClientDLL_GameVersion = (SDK::IBaseClientDLL*)Tools::CreateInterface("client_panorama.dll", "VClient017");
	pIBaseClientDLL = new SDK::IBaseClientDLL;
	*(pVMT_t)pIBaseClientDLL = *(pVMT_t)pIBaseClientDLL_GameVersion;  // Overwrites the Copy pIBaseClientDLL VMT with working VMT
}

Interfaces::~Interfaces() 
{
	delete pIVEngineClient;
	delete pIBaseClientDLL;
}

SDK::IVEngineClient* Interfaces::GetIVEngineClientInterface()
{
	return (SDK::IVEngineClient*)Tools::CreateInterface("engine.dll", "VEngineClient014");
}

SDK::IBaseClientDLL* Interfaces::GetIBaseClientDLL() 
{
	return (SDK::IBaseClientDLL*)Tools::CreateInterface("client_panorama.dll", "VClient017");
}

Interfaces g_Interfaces;
