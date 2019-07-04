/********************************************************************************
** Form generated from reading UI file 'QtGuiBoss.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIBOSS_H
#define UI_QTGUIBOSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiBoss
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *bossSelect1;
    QPushButton *bossBack;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiBoss)
    {
        if (QtGuiBoss->objectName().isEmpty())
            QtGuiBoss->setObjectName(QString::fromUtf8("QtGuiBoss"));
        QtGuiBoss->resize(1280, 760);
        centralWidget = new QWidget(QtGuiBoss);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(500, 130, 291, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(26);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 270, 121, 151));
        label_2->setPixmap(QPixmap(QString::fromUtf8("asset/boss1head.png")));
        bossSelect1 = new QPushButton(centralWidget);
        bossSelect1->setObjectName(QString::fromUtf8("bossSelect1"));
        bossSelect1->setGeometry(QRect(300, 440, 93, 28));
        bossBack = new QPushButton(centralWidget);
        bossBack->setObjectName(QString::fromUtf8("bossBack"));
        bossBack->setGeometry(QRect(610, 540, 93, 28));
        QtGuiBoss->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiBoss);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        QtGuiBoss->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiBoss);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiBoss->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiBoss);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiBoss->setStatusBar(statusBar);

        retranslateUi(QtGuiBoss);
        QObject::connect(bossSelect1, SIGNAL(clicked()), QtGuiBoss, SLOT(Btn1_Click()));
        QObject::connect(bossBack, SIGNAL(clicked()), QtGuiBoss, SLOT(BtnB_Click()));

        QMetaObject::connectSlotsByName(QtGuiBoss);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiBoss)
    {
        QtGuiBoss->setWindowTitle(QApplication::translate("QtGuiBoss", "QtGuiBoss", nullptr));
        label->setText(QApplication::translate("QtGuiBoss", "Select a BOSS", nullptr));
        label_2->setText(QString());
        bossSelect1->setText(QApplication::translate("QtGuiBoss", "Select", nullptr));
        bossBack->setText(QApplication::translate("QtGuiBoss", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiBoss: public Ui_QtGuiBoss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIBOSS_H
