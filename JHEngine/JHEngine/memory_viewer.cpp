#include "memory_viewer.h"

#include <strsafe.h>

#include "jh_disasm.h"
#include "jh_data_storage.h"
#include "jh_process.h"

#include <sstream>

JHEngineMemoryViewer::JHEngineMemoryViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//jhengine::gui::SetProcessListFormUi(&ui);
}

JHEngineMemoryViewer::~JHEngineMemoryViewer()
{

}

bool JHEngineMemoryViewer::IsReadableMemory(void *ptr)
{
	MEMORY_BASIC_INFORMATION mbi;

	if (VirtualQueryEx(jhengine::process::GetCurrentProcessHandle(), ptr, &mbi, sizeof(mbi)) != sizeof(mbi))
	{
		return false;
	}

	if (mbi.State & MEM_COMMIT &&
		(mbi.Protect & PAGE_EXECUTE_READ) || (mbi.Protect & PAGE_EXECUTE_READWRITE)
		|| (mbi.Protect & PAGE_READONLY) || (mbi.Protect & PAGE_READWRITE)
		)
	{
		return true;
	}
	return false;
}

void JHEngineMemoryViewer::DisassemblyGotoAddress()
{
	ULONG address = 0;
	std::istringstream(ui.textEdit->toPlainText().toStdString().c_str()) >> std::hex >> address;

}

void JHEngineMemoryViewer::MemoryGotoAddress()
{
	MessageBoxA(0, "3", "4", 64);
}

void JHEngineMemoryViewer::UpdateDisassembleView(void *ptr, bool scroll_top_chk)
{
	ui.treeWidget->clear();

	if (scroll_top_chk)
	{
		ui.treeWidget->scrollToTop();
	}

	if (!IsReadableMemory(ptr))
	{
		ui.treeWidget->scrollToTop();
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, "-");
		item->setText(1, "-");
		item->setText(2, "Non Readable Memory");
		ui.treeWidget->addTopLevelItem(item);
		
		return;
	}
	

	DWORD res_size = 0;
	void *end = AddPtr(ptr, 0x1000);

	while (ptr <= end)
	{
		std::string addr_str, bytes_str, opcode_str;
		jhengine::disassembler::Disasm(jhengine::process::GetCurrentProcessHandle(), (uint64_t)ptr, addr_str, bytes_str, opcode_str, res_size);
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, addr_str.c_str());
		item->setText(1, bytes_str.c_str());
		item->setText(2, opcode_str.c_str());

		ui.treeWidget->addTopLevelItem(item);

		ptr = AddPtr(ptr, res_size);
	}
}

void
JHEngineMemoryViewer::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);
	
	UpdateDisassembleView(jhengine::storage::GetMemoryViewerCurrentAddress(), false);
}

void
JHEngineMemoryViewer::closeEvent(QCloseEvent *event)
{
}
