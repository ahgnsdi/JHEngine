#include "memory_viewer.h"

#include <strsafe.h>

#include "jh_disasm.h"
#include "jh_data_storage.h"
#include "jh_process.h"

#include <sstream>

#include <qpainter.h>
#include <qscrollbar.h>
#include <qstyleditemdelegate.h>
#include <qabstracttextdocumentlayout.h>
#include <thread>

class HtmlDelegate : public QStyledItemDelegate
{
protected:
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
	QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

void HtmlDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItemV4 optionV4 = option;
	initStyleOption(&optionV4, index);

	QStyle *style = optionV4.widget ? optionV4.widget->style() : QApplication::style();

	QTextDocument doc;
	doc.setHtml(optionV4.text);

	/// Painting item without text
	optionV4.text = QString();
	style->drawControl(QStyle::CE_ItemViewItem, &optionV4, painter);

	QAbstractTextDocumentLayout::PaintContext ctx;

	// Highlighting text if item is selected
	//if (optionV4.state & QStyle::State_Selected)
		//ctx.palette.setColor(QPalette::Text, Qt::red);//optionV4.palette.color(QPalette::Active, QPalette::));

	QRect textRect = style->subElementRect(QStyle::SE_ItemViewItemText, &optionV4);
	painter->save();
	painter->translate(textRect.topLeft());
	painter->setClipRect(textRect.translated(-textRect.topLeft()));
	doc.documentLayout()->draw(painter, ctx);
	painter->restore();
}

QSize HtmlDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItemV4 optionV4 = option;
	initStyleOption(&optionV4, index);

	QTextDocument doc;
	doc.setHtml(optionV4.text);
	doc.setTextWidth(optionV4.rect.width());
	return QSize(doc.idealWidth(), doc.size().height());
}

JHEngineMemoryViewer::JHEngineMemoryViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//jhengine::gui::SetProcessListFormUi(&ui);

	ui.treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
	QMenu *menu = new QMenu(ui.treeWidget);
	QAction *dis_goto_action = menu->addAction("Go to Address");
	QAction *action = menu->addAction("Go to Address2");

	connect(dis_goto_action, SIGNAL(triggered()), SLOT(DisassemblyGotoAddress()));
	connect(action, SIGNAL(triggered()), SLOT(DisassemblyGotoAddress()));

	HtmlDelegate *del = new HtmlDelegate();

	ui.treeWidget->addAction(dis_goto_action);
	ui.treeWidget->addAction(action);
	ui.treeWidget->setItemDelegate(del);
}

JHEngineMemoryViewer::~JHEngineMemoryViewer()
{

}

void
JHEngineMemoryViewer::DisassemblyViewUp(bool page)
{
	if(page)
		MessageBoxA(0, "Up", "", 64);
	else
		MessageBoxA(0, "Up2", "", 64);
}

void
JHEngineMemoryViewer::DisassemblyViewDown(bool page)
{
	DWORD res_size = 0;
	void *current_ptr = jhengine::storage::GetMemoryViewerCurrentAddress();

	if(page)
		MessageBoxA(0, "Down", "", 64);
	else
	{
		
		std::string addr_str, bytes_str, opcode_str;
		jhengine::disassembler::Disasm(jhengine::process::GetCurrentProcessHandle(), (uint64_t)current_ptr, addr_str, bytes_str, opcode_str, res_size);
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, GetDefaultTextColor(addr_str).c_str());
		item->setText(1, GetDefaultTextColor(bytes_str).c_str());
		item->setText(2, GetDefaultTextColor(opcode_str).c_str());

		ui.treeWidget->addTopLevelItem(item);
	}

	jhengine::storage::SetMemoryViewerCurrentAddress(AddPtr(current_ptr, res_size));
}

void 
JHEngineMemoryViewer::wheelEvent(QWheelEvent *event)
{
	int degrees = event->delta() / 8;
	int steps = degrees / 15;

	if (steps < 0)
	{
		UpdateDisassembleView(jhengine::storage::GetMemoryViewerCurrentAddress(), false, 0x100);
	}
}

void
JHEngineMemoryViewer::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Down:
	case Qt::Key_PageDown:
		{
			if (ui.treeWidget->verticalScrollBar()->sliderPosition() == ui.treeWidget->verticalScrollBar()->maximum())
			{
				UpdateDisassembleView(jhengine::storage::GetMemoryViewerCurrentAddress(), false, 0x100);
			}
		}
		break;
	}
}

std::string 
JHEngineMemoryViewer::GetDefaultTextColor(std::string content)
{
	return "<span style = \"color:#c7ccc1\">" + content + "</span>";
}

std::string
JHEngineMemoryViewer::SetHighlightingSyntax(std::string content)
{
	return "";
}

