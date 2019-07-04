/********************************************************************************
** Form generated from reading UI file 'QtGuiBattlefield.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIBATTLEFIELD_H
#define UI_QTGUIBATTLEFIELD_H

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

class Ui_QtGuiBattlefield
{
public:
    QWidget *centralWidget;
    QPushButton *buttonCancel;
    QPushButton *buttonStop;
    QLabel *unitID;
    QLabel *unitHP;
    QLabel *unitMoveD;
    QLabel *bossID;
    QLabel *bossHP;
    QLabel *unitAttribute;
    QLabel *bossMoveD;
    QLabel *bossAttribute;
    QPushButton *buttonStart;
    QLabel *tips;
    QLabel *gameRound;
    QPushButton *buttonMove;
    QPushButton *buttonWait;
    QPushButton *buttonAttack;
    QPushButton *buttonHeal;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiBattlefield)
    {
        if (QtGuiBattlefield->objectName().isEmpty())
            QtGuiBattlefield->setObjectName(QString::fromUtf8("QtGuiBattlefield"));
        QtGuiBattlefield->resize(1280, 792);
        centralWidget = new QWidget(QtGuiBattlefield);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonCancel = new QPushButton(centralWidget);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(1070, 660, 93, 28));
        buttonStop = new QPushButton(centralWidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setGeometry(QRect(1070, 690, 93, 28));
        unitID = new QLabel(centralWidget);
        unitID->setObjectName(QString::fromUtf8("unitID"));
        unitID->setGeometry(QRect(40, 665, 100, 16));
        unitHP = new QLabel(centralWidget);
        unitHP->setObjectName(QString::fromUtf8("unitHP"));
        unitHP->setGeometry(QRect(40, 695, 100, 16));
        unitMoveD = new QLabel(centralWidget);
        unitMoveD->setObjectName(QString::fromUtf8("unitMoveD"));
        unitMoveD->setGeometry(QRect(160, 665, 150, 16));
        bossID = new QLabel(centralWidget);
        bossID->setObjectName(QString::fromUtf8("bossID"));
        bossID->setGeometry(QRect(350, 665, 100, 16));
        bossHP = new QLabel(centralWidget);
        bossHP->setObjectName(QString::fromUtf8("bossHP"));
        bossHP->setGeometry(QRect(350, 695, 100, 16));
        unitAttribute = new QLabel(centralWidget);
        unitAttribute->setObjectName(QString::fromUtf8("unitAttribute"));
        unitAttribute->setGeometry(QRect(160, 695, 150, 16));
        bossMoveD = new QLabel(centralWidget);
        bossMoveD->setObjectName(QString::fromUtf8("bossMoveD"));
        bossMoveD->setGeometry(QRect(470, 665, 150, 16));
        bossAttribute = new QLabel(centralWidget);
        bossAttribute->setObjectName(QString::fromUtf8("bossAttribute"));
        bossAttribute->setGeometry(QRect(470, 695, 190, 16));
        buttonStart = new QPushButton(centralWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(1170, 660, 93, 58));
        tips = new QLabel(centralWidget);
        tips->setObjectName(QString::fromUtf8("tips"));
        tips->setGeometry(QRect(190, 630, 501, 31));
        QFont font;
        font.setItalic(true);
        tips->setFont(font);
        tips->setLineWidth(1);
        tips->setTextFormat(Qt::AutoText);
        gameRound = new QLabel(centralWidget);
        gameRound->setObjectName(QString::fromUtf8("gameRound"));
        gameRound->setGeometry(QRect(660, 685, 100, 15));
        buttonMove = new QPushButton(centralWidget);
        buttonMove->setObjectName(QString::fromUtf8("buttonMove"));
        buttonMove->setGeometry(QRect(800, 660, 93, 28));
        buttonWait = new QPushButton(centralWidget);
        buttonWait->setObjectName(QString::fromUtf8("buttonWait"));
        buttonWait->setGeometry(QRect(900, 660, 93, 28));
        buttonAttack = new QPushButton(centralWidget);
        buttonAttack->setObjectName(QString::fromUtf8("buttonAttack"));
        buttonAttack->setGeometry(QRect(800, 690, 93, 28));
        buttonHeal = new QPushButton(centralWidget);
        buttonHeal->setObjectName(QString::fromUtf8("buttonHeal"));
        buttonHeal->setGeometry(QRect(900, 690, 93, 28));
        QtGuiBattlefield->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiBattlefield);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        QtGuiBattlefield->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiBattlefield);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiBattlefield->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiBattlefield);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiBattlefield->setStatusBar(statusBar);

        retranslateUi(QtGuiBattlefield);
        QObject::connect(buttonStart, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnStart_Click()));
        QObject::connect(buttonStop, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnStop_Click()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnCancel_Click()));
        QObject::connect(buttonMove, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnMove_Click()));
        QObject::connect(buttonWait, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnWait_Click()));
        QObject::connect(buttonAttack, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnAttack_Click()));
        QObject::connect(buttonHeal, SIGNAL(clicked()), QtGuiBattlefield, SLOT(BtnHeal_Click()));

        QMetaObject::connectSlotsByName(QtGuiBattlefield);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiBattlefield)
    {
        QtGuiBattlefield->setWindowTitle(QApplication::translate("QtGuiBattlefield", "QtGuiBattlefield", nullptr));
        buttonCancel->setText(QApplication::translate("QtGuiBattlefield", "cancel", nullptr));
        buttonStop->setText(QApplication::translate("QtGuiBattlefield", "quit", nullptr));
        unitID->setText(QApplication::translate("QtGuiBattlefield", "ID:", nullptr));
        unitHP->setText(QApplication::translate("QtGuiBattlefield", "HP:", nullptr));
        unitMoveD->setText(QApplication::translate("QtGuiBattlefield", "MoveDistance:", nullptr));
        bossID->setText(QApplication::translate("QtGuiBattlefield", "BossID:", nullptr));
        bossHP->setText(QApplication::translate("QtGuiBattlefield", "BossHP:", nullptr));
        unitAttribute->setText(QApplication::translate("QtGuiBattlefield", "Attribute:", nullptr));
        bossMoveD->setText(QApplication::translate("QtGuiBattlefield", "MoveDistance:", nullptr));
        bossAttribute->setText(QApplication::translate("QtGuiBattlefield", "MoveDistance:", nullptr));
        buttonStart->setText(QApplication::translate("QtGuiBattlefield", "start", nullptr));
        tips->setText(QApplication::translate("QtGuiBattlefield", "Tips\357\274\232Before start,you can modify your army position.", nullptr));
        gameRound->setText(QApplication::translate("QtGuiBattlefield", "Round:", nullptr));
        buttonMove->setText(QApplication::translate("QtGuiBattlefield", "move", nullptr));
        buttonWait->setText(QApplication::translate("QtGuiBattlefield", "wait", nullptr));
        buttonAttack->setText(QApplication::translate("QtGuiBattlefield", "attack", nullptr));
        buttonHeal->setText(QApplication::translate("QtGuiBattlefield", "heal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiBattlefield: public Ui_QtGuiBattlefield {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIBATTLEFIELD_H
