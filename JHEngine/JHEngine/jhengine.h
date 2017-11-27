#ifndef JHENGINE_H
#define JHENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_jhengine.h"
#include "process_list.h"

class JHEngine : public QMainWindow
{
	Q_OBJECT

public:
	JHEngine(QWidget *parent = 0);
	~JHEngine();

public slots:
	void OpenProcessList();

private:
	Ui::JHEngineClass ui;
	JHEngineProcessList proc_list_;
};

#endif // JHENGINE_H
