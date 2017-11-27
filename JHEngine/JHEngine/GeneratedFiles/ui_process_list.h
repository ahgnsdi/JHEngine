/********************************************************************************
** Form generated from reading UI file 'process_list.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_LIST_H
#define UI_PROCESS_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessList
{
public:
    QPushButton *SelectProcessBtn;
    QPushButton *SelectCloseBtn;
    QListWidget *listWidget;

    void setupUi(QWidget *ProcessList)
    {
        if (ProcessList->objectName().isEmpty())
            ProcessList->setObjectName(QStringLiteral("ProcessList"));
        ProcessList->resize(230, 454);
        SelectProcessBtn = new QPushButton(ProcessList);
        SelectProcessBtn->setObjectName(QStringLiteral("SelectProcessBtn"));
        SelectProcessBtn->setGeometry(QRect(10, 380, 211, 23));
        SelectCloseBtn = new QPushButton(ProcessList);
        SelectCloseBtn->setObjectName(QStringLiteral("SelectCloseBtn"));
        SelectCloseBtn->setGeometry(QRect(10, 420, 211, 23));
        listWidget = new QListWidget(ProcessList);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(9, 9, 211, 361));

        retranslateUi(ProcessList);
        QObject::connect(SelectProcessBtn, SIGNAL(clicked()), ProcessList, SLOT(SelectProcess()));
        QObject::connect(SelectCloseBtn, SIGNAL(clicked()), ProcessList, SLOT(CloseProcessListForm()));

        QMetaObject::connectSlotsByName(ProcessList);
    } // setupUi

    void retranslateUi(QWidget *ProcessList)
    {
        ProcessList->setWindowTitle(QApplication::translate("ProcessList", "Form", Q_NULLPTR));
        SelectProcessBtn->setText(QApplication::translate("ProcessList", "Select", Q_NULLPTR));
        SelectCloseBtn->setText(QApplication::translate("ProcessList", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcessList: public Ui_ProcessList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_LIST_H
