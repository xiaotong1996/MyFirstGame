#pragma once

#include <QMainWindow>
#include "ui_QtGuiBattlefield.h"
#include "mycanvas.h"
/*QtGuiBattlefield main game window provide game UI except map, map is created in MyCanvas.
*/
class QtGuiBattlefield : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiBattlefield(QWidget *parent = Q_NULLPTR);
	~QtGuiBattlefield();
	void updateUnitID(std::string id);
	void updateUnitHP(std::string hp);
	void updateUnitMoveDistance(std::string moveD);
	void updateUnitAttribute(std::string attribute);
	void updateBossID(std::string id);
	void updateBossHP(std::string hp);
	void updateBossMoveDistance(std::string moveD);
	void updateBossAttribute(std::string attribute);
	void updateGameRound(std::string round);
	void setBossID(int id);
	void setNumberWarrior(int n);
	void setNumberArcher(int n);

private:
	Ui::QtGuiBattlefield ui;
	MyCanvas* SFMLView;
	int bossID;
	int numberWarrior;
	int numberArcher;

private slots:
	void BtnStop_Click();
	void BtnStart_Click();
	void BtnCancel_Click();
	void BtnMove_Click();
	void BtnWait_Click();
	void BtnAttack_Click();
	void BtnHeal_Click();
};
