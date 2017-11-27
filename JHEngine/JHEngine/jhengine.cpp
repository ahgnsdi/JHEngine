#include "jhengine.h"
#include <Windows.h>

JHEngine::JHEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

JHEngine::~JHEngine()
{

}

void 
JHEngine::OpenProcessList()
{
	proc_list_.show();
}
