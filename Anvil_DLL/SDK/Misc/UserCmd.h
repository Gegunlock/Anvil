#pragma once

#include "../Math/QAngle/QAngle.h"

namespace SDK 
{
    struct CUserCmd
    {
        int		command_number;
        int		tick_count;
        QAngle	viewangles;
        Vector	aimdirection;
        Vector  move;
        int		buttons;
        char    impulse;
        int		weaponselect;
        int		weaponsubtype;
        int		random_seed;
        short	mousedx;
        short	mousedy;
        bool	hasbeenpredicted;
        char	pad_0x4C[0x18];
    };
}