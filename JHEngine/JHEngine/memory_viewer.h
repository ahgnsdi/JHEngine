#ifndef JHENGINE_MEMORY_VIEWER_H
#define JHENGINE_MEMORY_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_memory_viewer.h"

#include <Windows.h>


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

private:
	void UpdateDisassembleView(void *ptr, bool scroll_top_chk);
	bool IsReadableMemory(void *ptr);
	

private:
	Ui::MemoryViewer ui;
};

#endif // JHENGINE_H
