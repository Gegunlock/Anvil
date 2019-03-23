#pragma once
#include "../Misc/CUserCmd.h"

namespace SDK 
{
    class IClientMode
    {
    public:
        virtual void Unknown0(void) = 0;
        virtual void Unknown1(void) = 0;
        virtual void Unknown2(void) = 0;
        virtual void Unknown3(void) = 0;
        virtual void Unknown4(void) = 0;
        virtual void Unknown5(void) = 0;
        virtual void Unknown6(void) = 0;
        virtual void Unknown7(void) = 0;
        virtual void Unknown8(void) = 0;
        virtual void Unknown9(void) = 0;
        virtual void Unknown10(void) = 0;
        virtual void Unknown11(void) = 0;
        virtual void Unknown12(void) = 0;
        virtual void Unknown13(void) = 0;
        virtual void Unknown14(void) = 0;
        virtual void Unknown15(void) = 0;
        virtual void Unknown16(void) = 0;
        virtual void Unknown17(void) = 0;
        virtual bool OverrideView(void) = 0;  //18 Not Correct Signature
        virtual void Unknown19(void) = 0;
        virtual void Unknown20(void) = 0;
        virtual void Unknown21(void) = 0;
        virtual void Unknown22(void) = 0;
        virtual void Unknown23(void) = 0;
        virtual bool CreateMove(float flInputrSampleTime, CUserCmd* cmd) = 0;  //24
    };
}
