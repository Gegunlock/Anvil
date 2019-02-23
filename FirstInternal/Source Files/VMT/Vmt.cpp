
#include "Includes.h"

int CVmt::CountFunctions() const
{
	int iVFuncCount = 0;
	while (m_Vmt[iVFuncCount])
	{
		iVFuncCount++;
	}
	return iVFuncCount;
}

int CVmt::FindFunctionIndex(void * pfnVoidFunctionPointer) const
{
	int iNumberOfVFuncs = this->CountFunctions();
	for (int i = 0; i < iNumberOfVFuncs; i++)
	{
		if (m_Vmt[i] == pfnVoidFunctionPointer)
			return i;
	}
	return -1;
}

void * CVmt::FindFunctionPtr(int iIndex) const
{
	return m_Vmt[iIndex];
}

bool CVmt::Unhook(int iIndex) 
{

}

bool CVmt::UnhookAll() 
{
	
}

void CVmt::Hook(void* fpn, int iIndex) 
{

}
