#pragma once
#include "../../Main/Includes.h"


class CEngine
{
public:

//-------------------------------------------------------------------
//			Member Function Prototypes For Getting Engine Data
//-------------------------------------------------------------------
	virtual int GetLocalplayer();
	virtual void GetViewAngles(Vector& Angles);
	virtual int SetViewAngles(Vector& Angles);
	virtual int GetMaxClients();
	virtual bool GetIsInGame();

protected:

	CVmt EngineVmt = CVmt((void*)this);

//-------------------------------------------------------------------
//					Enum For Function VMTIndexes
//-------------------------------------------------------------------
	enum 
	{
		GETLOCAPLAYERINDEX = 12,
		GETVIEWANGLESINDEX = 18,
		SETVIEWANGLESINDEX = 19,
		GETMAXCLIENTSINDEX = 20,
		ISINGAMEINDEX = 26
	};
	
//-------------------------------------------------------------------
//					FunctionPointer TypeDefs
//-------------------------------------------------------------------

	typedef int(__thiscall *t_pfnGetLocalPlayer)(void*);							//Function Prototype for GetLocalPlayer
	typedef void(__thiscall *t_pfnGetViewAngles)(void*, Vector&);					//Function Prototype for GetViewAngles
	typedef int(__thiscall * t_pfnSetViewAngles)(void*, Vector&);					//Function Prototype for SetViewAngles
	typedef int(__thiscall * t_pfnGetMaxClients)(void*);							//Function Prototype for GetMaxClients
	typedef bool(__thiscall *t_pfnIsInGame)(void *);								//Function Prototype for GetIsInGameFunction
};
