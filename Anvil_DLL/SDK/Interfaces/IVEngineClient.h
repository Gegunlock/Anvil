#pragma once

#include "../Math/QAngle/QAngle.h"
#include "../../Tools/Utilitys/Utility.h"

namespace SDK 
{
    class IVEngineClient
    {
    public:
        int GetLocalPlayer(void)  // 12
        {
            using fGetLocalPlayer_t = int(__thiscall*)(void);
            fGetLocalPlayer_t oGetLocalPlayer = (fGetLocalPlayer_t)Tools::GetVirtualMethod(this, 12);
            return oGetLocalPlayer();
        }

        void GetViewAngles(QAngle& Angles)  // 18
        {
            using fGetViewAngles = void(__thiscall*)(QAngle&);
            fGetViewAngles oGetViewAngles = (fGetViewAngles)Tools::GetVirtualMethod(this, 18);
            oGetViewAngles(Angles);
        }

        void SetViewAngles(QAngle& Angles)  // 19
        {
            using fSetViewAngles = void(__thiscall*)(QAngle&);
            fSetViewAngles oSetViewAngles = (fSetViewAngles)Tools::GetVirtualMethod(this, 19);
            oSetViewAngles(Angles);
        }

        int GetMaxClients(void)  //20
        {
            using fGetMaxClients = int(__thiscall*)(void);
            fGetMaxClients oGetMaxClients = (fGetMaxClients)Tools::GetVirtualMethod(this, 20);
            return oGetMaxClients();
        }

        bool IsInGame(void)  // 26 
        {
            using fIsInGame_t = bool(__thiscall*)(void);
            fIsInGame_t oIsInGame = (fIsInGame_t)Tools::GetVirtualMethod(this, 26);
            return oIsInGame();
        }

        bool IsConnected(void)  //27
        {
            using fIsConnected = bool(__thiscall*)(void);
            fIsConnected oIsConnected = (fIsConnected)Tools::GetVirtualMethod(this, 27);
            return oIsConnected();
        }
    };
}

