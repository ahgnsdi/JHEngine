#include "jhengine.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qtextstream.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile f("style.qss");
	if (f.exists())
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	JHEngine w;
	w.show();
	return a.exec();
}
