#pragma once

#include "IClientEntity.h"

namespace SDK 
{
    class IClientEntityList 
    {
    public:
        virtual void vFuncPad0(void) = 0;

        virtual void vFuncPad1(void) = 0;

        virtual void vFuncPad2(void) = 0;

        virtual IClientEntity* GetClientEntity(int entNum) = 0;

        virtual void vFuncPad4(void) = 0;
    };
}