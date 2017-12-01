#ifndef JHENGINE_QTGUI_H
#define JHENGINE_QTGUI_H

#include "ui_jhengine.h"
#include "ui_process_list.h"

enum JHEngineFormId
{
	kMainForm
	, kProcessListForm
};

namespace jhengine
{
	namespace gui
	{
		void SetMainFormUi(Ui::JHEngineClass *ui);
		void SetProcessListFormUi(Ui::ProcessList *ui);

		Ui::JHEngineClass *GetMainFormUi();
		Ui::ProcessList *GetProcessListFormUi();
	}
}



#endif // JHENGINE_PROCESS_H