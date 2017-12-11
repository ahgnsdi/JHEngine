#ifndef JHENGINE_PROCESS_H
#define JHENGINE_PROCESS_H

#include <Windows.h>

#define AddPtr(base, offset)		((void *)((ULONG_PTR) (base) + (ULONG_PTR) (offset)))

namespace jhengine
{
	namespace process
	{
		void Detach();
		bool Attach(unsigned long pid);
		HANDLE GetCurrentProcessHandle();
		void *GetCurrentProcessImageBase();

		bool IsImagePtr(void *ptr);
		bool GetModuleRange(void *ptr, void *&start, void *&end);
		
	}
}



#endif // JHENGINE_PROCESS_H