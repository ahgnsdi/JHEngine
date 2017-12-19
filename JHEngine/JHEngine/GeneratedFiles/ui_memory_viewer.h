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
#include <QtWidgets/QWidget>
#include "disassembly_viewer.h"

QT_BEGIN_NAMESPACE

class Ui_MemoryViewer
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    DisassemblyViewer *treeWidget;
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
        treeWidget = new DisassemblyViewer(layoutWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout->addWidget(treeWidget);

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
    } // retranslateUi

};

namespace Ui {
    class MemoryViewer: public Ui_MemoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_VIEWER_H
