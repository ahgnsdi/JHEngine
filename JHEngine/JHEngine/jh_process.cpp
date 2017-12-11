#include "jh_process.h"

#include <Psapi.h>
#pragma comment(lib, "psapi.lib")

unsigned long g_pid = 0;
HANDLE g_proc_handle = nullptr;

bool jhengine::process::Attach(unsigned long pid)
{
	if (g_pid)
		Detach();

	g_proc_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!g_proc_handle)
		return false;

	g_pid = pid;
	return true;
}

void jhengine::process::Detach()
{
	if (g_proc_handle)
	{
		CloseHandle(g_proc_handle);
		g_proc_handle = nullptr;
	}

	g_pid = 0;
}

HANDLE jhengine::process::GetCurrentProcessHandle()
{
	return g_proc_handle;
}

void *jhengine::process::GetCurrentProcessImageBase()
{
	if (!g_proc_handle)
	{
		return nullptr;
	}

	HMODULE mod[1024];
	DWORD needed = 0;
	if (EnumProcessModules(g_proc_handle, mod, sizeof(mod), &needed))
	{
		return (void*)mod[0];
	}
	return nullptr;
}

bool jhengine::process::IsImagePtr(void *ptr)
{
	if (!g_proc_handle)
	{
		return false;
	}

	MEMORY_BASIC_INFORMATION mbi;
	if (VirtualQueryEx(g_proc_handle, ptr, &mbi, sizeof(mbi)) != sizeof(mbi))
	{
		return false;
	}

	if (mbi.Type == MEM_IMAGE)
	{
		return true;
	}

	return false;
}

bool jhengine::process::GetModuleRange(void *ptr, void *&start, void *&end)
{
	MODULEINFO info;
	if (GetModuleInformation(g_proc_handle, (HMODULE)ptr, &info, sizeof(info)))
	{
		start = info.lpBaseOfDll;
		end = AddPtr(start, info.SizeOfImage);
		return true;
	}
	return false;
}