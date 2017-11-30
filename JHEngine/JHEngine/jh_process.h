#ifndef JHENGINE_PROCESS_H
#define JHENGINE_PROCESS_H

#include <Windows.h>

static unsigned long g_pid = 0;
static HANDLE g_proc_handle = nullptr;

namespace jhengine
{
	namespace process
	{
		void Detach();
		bool Attach(unsigned long pid)
		{
			if (g_pid)
				Detach();

			g_proc_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			if (!g_proc_handle)
				return false;

			g_pid = pid;
			return true;
		}

		void Detach()
		{
			if (g_proc_handle)
			{
				CloseHandle(g_proc_handle);
				g_proc_handle = nullptr;
			}
			
			g_pid = 0;
		}

		
	}
}



#endif // JHENGINE_PROCESS_H