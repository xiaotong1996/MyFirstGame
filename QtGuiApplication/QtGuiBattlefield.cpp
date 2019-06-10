#include "QtGuiBattlefield.h"
#include "../MyLibrary/GameManager.h"
#include <QtGuiBoss.h>

QtGuiBattlefield::QtGuiBattlefield(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.buttonStart->setCheckable(true);
	SFMLView = new MyCanvas(this, QPoint(0, 0), QSize(1280, 640));
	SFMLView->show();
	
}

QtGuiBattlefield::~QtGuiBattlefield()
{
}

void QtGuiBattlefield::updateUnitID(std::string id)
{
	std::string newid = "ID: " + id;
	ui.unitID->setText(QString::fromStdString(newid));
}

void QtGuiBattlefield::updateUnitHP(std::string hp)
{
	std::string newHP = "HP: " + hp;
	ui.unitHP->setText(QString::fromStdString(newHP));
}

void QtGuiBattlefield::updateUnitMoveDistance(std::string moveD)
{
	std::string newMoveD = "MoveDistance: " + moveD;
	ui.unitMoveD->setText(QString::fromStdString(newMoveD));
}

void QtGuiBattlefield::updateUnitAttribute(std::string attribute)
{
	ui.unitAttribute->setText(QString::fromStdString(attribute));
}

void QtGuiBattlefield::updateBossID(std::string id)
{
	std::string newid = "ID: " + id;
	ui.bossID->setText(QString::fromStdString(newid));
}

void QtGuiBattlefield::updateBossHP(std::string hp)
{
	std::string newHP = "HP: " + hp;
	ui.bossHP->setText(QString::fromStdString(newHP));
}

void QtGuiBattlefield::updateBossMoveDistance(std::string moveD)
{
	std::string newMoveD = "MoveDistance: " + moveD;
	ui.bossMoveD->setText(QString::fromStdString(newMoveD));
}

void QtGuiBattlefield::updateBossAttribute(std::string attribute)
{
	ui.bossAttribute->setText(QString::fromStdString(attribute));
}

void QtGuiBattlefield::updateGameRound(std::string round)
{
	std::string newRound = "Round: " + round;
	ui.gameRound->setText(QString::fromStdString(newRound));
}

void QtGuiBattlefield::BtnStop_Click()
{
	//if player give up this round, it will show the parent widget
	this->parentWidget()->parentWidget()->show(); 
	GameManager::instance().getGamer()->getCurrentRound().gameEnd();
	delete this->parentWidget();
	//delete this;
	// TO-DO
	//show round detail
	//record this round
}

void QtGuiBattlefield::BtnStart_Click()
{
	if (!GameManager::instance().getGamer()->getCurrentRound().isEnd()) {
		GameManager::instance().getGamer()->getCurrentRound().gameStart();
		GameManager::instance().getGamer()->getCurrentRound().addTurn();
		ui.buttonStart->setCheckable(false);
	}
}

void QtGuiBattlefield::BtnCancel_Click()
{
	//every round player can only cancel one time
	GameManager::instance().getGamer()->getCurrentRound().cancelLastCommand();
}

void QtGuiBattlefield::BtnMove_Click()
{
	if (SFMLView->isSomeoneSelected()) {
		SFMLView->setIsMove(true);
		SFMLView->setIsAttack(false);
	}
}

void QtGuiBattlefield::BtnWait_Click()
{
	if (!GameManager::instance().getGamer()->getCurrentRound().isEnd()) {
		GameManager::instance().getGamer()->getCurrentRound().addTurn();
	}
}

void QtGuiBattlefield::BtnAttack_Click()
{
	if (SFMLView->isSomeoneSelected()) {
		SFMLView->setIsAttack(true);
		SFMLView->setIsMove(false);
	}
}

void QtGuiBattlefield::BtnHeal_Click()
{
	// TO-DO
}


