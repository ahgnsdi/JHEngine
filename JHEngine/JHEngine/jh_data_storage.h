#ifndef JH_ENGINE_STORAGE_H
#define JH_ENGINE_STORAGE_H

#include <Windows.h>
#include <qtreewidget.h>

namespace jhengine
{
	namespace storage
	{
		void SetMemoryViewerCurrentAddress(void *address);
		void *GetMemoryViewerCurrentAddress();

		void SetMemoryDumpViewerCurrentAddress(void *address);
		void *GetMemoryDumpViewerCurrentAddress();
	}
}


#endif //JH_ENGINE_STORAGE_H
