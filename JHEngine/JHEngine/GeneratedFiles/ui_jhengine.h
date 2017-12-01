/********************************************************************************
** Form generated from reading UI file 'jhengine.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JHENGINE_H
#define UI_JHENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JHEngineClass
{
public:
    QWidget *centralWidget;
    QPushButton *ProcOpenBtn;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JHEngineClass)
    {
        if (JHEngineClass->objectName().isEmpty())
            JHEngineClass->setObjectName(QStringLiteral("JHEngineClass"));
        JHEngineClass->setEnabled(true);
        JHEngineClass->resize(600, 574);
        centralWidget = new QWidget(JHEngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ProcOpenBtn = new QPushButton(centralWidget);
        ProcOpenBtn->setObjectName(QStringLiteral("ProcOpenBtn"));
        ProcOpenBtn->setEnabled(true);
        ProcOpenBtn->setGeometry(QRect(10, 20, 91, 51));
        ProcOpenBtn->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 0, 201, 16));
        JHEngineClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(JHEngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JHEngineClass->setStatusBar(statusBar);

        retranslateUi(JHEngineClass);
        QObject::connect(ProcOpenBtn, SIGNAL(clicked()), JHEngineClass, SLOT(OpenProcessList()));

        QMetaObject::connectSlotsByName(JHEngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *JHEngineClass)
    {
        JHEngineClass->setWindowTitle(QApplication::translate("JHEngineClass", "JHEngine", Q_NULLPTR));
        ProcOpenBtn->setText(QApplication::translate("JHEngineClass", "Process Open", Q_NULLPTR));
        label->setText(QApplication::translate("JHEngineClass", "No Process Selected", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JHEngineClass: public Ui_JHEngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JHENGINE_H
