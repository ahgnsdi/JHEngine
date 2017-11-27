#include "process_list.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <strsafe.h>

JHEngineProcessList::JHEngineProcessList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	PrintProcessList();
}

JHEngineProcessList::~JHEngineProcessList()
{

}

void
JHEngineProcessList::CloseProcessListForm()
{
	this->close();
}

void
JHEngineProcessList::PrintProcessList()
{
	HANDLE snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (snapshot_handle == INVALID_HANDLE_VALUE)
	{
		return;
	}

	std::shared_ptr<void> handle_closer(snapshot_handle, ::CloseHandle);

	PROCESSENTRY32W pe = { 0, };
	pe.dwSize = sizeof(pe);

	BOOL ret = Process32FirstW(snapshot_handle, &pe);
	for ( ; ret ; ret = Process32NextW(snapshot_handle, &pe))
	{
		QString str;
		wchar_t buf[MAX_PATH] = { 0, };
		StringCbPrintfW(buf, sizeof(buf), L"%d(0x%x) - %ls"
			, pe.th32ProcessID
			, pe.th32ProcessID
			, pe.szExeFile);
		str = QString::fromWCharArray(buf);
		ui.listWidget->addItem(str);
	}
}