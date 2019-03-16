#pragma once
#include <windows.h>

namespace Tools 
{
	class VirtualMethodTableHook
	{
		typedef void*** pVMT_t;
		typedef void**	VMT_t;

	public:
		VirtualMethodTableHook(void* pObj = nullptr);
		~VirtualMethodTableHook();

		bool Init(void* pObj);
		bool Hook(void* pNewFunctionPointer, int Index);
		bool Unhook(int Index);
		void UnhookAll(void);

	private:
		int	 CountVirtualFunctions(void) const;

		pVMT_t	m_pObj = nullptr;
		VMT_t	m_NewVmt = nullptr;
		VMT_t	m_OriginalVmt = nullptr;
		byte*   m_pHookedFunctions = nullptr;
		int		m_VirtualFunctionCount = 0;
	};
}
