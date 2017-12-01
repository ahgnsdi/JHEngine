#include "process_list.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <strsafe.h>

#include "jh_process.h"
#include "jh_qtgui.h"

JHEngineProcessList::JHEngineProcessList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	jhengine::gui::SetProcessListFormUi(&ui);
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
	QString proc_str = ui.listWidget->currentItem()->text();
	ulong pid = proc_str.section("(", 0, 0).toULong();

	if (!jhengine::process::Attach(pid))
	{
		wchar_t str[MAX_PATH] = { 0, };
		StringCbPrintfW(str, sizeof(str), L"OpenProcess Failed ErrorCode: %d", GetLastError());
		MessageBoxW(0, str, L"Error", 0);
		jhengine::gui::GetMainFormUi()->label->setText("Error");
	}
	else
	{
		jhengine::gui::GetMainFormUi()->label->setText(proc_str);
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
		jhengine::gui::GetMainFormUi()->label->setText("Error");
	}
	else
	{
		jhengine::gui::GetMainFormUi()->label->setText(item->text());
	}

	this->close();
}