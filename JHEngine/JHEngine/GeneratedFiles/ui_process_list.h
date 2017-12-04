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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessList
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProcessList)
    {
        if (ProcessList->objectName().isEmpty())
            ProcessList->setObjectName(QStringLiteral("ProcessList"));
        ProcessList->resize(248, 504);
        centralwidget = new QWidget(ProcessList);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        ProcessList->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ProcessList);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProcessList->setStatusBar(statusbar);

        retranslateUi(ProcessList);
        QObject::connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), ProcessList, SLOT(SelectProcess(QListWidgetItem*)));
        QObject::connect(pushButton, SIGNAL(clicked()), ProcessList, SLOT(SelectProcess()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ProcessList, SLOT(CloseProcessListForm()));

        QMetaObject::connectSlotsByName(ProcessList);
    } // setupUi

    void retranslateUi(QMainWindow *ProcessList)
    {
        ProcessList->setWindowTitle(QApplication::translate("ProcessList", "ProcessList", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ProcessList", "Select", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ProcessList", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcessList: public Ui_ProcessList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_LIST_H
