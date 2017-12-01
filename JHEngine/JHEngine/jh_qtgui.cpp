#include "jh_qtgui.h"

Ui::JHEngineClass *g_main_form = nullptr;
Ui::ProcessList *g_proc_list_form = nullptr;

void
jhengine::gui::SetMainFormUi(Ui::JHEngineClass *ui)
{
	g_main_form = ui;
}

void 
jhengine::gui::SetProcessListFormUi(Ui::ProcessList *ui)
{
	g_proc_list_form = ui;
}

Ui::JHEngineClass *
jhengine::gui::GetMainFormUi()
{
	return g_main_form;
}

Ui::ProcessList *
jhengine::gui::GetProcessListFormUi()
{
	return g_proc_list_form;
}