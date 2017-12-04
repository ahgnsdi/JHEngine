#ifndef JHENGINE_PROCESS_LIST_H
#define JHENGINE_PROCESS_LIST_H

#include <QtWidgets/QMainWindow>
#include "ui_process_list.h"

#include <Windows.h>

#include "qlayout.h"


class JHEngineProcessList : public QMainWindow
{
	Q_OBJECT

public:
	JHEngineProcessList(QWidget *parent = 0);
	~JHEngineProcessList();

public slots:
	void CloseProcessListForm();
	
	void SelectProcess();
	void SelectProcess(QListWidgetItem *item);

	void showEvent(QShowEvent *event);

private:
	void PrintProcessList();


private:
	Ui::ProcessList ui;
};

#endif // JHENGINE_H
