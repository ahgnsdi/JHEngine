#ifndef JHENGINE_PROCESS_LIST_H
#define JHENGINE_PROCESS_LIST_H

#include <QtWidgets/QMainWindow>
#include "ui_process_list.h"

class JHEngineProcessList : public QMainWindow
{
	Q_OBJECT

public:
	JHEngineProcessList(QWidget *parent = 0);
	~JHEngineProcessList();

public slots:
	void CloseProcessListForm();

private:
	void PrintProcessList();


private:
	Ui::ProcessList ui;
};

#endif // JHENGINE_H
