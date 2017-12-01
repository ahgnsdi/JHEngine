#include "jhengine.h"
#include <Windows.h>
#include "jh_qtgui.h"
#include <strsafe.h>

JHEngine::JHEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	jhengine::gui::SetMainFormUi(&ui);
}

JHEngine::~JHEngine()
{

}

void 
JHEngine::OpenProcessList()
{
	proc_list_.show();
}
