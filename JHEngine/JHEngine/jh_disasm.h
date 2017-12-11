#ifndef JH_CAPSTONE_H
#define JH_CAPSTONE_H

#include "capstone/capstone.h"

#include <Windows.h>

#include <string>

namespace jhengine
{
	namespace disassembler
	{
		void Initialize();
		void Finalize();

		bool Disasm(HANDLE process_handle, uint64_t addr, std::string &adr_str, std::string &bytes_str, std::string &opcode_str, DWORD &res_size);
	}
}

#endif // JH_CAPSTONE_H
