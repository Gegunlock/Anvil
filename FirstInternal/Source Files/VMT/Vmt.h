#pragma once

#include "Includes.h"

class CVmt
{
public:

	CVmt(void* pObjectVmtPtr) : m_iVmtSize(CountFunctions())
	{
		m_Vmt = *((NTypedefs::t_pVmt)pObjectVmtPtr);
	}

	virtual int CountFunctions() const;
	virtual int FindFunctionIndex(void* pfnVoidFunctionPointer) const;
	virtual void* FindFunctionPtr(int iIndex) const;

protected:
	void** m_Vmt;
	int m_iVmtSize;
};

class CVmtHookManager : public CVmt
{
public:
	~CVmtHookManager() 
	{

	}

	bool UnhookAll() 
	{
		for (int i = 0; i < m_iVmtSize; i++) 
		{
			if (!Unhook(i))
				return false;
		}
		return true;
	}

	bool Unhook(int iIndex) 
	{
		if (m_pfnOriginalFunctionPointer[iIndex] = NULL)
			return false;
		else 
		{
			m_Vmt[iIndex] = m_pfnOriginalFunctionPointer[iIndex];
			m_pfnCurrentFunctionPointer[iIndex] = m_pfnOriginalFunctionPointer[iIndex];
		}
	}

	bool Hook(void* fpn, int iIndex) 
	{

	}

	void UpdateSize(int iNewSize) 
	{
		m_iVmtSize = iNewSize;
	}

private:
	void* m_pfnOriginalFunctionPointer[5] = {0,0,0,0,0};
	void* m_pfnCurrentFunctionPointer[1] = {};
};
