#include "jhengine.h"
#include <Windows.h>
#include "jh_qtgui.h"
#include <strsafe.h>

#include "jh_disasm.h"

JHEngine::JHEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	jhengine::gui::SetMainFormUi(&ui);
	jhengine::disassembler::Initialize();
}

JHEngine::~JHEngine()
{

}

void 
JHEngine::OpenProcessList()
{
	proc_list_.show();
}

void 
JHEngine::OpenMemoryViewer()
{
	memory_viewer_.show();
}