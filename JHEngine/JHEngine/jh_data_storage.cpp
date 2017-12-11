#include "jh_data_storage.h"

#include <vector>

void *g_mem_vwr_cur_addr = nullptr;

void jhengine::storage::SetMemoryViewerCurrentAddress(void *address)
{
	g_mem_vwr_cur_addr = address;
}


void *jhengine::storage::GetMemoryViewerCurrentAddress()
{
	return g_mem_vwr_cur_addr;
}