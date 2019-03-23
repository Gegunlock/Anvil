#pragma once
#include "CUserCmd.h"
#include "../../Math/QAngle/QAngle.h"

namespace SDK 
{
    class CInput
    {
    public:
        char                pad_0x00[0x0C];
        bool                m_trackir_available;
        bool                m_mouse_initiated;
        bool                m_mouse_active;
        bool                m_fJoystickAdvancedInit;
        char                pad_0x08[0x2C];
        void*               m_pKeys;
        char                pad_0x38[0x6C];
        bool                m_fCameraInterceptingMouse;
        bool                m_fCameraInThirdPerson;
        bool                m_fCameraMovingWithMouse;
        Vector		        m_vecCameraOffset;
        bool                m_fCameraDistanceMove;
        int                 m_nCameraOldX;
        int                 m_nCameraOldY;
        int                 m_nCameraX;
        int                 m_nCameraY;
        bool                m_CameraIsOrthographic;
        Vector              m_angPreviousViewAngles;
        Vector              m_angPreviousViewAnglesTilt;
        float               m_flLastForwardMove;
        int                 m_nClearInputState;
        char                pad_0xE4[0x8];
        CUserCmd*           m_pCommands;
        CVerifiedUserCmd*   m_pVerifiedCommands;

        inline CUserCmd* GetUserCmd(int sequence_number);
        inline CUserCmd * GetUserCmd(int nSlot, int sequence_number);
        inline CVerifiedUserCmd* GetVerifiedCmd(int sequence_number);
    };
}
