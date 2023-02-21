#pragma once
#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <Psapi.h>





//Get all module related info, this will include the base DLL.
//and the size of the module
MODULEINFO GetModuleInfo(const char* szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}

char* InScan(char* pattern, char* mask, char* begin, unsigned int size)
{

	unsigned int patternLength = strlen(mask);

	for (unsigned int i = 0; i < size - patternLength; i++)

	{

		bool found = true;
		for (unsigned int j = 0; j < patternLength; j++)
		{
			if (mask[j] != '?' && pattern[j] != *(begin + i + j))
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return (begin + i);
		}
	}

	return 0;

}



char* PatternScan(char* pattern, char* mask)
{

	SYSTEM_INFO sysInfo;

	GetSystemInfo(&sysInfo);

	__int64 end = (__int64)sysInfo.lpMaximumApplicationAddress;

	char* currentChunk = 0;
	char* match = nullptr;
	SIZE_T bytesRead;

	while (currentChunk < (char*)end)

	{

		MEMORY_BASIC_INFORMATION mbi;

		HANDLE process = GetCurrentProcess();
		int hr = GetLastError();

		if (!VirtualQueryEx(process, currentChunk, &mbi, sizeof(mbi)))
		{
			return 0;
		}

		char* buffer = 0;


		if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS)
		{
			buffer = new char[mbi.RegionSize];
			DWORD oldprotect;
			if (VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
			{
				ReadProcessMemory(process, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				char* internalAddress = InScan(pattern, mask, buffer, bytesRead);

				if (internalAddress != 0)
				{
					//calculate from internal to external

					__int64 offsetFromBuffer = internalAddress - buffer;
					match = currentChunk + offsetFromBuffer;
					delete[] buffer;
					break;
				}
			}
		}

		currentChunk = currentChunk + mbi.RegionSize;

		if (buffer) delete[] buffer;
		buffer = 0;
	}

	return match;

}

// Declaring variables;
char* Sharpness = NULL;
char* UnlimitedGold = NULL;




void InitPattern()
{
	Sharpness = PatternScan("\x36\x01\x00\x00\x04", "xx?xx");
	//GodMode = PatternScan("\xF3\x0F\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x0F\x28\x00\x00\x00\x48\x83\xC4\x00\x5B\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x40", "xx??????x????xx???xxx?xxxxxxxxxxxxx");
	//GodMode += 5; //

	//UnlimitedGold = PatternScan("\x00\x00\x96\x43\xC7\x5C\xDE\x33", "xxxxxxxx");
	//UnlimitedGold += 4; //

}

