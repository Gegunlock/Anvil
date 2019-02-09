#pragma once

#include "Includes.h"

class CVmt
{
public:

	CVmt(void* pObjectVmtPtr) : m_iVmtSize(CountFunctions())
	{
		m_Vmt = *((NTypedefs::t_pVmt)pObjectVmtPtr);
		m_pOriginalFunctionPtrArray = new void*[m_iVmtSize];
		m_pCurrentFunctionPtrArray = new void*[m_iVmtSize];
	}

	~CVmt() 
	{
		UnhookAll();
		delete[] m_pOriginalFunctionPtrArray;
		delete[] m_pCurrentFunctionPtrArray;
	}

	int CountFunctions() const;
	int FindFunctionIndex(void* pfnVoidFunctionPointer) const;
	void* FindFunctionPtr(int iIndex) const;

	bool Unhook(int iIndex);
	bool UnhookAll();
	void Hook(void* fpn, int iIndex);

protected:
	void** m_Vmt;
	const int m_iVmtSize;

	void* m_pOriginalFunctionPtrArray;
	void* m_pCurrentFunctionPtrArray;
};

