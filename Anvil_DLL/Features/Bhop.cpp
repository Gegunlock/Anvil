#include "Bhop.h"

#include "../Main/Settings.h"

bool Config::Bunnyhop::Enable = true;

namespace Features 
{
    void Bunnyhop(SDK::IClientEntity* ClientEntity, SDK::CUserCmd* UserCmd)
    {
        if (!(Config::Bunnyhop::Enable)) 
            return;

        if ((UserCmd->buttons & SDK::CUserCmd::Flags::IN_JUMP) && !(ClientEntity->iFlag & 1)) 
        {
            UserCmd->buttons &= ~SDK::CUserCmd::Flags::IN_JUMP;
        }
    }
}
