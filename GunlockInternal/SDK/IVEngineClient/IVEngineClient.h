#pragma once

namespace SDK 
{
	class IVEngineClient
	{
	public:
		virtual int GetLocalplayer();
		virtual void GetViewAngles(Vector& Angles);
		virtual int SetViewAngles(Vector& Angles);
		virtual int GetMaxClients();
		virtual bool GetIsInGame();

	private:
		const int GETLOCAPLAYERINDEX = 12;
		const int GETVIEWANGLESINDEX = 18;
		const int SETVIEWANGLESINDEX = 19;
		cosnt int GETMAXCLIENTSINDEX = 20;
		const int ISINGAMEINDEX = 26;


		typedef int(__thiscall  * GetLocalPlayer_type)(void*);							//Function Prototype for GetLocalPlayer
		typedef void(__thiscall * GetViewAngles_type)(void*, Vector&);					//Function Prototype for GetViewAngles
		typedef int(__thiscall  * SetViewAngles_type)(void*, Vector&);					//Function Prototype for SetViewAngles
		typedef int(__thiscall  * GetMaxClients_type)(void*);							//Function Prototype for GetMaxClients
		typedef bool(__thiscall * IsInGame_type)(void *);								//Function Prototype for GetIsInGameFunction
	};
}

