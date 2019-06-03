#pragma once

#include <QMainWindow>
#include "ui_QtGuiArmyConfig.h"

class QtGuiArmyConfig : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiArmyConfig(QWidget *parent = Q_NULLPTR);
	~QtGuiArmyConfig();

private:
	Ui::QtGuiArmyConfig ui;

private slots:
	void BtnB_Click();
	void BtnOK_Click();
};
