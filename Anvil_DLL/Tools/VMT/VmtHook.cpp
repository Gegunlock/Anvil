#include "VmtHook.h"

#include <memory>

namespace Tools
{
    VmtHook::VmtHook(void * pObjToBeHooked) : m_pObj((pVMT_t)pObjToBeHooked)
    {
        if (pObjToBeHooked == nullptr)
            return;

        m_OriginalVmt = *m_pObj;

        m_VirtualFunctionCount = CountVirtualFunctions();

        m_NewVmt = new void*[m_VirtualFunctionCount + 1]();
        m_pHookedFunctions = new byte[m_VirtualFunctionCount]();

        std::memcpy(m_NewVmt, m_OriginalVmt, (m_VirtualFunctionCount + 1) * sizeof(void*));

        *m_pObj = m_NewVmt;
    }

    VmtHook::~VmtHook()
    {
        if (m_NewVmt == nullptr)
            return;

        *m_pObj = m_OriginalVmt;
        delete[] m_NewVmt;
        delete[] m_pHookedFunctions;
    }

    bool VmtHook::Init(void * pObjToBeHooked)
    {
        if (m_NewVmt == nullptr)
        {
            m_pObj = (pVMT_t)pObjToBeHooked;
            m_OriginalVmt = *m_pObj;

            m_VirtualFunctionCount = CountVirtualFunctions();

            m_NewVmt = new void*[m_VirtualFunctionCount + 1]();
            m_pHookedFunctions = new byte[m_VirtualFunctionCount]();

            std::memcpy(m_NewVmt, m_OriginalVmt, (m_VirtualFunctionCount + 1) * sizeof(void*));

            *m_pObj = m_NewVmt;
            return true;
        }
        return false;
    }

    int VmtHook::CountVirtualFunctions(void) const
    {
        if (m_OriginalVmt == nullptr)
            return -1;

        int VirtualFunctionCount = 0;
        while (m_OriginalVmt[VirtualFunctionCount])
        {
            VirtualFunctionCount++;
        }
        return VirtualFunctionCount;
    }

    void* VmtHook::GetOriginal(int Index) const
    {
        return m_OriginalVmt[Index];
    }

    bool VmtHook::Hook(void * NewFunctionPointer, int Index)
    {
        if (m_pHookedFunctions[Index] != 0 || Index > m_VirtualFunctionCount || Index < 0)
            return false;

        m_pHookedFunctions[Index] = 1;
        m_NewVmt[Index] = NewFunctionPointer;
        return true;
    }

    bool VmtHook::Unhook(int Index)
    {
        if (m_pHookedFunctions[Index] != 1 || Index > m_VirtualFunctionCount || Index < 0)
            return false;

        m_pHookedFunctions[Index] = 0;
        m_NewVmt[Index] = m_OriginalVmt[Index];
        return true;
    }

    void VmtHook::UnhookAll(void)
    {
        for (int Index = 0; Index < m_VirtualFunctionCount; Index++)
        {
            if (m_pHookedFunctions[Index] != 0)
                Unhook(Index);
            continue;
        }
    }
}
