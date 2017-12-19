#ifndef JH_DISASSEMBLY_VIEWER_H
#define JH_DISASSEMBLY_VIEWER_H

#include <qtreewidget.h>
#include <qevent.h>
#include <qpainter.h>

#include <Windows.h>

class DisassemblyViewer : public QTreeWidget
{
public:
	DisassemblyViewer(QWidget *widget)
		: QTreeWidget(widget)
	{
		setFrameStyle(QTreeWidget::Panel);
	}

	~DisassemblyViewer()
	{
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter painter(viewport());
		painter.setPen(QPen(Qt::blue));
		painter.fillRect(event->rect(), Qt::red);

		painter.drawText(10,10,10,10,10, "123");

		//QTreeWidget::paintEvent(event);
	}

};


#endif//