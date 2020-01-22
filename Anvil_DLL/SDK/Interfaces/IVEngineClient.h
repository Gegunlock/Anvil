#pragma once

#include "../Math/QAngle/QAngle.h"

namespace SDK 
{
    class IVEngineClient
    {
    public:
        virtual void vFuncPad0(void) = 0;

        virtual void vFuncPad1(void) = 0;

        virtual void vFuncPad2(void) = 0;

        virtual void vFuncPad3(void) = 0;

        virtual void vFuncPad4(void) = 0;

        virtual void vFuncPad5(void) = 0;

        virtual void vFuncPad6(void) = 0;

        virtual void vFuncPad7(void) = 0;

        virtual void vFuncPad8(void) = 0;

        virtual void vFuncPad9(void) = 0;

        virtual void vFuncPad10(void) = 0;

        virtual void vFuncPad11(void) = 0;

        virtual int GetLocalPlayer(void) = 0;

        virtual void vFuncPad13(void) = 0;

        virtual void vFuncPad14(void) = 0;

        virtual void vFuncPad15(void) = 0;

        virtual void vFuncPad16(void) = 0;

        virtual void vFuncPad17(void) = 0;

        virtual void GetViewAngles(QAngle& Angles) = 0;

        virtual void SetViewAngles(QAngle& Angles) = 0;

        virtual int GetMaxClients(void) = 0;

        virtual void vFuncPad21(void) = 0;

        virtual void vFuncPad22(void) = 0;

        virtual void vFuncPad23(void) = 0;

        virtual void vFuncPad24(void) = 0;

        virtual void vFuncPad25(void) = 0;

        virtual bool IsInGame(void) = 0;

        virtual bool IsConnected(void) = 0;

    };
}