bool JHEngineMemoryViewer::IsReadableMemory(void *ptr)
{
	MEMORY_BASIC_INFORMATION mbi;

	if (VirtualQueryEx(jhengine::process::GetCurrentProcessHandle(), ptr, &mbi, sizeof(mbi)) != sizeof(mbi))
	{
		return false;
	}

	if (mbi.State & MEM_COMMIT &&
		(mbi.Protect & PAGE_EXECUTE_READ) || (mbi.Protect & PAGE_EXECUTE_READWRITE)
		|| (mbi.Protect & PAGE_READONLY) || (mbi.Protect & PAGE_READWRITE)
		)
	{
		return true;
	}
	return false;
}

void JHEngineMemoryViewer::DisassemblyGotoAddress()
{
	ULONG address = 0;
	//std::istringstream(ui.textEdit->toPlainText().toStdString().c_str()) >> std::hex >> address;
	MessageBoxW(0, L"", L"", 64);
}

void JHEngineMemoryViewer::MemoryGotoAddress()
{
	MessageBoxA(0, "3", "4", 64);
}

void JHEngineMemoryViewer::UpdateDisassembleView(void *ptr, bool scroll_top_chk, ulong size)
{
	if (scroll_top_chk)
	{
		ui.treeWidget->scrollToTop();
	}

	if (clear_view_cnt_ > 10)
	{
		clear_view_cnt_ = 0;
		ui.treeWidget->clear();
	}

	if (!IsReadableMemory(ptr))
	{
		ui.treeWidget->clear();
		ui.treeWidget->scrollToTop();
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, GetDefaultTextColor("-").c_str());
		item->setText(1, GetDefaultTextColor("-").c_str());
		item->setText(2, GetDefaultTextColor("Non Readable Memory").c_str());
		ui.treeWidget->addTopLevelItem(item);
		
		return;
	}
	

	DWORD res_size = 0;
	void *end = AddPtr(ptr, size);

	while (ptr <= end)
	{
		std::string addr_str, bytes_str, opcode_str;
		jhengine::disassembler::Disasm(jhengine::process::GetCurrentProcessHandle(), (uint64_t)ptr, addr_str, bytes_str, opcode_str, res_size);
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, GetDefaultTextColor(addr_str).c_str());
		item->setText(1, GetDefaultTextColor(bytes_str).c_str());
		item->setText(2, GetDefaultTextColor(opcode_str).c_str());

		ui.treeWidget->addTopLevelItem(item);

		ptr = AddPtr(ptr, res_size);
	}

	jhengine::storage::SetMemoryViewerCurrentAddress(end);
}

void
JHEngineMemoryViewer::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);

	QTreeWidgetItem *item = new QTreeWidgetItem;

	UpdateDisassembleView(jhengine::storage::GetMemoryViewerCurrentAddress(), false, 0x1000);
	UpdateMemoryDumpView(jhengine::storage::GetMemoryViewerCurrentAddress(), false, 0x1000);
}

void
JHEngineMemoryViewer::closeEvent(QCloseEvent *event)
{
	ui.treeWidget->clear();
}

void JHEngineMemoryViewer::UpdateMemoryDumpView(void *ptr, bool scroll_top_chk, ulong size)
{
	if (scroll_top_chk)
	{
		ui.treeWidget->scrollToTop();
	}

	if (clear_view_cnt_ > 10)
	{
		clear_view_cnt_ = 0;
		ui.treeWidget->clear();
	}

	if (!IsReadableMemory(ptr))
	{
		ui.treeWidget->clear();
		ui.treeWidget->scrollToTop();
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, GetDefaultTextColor("-").c_str());
		item->setText(1, GetDefaultTextColor("-").c_str());
		item->setText(2, GetDefaultTextColor("Non Readable Memory").c_str());
		ui.treeWidget->addTopLevelItem(item);

		return;
	}


	DWORD res_size = 0;
	void *end = AddPtr(ptr, size);

	while (ptr <= end)
	{
		char addr_str[10], bytes_str[100], ascii_str[100];
		BYTE buffer[16] = { 0 ,};
		SIZE_T req_size = 0;
		ReadProcessMemory(jhengine::process::GetCurrentProcessHandle(), ptr, buffer, 16, &req_size);

		StringCbPrintfA(addr_str, sizeof(addr_str), "%08X", ptr);
		
		for (int i = 0; i < 16; i++)
		{
			if(buffer[i] > ' ' && buffer[i] <= '~')
				ascii_str[i]=(char)buffer[i];
			else
				ascii_str[i]='.';
		}
		ascii_str[16] = NULL;

		StringCbPrintfA(bytes_str, sizeof(bytes_str), "%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X"
			, buffer[0]
			, buffer[1]
			, buffer[2]
			, buffer[3]
			, buffer[4]
			, buffer[5]
			, buffer[6]
			, buffer[7]
			, buffer[8]
			, buffer[9]
			, buffer[10]
			, buffer[11]
			, buffer[12]
			, buffer[13]
			, buffer[14]
			, buffer[15]);

		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, addr_str);
		item->setText(1, ascii_str);
		item->setText(2, bytes_str);

		ui.treeWidget_2->addTopLevelItem(item);

		ptr = AddPtr(ptr, 16);
	}

	jhengine::storage::SetMemoryDumpViewerCurrentAddress(end);
}
