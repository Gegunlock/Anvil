#pragma once
#include <windows.h>

namespace Tools 
{
    class VmtHook
    {
        using pVMT_t = void***;
        using VMT_t = void**;

    public:
        VmtHook(void* pObj = nullptr);
        ~VmtHook();

        bool  Init(void* pObj);
        void* GetOriginal(int Index) const;
        bool  Hook(void* pNewFunctionPointer, int Index);
        bool  Unhook(int Index);
        void  UnhookAll(void);

    private:
        int    CountVirtualFunctions(void) const;

        pVMT_t    m_pObj = nullptr;
        VMT_t     m_NewVmt = nullptr;
        VMT_t     m_OriginalVmt = nullptr;
        byte*     m_pHookedFunctions = nullptr;
        int       m_VirtualFunctionCount = 0;
    };
}
