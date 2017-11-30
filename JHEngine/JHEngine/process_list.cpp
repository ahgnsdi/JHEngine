#include "process_list.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <strsafe.h>

#include "jh_process.h"

JHEngineProcessList::JHEngineProcessList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

JHEngineProcessList::~JHEngineProcessList()
{

}

void
JHEngineProcessList::CloseProcessListForm()
{
	this->close();
}

void JHEngineProcessList::showEvent(QShowEvent *event)
{
	PrintProcessList();
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

void
JHEngineProcessList::SelectProcess()
{
	ulong pid = ui.listWidget->currentItem()->text().section("(", 0, 0).toULong();

	if (!jhengine::process::Attach(pid))
	{
		wchar_t str[MAX_PATH] = { 0, };
		StringCbPrintfW(str, sizeof(str), L"OpenProcess Failed ErrorCode: %d", GetLastError());
		MessageBoxW(0, str, L"Error", 0);
	}

	this->close();
}

void
JHEngineProcessList::SelectProcess(QListWidgetItem *item)
{
	ulong pid = item->text().section("(", 0, 0).toULong();

	if (!jhengine::process::Attach(pid))
	{
		wchar_t str[MAX_PATH] = { 0, };
		StringCbPrintfW(str, sizeof(str), L"OpenProcess Failed ErrorCode: %d", GetLastError());
		MessageBoxW(0, str, L"Error", 0);
	}

	this->close();
}