#ifndef JH_DISASSEMBLY_VIEWER_H
#define JH_DISASSEMBLY_VIEWER_H

#include <qtreewidget.h>
#include <qevent.h>
#include <qpainter.h>
#include <qheaderview.h>

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

	int getWeight()
	{
		return QFontMetrics(this->font()).width(QChar(' '));
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter painter(viewport());
		painter.setPen(QPen(Qt::blue));
		painter.fillRect(event->rect(), Qt::black);

		int h = this->header()->height();
		int w = this->font().weight();

		painter.drawText(QRect(100 + 4, 1, h, w), "123");

		//QTreeWidget::paintEvent(event);
	}

};


#endif//