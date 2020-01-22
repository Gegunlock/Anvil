#pragma once
#include <windows.h>

namespace Tools 
{
    class VirtualMethodTableHook
    {
        using ppVMT_t = void***;
        using pVMT_t = void**;

    public:
        VirtualMethodTableHook(void* pObj = nullptr);
        ~VirtualMethodTableHook();

        bool  Init(void* pObj);
        void* GetOriginal(int Index) const;
        bool  Hook(void* pNewFunctionPointer, int Index);
        bool  Unhook(int Index);
        void  UnhookAll(void);

    private:
        int    CountVirtualFunctions(void) const;

        ppVMT_t    m_pObj = nullptr;
        pVMT_t     m_NewVmt = nullptr;
        pVMT_t     m_OriginalVmt = nullptr;
        byte*     m_pHookedFunctions = nullptr;
        int       m_VirtualFunctionCount = 0;
    };
}
