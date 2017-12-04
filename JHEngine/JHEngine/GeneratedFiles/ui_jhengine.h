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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JHEngineClass
{
public:
    QWidget *centralWidget;
    QToolButton *ProcOptnBtn;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QLabel *label;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JHEngineClass)
    {
        if (JHEngineClass->objectName().isEmpty())
            JHEngineClass->setObjectName(QStringLiteral("JHEngineClass"));
        JHEngineClass->setEnabled(true);
        JHEngineClass->resize(600, 745);
        centralWidget = new QWidget(JHEngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ProcOptnBtn = new QToolButton(centralWidget);
        ProcOptnBtn->setObjectName(QStringLiteral("ProcOptnBtn"));
        ProcOptnBtn->setGeometry(QRect(10, 30, 31, 31));
        ProcOptnBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/AhnJaeHun/Desktop/1255.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ProcOptnBtn->setIcon(icon);
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(43, 30, 31, 31));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        toolButton_2->setIcon(icon);
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(76, 30, 31, 31));
        toolButton_3->setFocusPolicy(Qt::NoFocus);
        toolButton_3->setIcon(icon);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 301, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 450, 141, 23));
        pushButton->setFocusPolicy(Qt::NoFocus);
        JHEngineClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(JHEngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JHEngineClass->setStatusBar(statusBar);

        retranslateUi(JHEngineClass);
        QObject::connect(ProcOptnBtn, SIGNAL(clicked()), JHEngineClass, SLOT(OpenProcessList()));
        QObject::connect(pushButton, SIGNAL(clicked()), JHEngineClass, SLOT(OpenMemoryViewer()));

        QMetaObject::connectSlotsByName(JHEngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *JHEngineClass)
    {
        JHEngineClass->setWindowTitle(QApplication::translate("JHEngineClass", "JHEngine", Q_NULLPTR));
        ProcOptnBtn->setText(QApplication::translate("JHEngineClass", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("JHEngineClass", "...", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("JHEngineClass", "...", Q_NULLPTR));
        label->setText(QApplication::translate("JHEngineClass", "No Process Select", Q_NULLPTR));
        pushButton->setText(QApplication::translate("JHEngineClass", "MemoryViewer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JHEngineClass: public Ui_JHEngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JHENGINE_H
