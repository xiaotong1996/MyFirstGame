#pragma once

#include <QMainWindow>
#include "ui_QtGuiArmyConfig.h"

/*QtGuiArmyConfig After player chose a boss to challenge, show this GUI for player to compose his army
*/
class QtGuiArmyConfig : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiArmyConfig(QWidget *parent = Q_NULLPTR);
	~QtGuiArmyConfig();
	void setBossID(int id);

private:
	Ui::QtGuiArmyConfig ui;
	int bossID;

private slots:
	void BtnB_Click();
	void BtnOK_Click();
};
