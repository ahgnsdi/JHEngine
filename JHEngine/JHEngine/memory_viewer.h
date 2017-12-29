#ifndef JHENGINE_MEMORY_VIEWER_H
#define JHENGINE_MEMORY_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_memory_viewer.h"

#include <Windows.h>
#include <string>

class JHEngineMemoryViewer : public QMainWindow
{
	Q_OBJECT

public:
	JHEngineMemoryViewer(QWidget *parent = 0);
	~JHEngineMemoryViewer();

public slots:
	void showEvent(QShowEvent *event);
	void closeEvent(QCloseEvent *event);

	void DisassemblyGotoAddress();
	void MemoryGotoAddress();

	void wheelEvent(QWheelEvent *event);

private:
	void UpdateDisassembleView(void *ptr, bool scroll_top_chk, ulong size);
	bool IsReadableMemory(void *ptr);

	void DisassemblyViewUp(bool page);
	void DisassemblyViewDown(bool page);

	std::string GetDefaultTextColor(std::string content);

	void ScrollEventThreadProc();
	

private:
	Ui::MemoryViewer ui;
	int mouse_scroll_delta_ = 4;
	int clear_view_cnt_ = 0;
};

#endif // JHENGINE_H
