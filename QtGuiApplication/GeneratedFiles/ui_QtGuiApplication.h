/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION_H
#define UI_QTGUIAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplicationClass
{
public:
    QWidget *centralWidget;
    QPushButton *newGameBtn;
    QPushButton *loadGameBtn;
    QPushButton *settingBtn;
    QPushButton *exitBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplicationClass)
    {
        if (QtGuiApplicationClass->objectName().isEmpty())
            QtGuiApplicationClass->setObjectName(QString::fromUtf8("QtGuiApplicationClass"));
        QtGuiApplicationClass->resize(600, 400);
        centralWidget = new QWidget(QtGuiApplicationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        newGameBtn = new QPushButton(centralWidget);
        newGameBtn->setObjectName(QString::fromUtf8("newGameBtn"));
        newGameBtn->setGeometry(QRect(230, 60, 93, 28));
        loadGameBtn = new QPushButton(centralWidget);
        loadGameBtn->setObjectName(QString::fromUtf8("loadGameBtn"));
        loadGameBtn->setGeometry(QRect(230, 130, 93, 28));
        settingBtn = new QPushButton(centralWidget);
        settingBtn->setObjectName(QString::fromUtf8("settingBtn"));
        settingBtn->setGeometry(QRect(230, 190, 93, 28));
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(230, 250, 93, 28));
        QtGuiApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplicationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        QtGuiApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplicationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplicationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplicationClass->setStatusBar(statusBar);

        retranslateUi(QtGuiApplicationClass);
        QObject::connect(newGameBtn, SIGNAL(clicked()), QtGuiApplicationClass, SLOT(BtnS_Click()));

        QMetaObject::connectSlotsByName(QtGuiApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplicationClass)
    {
        QtGuiApplicationClass->setWindowTitle(QApplication::translate("QtGuiApplicationClass", "QtGuiApplication", nullptr));
        newGameBtn->setText(QApplication::translate("QtGuiApplicationClass", "new game", nullptr));
        loadGameBtn->setText(QApplication::translate("QtGuiApplicationClass", "load game", nullptr));
        settingBtn->setText(QApplication::translate("QtGuiApplicationClass", "setting", nullptr));
        exitBtn->setText(QApplication::translate("QtGuiApplicationClass", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplicationClass: public Ui_QtGuiApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION_H
