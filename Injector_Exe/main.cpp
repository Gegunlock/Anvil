#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>
#include <string>

HANDLE FindProcess(const std::string Process);
BOOL LoadDLL(HANDLE hProcess, const std::string& dllPath);

int main() 
{
	using namespace std;

	string sDllPath = "C:\\Users\\Admin\\source\\repos\\Anvil_Internal\\Debug\\Anvil_DLL.dll";
	HANDLE hProcess = FindProcess("csgo.exe");
	
	if (LoadDLL(hProcess, sDllPath) == NULL) 
	{
		return 1;
	}

	return 0;
}

HANDLE FindProcess(const std::string ProcessName)
{
	HANDLE				hSnapShot;
	HANDLE				hProcess = NULL;
	PROCESSENTRY32		peProcEntry;

	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	peProcEntry.dwSize = sizeof(peProcEntry);

	if (Process32First(hSnapShot, &peProcEntry) == FALSE) 
	{
		CloseHandle(hSnapShot);
		return NULL;
	}

	/*Go Through Each Process And Compare Their Process Name To Param ProcessName*/
	do 
	{
		if (!strcmp(ProcessName.c_str(), peProcEntry.szExeFile))
		{
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, peProcEntry.th32ProcessID);

			if (hProcess != NULL)
				break;
			else
				return NULL;
		}
	} while (Process32Next(hSnapShot, &peProcEntry));

	CloseHandle(hSnapShot);
	return hProcess;
}

BOOL LoadDLL(HANDLE hProcess, const std::string& dllPath)
{
	DWORD DllPathSize = dllPath.length();
	LPVOID lpDllPathInRemoteMemory = VirtualAllocEx(hProcess, NULL, DllPathSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	if (lpDllPathInRemoteMemory == NULL)
		return NULL;

	if (!WriteProcessMemory(hProcess, lpDllPathInRemoteMemory, dllPath.c_str(), DllPathSize, NULL))
		return NULL;

	LPVOID lpLoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

	if (lpLoadLibraryAddress == NULL)
		return NULL;

	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)lpLoadLibraryAddress, lpDllPathInRemoteMemory, NULL, NULL);

	if (hRemoteThread == NULL)
		return NULL;

	return TRUE;
}