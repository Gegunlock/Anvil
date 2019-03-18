#pragma once
#include "../../Math/QAngle/QAngle.h"

namespace SDK 
{
	class IVEngineClient
	{
	public:
		virtual void Unknown0(void);  //0
		virtual void Unknown1(void);  //1
		virtual void Unknown2(void);  //2
		virtual void Unknown3(void);  //3
		virtual void Unknown4(void);  //4
		virtual void Unknown5(void);  //5
		virtual void Unknown6(void);  //6
		virtual void Unknown7(void);  //7
		virtual void Unknown8(void);  //8
		virtual void Unknown9(void);  //9
		virtual void Unknown10(void);  //10
		virtual void Unknown11(void);  //11
		virtual int	 GetLocalPlayer(void);  // 12
		virtual void Unknown13(void);  //13
		virtual void Unknown14(void);  //14
		virtual void Unknown15(void);  //15
		virtual void Unknown16(void);  //16
		virtual void Unknown17(void);  //17
		virtual void GetViewAngles(QAngle& Angles);  // 18
		virtual int	 SetViewAngles(QAngle& Angles);  // 19
		virtual int  GetMaxClients(void);  //20
		virtual void unknown21(void);  //21
		virtual void unknown22(void);  //22
		virtual void unknown23(void);  //23
		virtual void unknown24(void);  //24
		virtual void unknown25(void);  //25
		virtual bool IsInGame(void);  // 26
		virtual bool IsConnected(void);  //27
	};
}

