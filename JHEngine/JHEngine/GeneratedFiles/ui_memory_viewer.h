/********************************************************************************
** Form generated from reading UI file 'memory_viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORY_VIEWER_H
#define UI_MEMORY_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryViewer
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTextEdit *textEdit;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MemoryViewer)
    {
        if (MemoryViewer->objectName().isEmpty())
            MemoryViewer->setObjectName(QStringLiteral("MemoryViewer"));
        MemoryViewer->resize(931, 783);
        MemoryViewer->setContextMenuPolicy(Qt::ActionsContextMenu);
        centralwidget = new QWidget(MemoryViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 931, 331));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(layoutWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout->addWidget(treeWidget);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(60, 390, 241, 21));
        MemoryViewer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MemoryViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MemoryViewer->setStatusBar(statusbar);
        menuBar = new QMenuBar(MemoryViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 931, 21));
        MemoryViewer->setMenuBar(menuBar);

        retranslateUi(MemoryViewer);

        QMetaObject::connectSlotsByName(MemoryViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MemoryViewer)
    {
        MemoryViewer->setWindowTitle(QApplication::translate("MemoryViewer", "MemoryViewer", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MemoryViewer", "Opcode", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("MemoryViewer", "Bytes", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MemoryViewer", "Address", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MemoryViewer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">123</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemoryViewer: public Ui_MemoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_VIEWER_H
