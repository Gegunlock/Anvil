#pragma once
#include "../Math/QAngle/QAngle.h"

namespace SDK 
{
    class IVEngineClient
    {
    public:
        virtual void Unknown0(void) = 0;  //0
        virtual void Unknown1(void) = 0;  //1
        virtual void Unknown2(void) = 0;  //2
        virtual void Unknown3(void) = 0;  //3
        virtual void Unknown4(void) = 0;  //4
        virtual void Unknown5(void) = 0;  //5
        virtual void Unknown6(void) = 0;  //6
        virtual void Unknown7(void) = 0;  //7
        virtual void Unknown8(void) = 0;  //8
        virtual void Unknown9(void) = 0;  //9
        virtual void Unknown10(void) = 0;  //10
        virtual void Unknown11(void) = 0;  //11
        virtual int  GetLocalPlayer(void) = 0;  // 12
        virtual void Unknown13(void) = 0;  //13
        virtual void Unknown14(void) = 0;  //14
        virtual void Unknown15(void) = 0;  //15
        virtual void Unknown16(void) = 0;  //16
        virtual void Unknown17(void) = 0;  //17
        virtual void GetViewAngles(QAngle& Angles) = 0;  // 18
        virtual int  SetViewAngles(QAngle& Angles) = 0;  // 19
        virtual int  GetMaxClients(void) = 0;  //20
        virtual void unknown21(void) = 0;  //21
        virtual void unknown22(void) = 0;  //22
        virtual void unknown23(void) = 0;  //23
        virtual void unknown24(void) = 0;  //24
        virtual void unknown25(void) = 0;  //25
        virtual bool IsInGame(void) = 0;  // 26
        virtual bool IsConnected(void) = 0;  //27
    };
}

