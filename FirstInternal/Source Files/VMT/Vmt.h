#pragma once
#include "../Main/Includes.h"

class CVmt 
{
public:
	CVmt(void* pObjectVmtPtr) 
	{
		m_Vmt = *((NTypedefs::t_pVmt)pObjectVmtPtr);
	}

	int CountFunctions();
	int FindFunctionIndex(void* pfnVoidFunctionPointer);
	void* FindFunctionPtr(int iIndex);

private:
	void** m_Vmt;
}; 