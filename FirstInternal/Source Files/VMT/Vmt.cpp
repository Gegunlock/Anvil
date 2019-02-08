
#include "../Main/Includes.h"

int CVmt::CountFunctions() 
{
	int iVFuncCount = 0;
	while (/*Points To Beginning of VMT*/m_Vmt[iVFuncCount])
	{
		iVFuncCount++;
	}
	return iVFuncCount;
}

int CVmt::FindFunctionIndex(void* pfnVoidFunctionPointer)
{
	int iNumberOfVFuncs = this->CountFunctions();
	for (int i = 0; i < iNumberOfVFuncs; i++)
	{
		if (m_Vmt[i] == pfnVoidFunctionPointer)
			return i;
	}
	return -1;
}

void* CVmt::FindFunctionPtr(int iIndex) 
{
	return m_Vmt[iIndex];
}