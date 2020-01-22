#pragma once

#include <windows.h>
#include <string>

namespace SDK 
{
    class IClientEntity 
    {
    public:
        char pad_0000[256]; //0x0000
        uint32_t iHealth; //0x0100
        uint32_t iFlag; //0x0104
        char pad_0108[60]; //0x0108
    };
}