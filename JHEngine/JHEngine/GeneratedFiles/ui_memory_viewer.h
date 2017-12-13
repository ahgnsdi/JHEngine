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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
    QLabel *label;
    QLabel *label_2;
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
        layoutWidget->setGeometry(QRect(0, 100, 931, 331));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(layoutWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout->addWidget(treeWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 391, 91));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(127, 24, 151, 21));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(284, 24, 71, 21));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(284, 54, 71, 21));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(127, 54, 151, 21));
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 24, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 54, 101, 16));
        MemoryViewer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MemoryViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MemoryViewer->setStatusBar(statusbar);
        menuBar = new QMenuBar(MemoryViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 931, 21));
        MemoryViewer->setMenuBar(menuBar);

        retranslateUi(MemoryViewer);
        QObject::connect(pushButton, SIGNAL(clicked()), MemoryViewer, SLOT(DisassemblyGotoAddress()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MemoryViewer, SLOT(MemoryGotoAddress()));

        QMetaObject::connectSlotsByName(MemoryViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MemoryViewer)
    {
        MemoryViewer->setWindowTitle(QApplication::translate("MemoryViewer", "MemoryViewer", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MemoryViewer", "Opcode", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("MemoryViewer", "Bytes", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MemoryViewer", "Address", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MemoryViewer", "Go To Address", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MemoryViewer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">123</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MemoryViewer", "Go", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MemoryViewer", "Go", Q_NULLPTR));
        label->setText(QApplication::translate("MemoryViewer", "DisassblyViewer", Q_NULLPTR));
        label_2->setText(QApplication::translate("MemoryViewer", "MemoryViewer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemoryViewer: public Ui_MemoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_VIEWER_H
