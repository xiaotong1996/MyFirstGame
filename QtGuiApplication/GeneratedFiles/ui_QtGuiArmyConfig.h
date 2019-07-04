/********************************************************************************
** Form generated from reading UI file 'QtGuiArmyConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIARMYCONFIG_H
#define UI_QTGUIARMYCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiArmyConfig
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *warriosNumber;
    QSpinBox *archersNumber;
    QSpinBox *doctorsNumber;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *limit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiArmyConfig)
    {
        if (QtGuiArmyConfig->objectName().isEmpty())
            QtGuiArmyConfig->setObjectName(QString::fromUtf8("QtGuiArmyConfig"));
        QtGuiArmyConfig->resize(1280, 760);
        centralWidget = new QWidget(QtGuiArmyConfig);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(520, 20, 311, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(24);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(200, 470, 911, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(158);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        warriosNumber = new QSpinBox(horizontalLayoutWidget);
        warriosNumber->setObjectName(QString::fromUtf8("warriosNumber"));

        horizontalLayout->addWidget(warriosNumber);

        archersNumber = new QSpinBox(horizontalLayoutWidget);
        archersNumber->setObjectName(QString::fromUtf8("archersNumber"));

        horizontalLayout->addWidget(archersNumber);

        doctorsNumber = new QSpinBox(horizontalLayoutWidget);
        doctorsNumber->setObjectName(QString::fromUtf8("doctorsNumber"));

        horizontalLayout->addWidget(doctorsNumber);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(200, 210, 911, 258));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setPixmap(QPixmap(QString::fromUtf8("asset/warriorhead.png")));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("asset/archerhead.png")));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(200, 100, 911, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(158);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        limit = new QLabel(horizontalLayoutWidget_3);
        limit->setObjectName(QString::fromUtf8("limit"));
        limit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(limit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 600, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 600, 93, 28));
        QtGuiArmyConfig->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiArmyConfig);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        QtGuiArmyConfig->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiArmyConfig);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiArmyConfig->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiArmyConfig);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiArmyConfig->setStatusBar(statusBar);

        retranslateUi(QtGuiArmyConfig);
        QObject::connect(pushButton, SIGNAL(clicked()), QtGuiArmyConfig, SLOT(BtnOK_Click()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtGuiArmyConfig, SLOT(BtnB_Click()));

        QMetaObject::connectSlotsByName(QtGuiArmyConfig);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiArmyConfig)
    {
        QtGuiArmyConfig->setWindowTitle(QApplication::translate("QtGuiArmyConfig", "QtGuiArmyConfig", nullptr));
        label->setText(QApplication::translate("QtGuiArmyConfig", "Build your army", nullptr));
        label_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("QtGuiArmyConfig", "doctors", nullptr));
        label_6->setText(QApplication::translate("QtGuiArmyConfig", "The population limit:", nullptr));
        limit->setText(QApplication::translate("QtGuiArmyConfig", "0", nullptr));
        pushButton->setText(QApplication::translate("QtGuiArmyConfig", "OK", nullptr));
        pushButton_2->setText(QApplication::translate("QtGuiArmyConfig", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiArmyConfig: public Ui_QtGuiArmyConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIARMYCONFIG_H
