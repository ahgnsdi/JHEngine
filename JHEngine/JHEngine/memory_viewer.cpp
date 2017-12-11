#include "memory_viewer.h"

#include <strsafe.h>

#include "jh_disasm.h"
#include "jh_data_storage.h"
#include "jh_process.h"

JHEngineMemoryViewer::JHEngineMemoryViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//jhengine::gui::SetProcessListFormUi(&ui);
}

JHEngineMemoryViewer::~JHEngineMemoryViewer()
{

}

void JHEngineMemoryViewer::PrintDisassemble(void *ptr)
{
	if (jhengine::process::IsImagePtr(ptr))
	{
		
	}
}

void
JHEngineMemoryViewer::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);

	if (!first_show_chk_)
	{
		char strbuf[100];
		void *start, *end;
		jhengine::process::GetModuleRange((void *)0x00400000, start, end);
		StringCbPrintfA(strbuf, sizeof(strbuf), "%x %x", start, end);
		MessageBoxA(0, strbuf, "", 64);
		void *cur_addr = jhengine::storage::GetMemoryViewerCurrentAddress();

		jhengine::disassembler::Initialize();

		std::string addr_str, bytes_str, opcode_str;
		DWORD res_size = 0;

		for (int i = 0; i < 10000; i++)
		{
			jhengine::disassembler::Disasm(jhengine::process::GetCurrentProcessHandle(), (uint64_t)cur_addr, addr_str, bytes_str, opcode_str, res_size);
			QTreeWidgetItem *item = new QTreeWidgetItem;
			item->setText(0, addr_str.c_str());
			item->setText(1, bytes_str.c_str());
			item->setText(2, opcode_str.c_str());

			ui.treeWidget->addTopLevelItem(item);

			cur_addr = AddPtr(cur_addr, res_size);
		}

		first_show_chk_ = true;
	}
}

void
JHEngineMemoryViewer::closeEvent(QCloseEvent *event)
{
}
