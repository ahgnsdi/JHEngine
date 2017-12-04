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

private:
	Ui::MemoryViewer ui;
};

#endif // JHENGINE_H
