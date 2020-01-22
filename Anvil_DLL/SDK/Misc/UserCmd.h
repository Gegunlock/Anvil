#pragma once

#include "../Math/QAngle/QAngle.h"

namespace SDK 
{

    class CUserCmd
    {
    public:

        enum Flags
        {
            IN_ATTACK1 = 1 << 0,
            IN_JUMP = 1 << 1,
            IN_DUCK = 1 << 2,
            IN_FORWARD = 1 << 3,
            IN_BACK = 1 << 4,
            IN_USE = 1 << 5,
            IN_CANCEL = 1 << 6,
            IN_LEFT = 1 << 7,
            IN_RIGHT = 1 << 8,
            IN_MOVELEFT = 1 << 9,
            IN_MOVERIGHT = 1 << 10,
            IN_ATTACK2 = 1 << 11,
            IN_RUN = 1 << 12,
            IN_RELOAD = 1 << 13,
            IN_ALT1 = 1 << 14,
            IN_ALT2 = 1 << 15,
            IN_SCORE = 1 << 16,      // Used by client.dll for when scoreboard is held down
            IN_SPEED = 1 << 17,      // Player is holding the speed key
            IN_WALK = 1 << 18,     // Player holding walk key
            IN_ZOOM = 1 << 19,     // Zoom key for HUD zoom
            IN_WEAPON1 = 1 << 20,   // weapon defines these bits
            IN_WEAPON2 = 1 << 21,   // weapon defines these bits
            IN_BULLRUSH = 1 << 22,
            IN_GRENADE1 = 1 << 23,  // grenade 1
            IN_GRENADE2 = 1 << 24,  // grenade 2
            IN_LOOKSPIN = 1 << 25
        };

        virtual ~CUserCmd() {};

        CUserCmd& operator =(const CUserCmd& src)
        {
            if (this == &src)
                return *this;

            command_number = src.command_number;
            tick_count = src.tick_count;
            viewangles = src.viewangles;
            forward_move = src.forward_move;
            side_move = src.side_move;
            up_move = src.up_move;
            buttons = src.buttons;
            impulse = src.impulse;
            weapon_select = src.weapon_select;
            weapon_sub_type = src.weapon_sub_type;
            random_seed = src.random_seed;
            mousedx = src.mousedx;
            mousedy = src.mousedy;

            has_been_predicted = src.has_been_predicted;
            headangles = src.headangles;
            headoffset = src.headoffset;
            return *this;
        }

        CUserCmd(const CUserCmd& src)
        {
            *this = src;
        }

        int command_number;
        int tick_count;
        QAngle viewangles;
        QAngle aimdirection;
        float forward_move;
        float side_move;
        float up_move;
        int  buttons;
        BYTE impulse;
        int  weapon_select;
        int  weapon_sub_type;
        int  random_seed;
        short mousedx;
        short mousedy;
        bool has_been_predicted;
        QAngle headangles;
        QAngle headoffset;
    };
}
