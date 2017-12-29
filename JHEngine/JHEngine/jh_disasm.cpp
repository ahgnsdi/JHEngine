#include "jh_disasm.h"

#include <strsafe.h>

#ifdef _WIN64
#pragma comment(lib, "capstone_x64.lib")
#else
#pragma comment(lib, "capstone_x86.lib")
#endif

csh g_capstone_handle = NULL;
cs_insn *g_inst = nullptr;

void jhengine::disassembler::Initialize()
{
	cs_open(CS_ARCH_X86, CS_MODE_32, &g_capstone_handle);
	g_inst = cs_malloc(g_capstone_handle);
}

void jhengine::disassembler::Finalize()
{
	if (g_inst)
		cs_free(g_inst, 1);
}

bool jhengine::disassembler::Disasm(HANDLE process_handle, uint64_t addr, std::string &adr_str, std::string &bytes_str, std::string &opcode_str, DWORD &res_size)
{

	BYTE buffer[16] = { 0, };
	SIZE_T req_size = 0;

	if (!ReadProcessMemory(process_handle, (LPCVOID)addr, buffer, sizeof(buffer), &req_size))
	{
		return false;
	}

	uint64_t local_addr = (uint64_t)&buffer;
	size_t buffer_size = 16;

	bool ret = cs_disasm_iter(g_capstone_handle, (const uint8_t **)&local_addr, &buffer_size, &addr, g_inst);

	if (ret)
	{
		char tmp[MAX_PATH] = { 0 , };

		StringCbPrintfA(tmp, sizeof(tmp), "%08X", g_inst->address);
		adr_str = tmp;

		for (int i = 0; i < g_inst->size; i++)
		{
			if(i == 0)
				StringCbPrintfA(tmp, sizeof(tmp), "%02X ", g_inst->bytes[i]);
			else
			{
				char tmp2[32] = { 0, };
				StringCbPrintfA(tmp2, sizeof(tmp2), "%02X ", g_inst->bytes[i]);
				StringCbCatA(tmp, sizeof(tmp), tmp2);
			}
		}

		bytes_str = tmp; 

		StringCbPrintfA(tmp, sizeof(tmp), "<b>%s</b>\t%s", g_inst->mnemonic, g_inst->op_str);
		opcode_str = tmp;

		res_size = g_inst->size;
	}
	else
	{
		char tmp[32] = { 0, };
		StringCbPrintfA(tmp, sizeof(tmp), "%08X", addr);
		adr_str = tmp;

		bytes_str = "-";
		opcode_str = "-";
		
		res_size = 1;
	}
	return ret;
}