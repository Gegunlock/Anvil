
#include "Includes.h"

//-------------------------------------------------------------------
//			Member Function Implementation For Getting Engine Data
//-------------------------------------------------------------------
int CEngine::GetLocalplayer()
{
	t_pfnGetLocalPlayer pfnGetLocalPlayer = (t_pfnGetLocalPlayer)EngineVmt.FindFunctionPtr(GETLOCAPLAYERINDEX); //Get The Function
	return pfnGetLocalPlayer(this); //Call and return result
}

void CEngine::GetViewAngles(Vector& Angles) 
{
	t_pfnGetViewAngles pfnGetViewAngles = (t_pfnGetViewAngles)EngineVmt.FindFunctionPtr(GETVIEWANGLESINDEX);
	pfnGetViewAngles(this, Angles);
}

int CEngine::SetViewAngles(Vector& Angles) 
{
	t_pfnSetViewAngles pfnSetViewAngles = (t_pfnSetViewAngles)EngineVmt.FindFunctionPtr(SETVIEWANGLESINDEX);
	return pfnSetViewAngles(this, Angles);
}

int CEngine::GetMaxClients() 
{
	t_pfnGetMaxClients pfnGetMaxClients = (t_pfnGetMaxClients)EngineVmt.FindFunctionPtr(GETMAXCLIENTSINDEX);
	return pfnGetMaxClients(this);
}

bool CEngine::GetIsInGame()
{
	t_pfnIsInGame pfnIsInGame = (t_pfnIsInGame)EngineVmt.FindFunctionPtr(ISINGAMEINDEX);
	return pfnIsInGame(this);
}
