#include "memory_viewer.h"

#include <strsafe.h>

JHEngineMemoryViewer::JHEngineMemoryViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//jhengine::gui::SetProcessListFormUi(&ui);
}

JHEngineMemoryViewer::~JHEngineMemoryViewer()
{

}

void
JHEngineMemoryViewer::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);
}