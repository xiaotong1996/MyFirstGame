#include "QtGuiArmyConfig.h"

#include "QtGuiBattlefield.h"
#include "../MyLibrary/GameManager.h"
#include <string>
#include <QMessageBox>



QtGuiArmyConfig::QtGuiArmyConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtGuiArmyConfig::~QtGuiArmyConfig()
{
}

void QtGuiArmyConfig::setBossID(int id)
{
	bossID = id;
	if (bossID == 1) {
		ui.limit->setText(QString::number(GameConfigue::population_limit_boss1()));
	}
}


void QtGuiArmyConfig::BtnOK_Click()
{
	//set solder
	/*int solder_position_x = GameManager::instance().getGameConfigue()->warrior_position_x();
	int solder_position_y = GameManager::instance().getGameConfigue()->warrior_postition_y();
	std::string warrior_id = GameManager::instance().getGameConfigue()->warrior_id();
	int warrior_HP_max = GameManager::instance().getGameConfigue()->warrior_HP_max();
	int warrior_damage = GameManager::instance().getGameConfigue()->warrior_damage();
	int warrior_damage_distance = GameManager::instance().getGameConfigue()->warrior_damage_distance();
	int warrior_move_distance = GameManager::instance().getGameConfigue()->warrior_move_distance();
	std::string archer_id = GameManager::instance().getGameConfigue()->archer_id();
	int archer_HP_max = GameManager::instance().getGameConfigue()->archer_HP_max();
	int archer_damage = GameManager::instance().getGameConfigue()->archer_damage();
	int archer_damage_distance = GameManager::instance().getGameConfigue()->archer_damage_distance();
	int archer_move_distance = GameManager::instance().getGameConfigue()->archer_move_distance();

	int scale= GameManager::instance().getGameConfigue()->default_scale();

	const int warriors_n = ui.warriosNumber->value();
	const int archers_n = ui.archersNumber->value();
	const int doctors_n = ui.doctorsNumber->value();
	for (int i = 0; i < warriors_n; i++) {
		std::string warrior_id_ = warrior_id + std::to_string(i);
		int solder_position_x_ = solder_position_x + scale*2;
		int soler_position_y_ = solder_position_y + i * scale*2;
		std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR,warrior_id_, warrior_HP_max, solder_position_x_, soler_position_y_, warrior_damage, warrior_damage_distance, warrior_move_distance);
		GameManager::instance().getGamer()->getCurrentRound().add2Army(warrior);
	}
	for (int i = 0; i < archers_n; i++) {
		std::string archer_id_ = archer_id + std::to_string(i);
		int solder_position_x_ = solder_position_x;
		int soler_position_y_ = solder_position_y + i * scale*2;
		std::shared_ptr<Unit> archer = std::make_shared<Solder>(ARCHER,archer_id_, archer_HP_max, solder_position_x_, soler_position_y_, archer_damage, archer_damage_distance, archer_move_distance);
		GameManager::instance().getGamer()->getCurrentRound().add2Army(archer);
	}*/
	/*numberWarrior = ui.warriosNumber->value();
	numberArcher = ui.archersNumber->value();*/
	if (ui.warriosNumber->value() == 0 && ui.archersNumber->value() == 0) {
		QMessageBox msgBox; 
		msgBox.setText("YOU SHOULD CHOOSE YOUR ARMY BEFORE START!!! ");
		msgBox.exec();
	}
	else {
		QtGuiBattlefield* gui_field = new QtGuiBattlefield(this);
		gui_field->setBossID(bossID);
		gui_field->setNumberArcher(ui.archersNumber->value());
		gui_field->setNumberWarrior(ui.warriosNumber->value());
		gui_field->initCanvas();
		gui_field->show();
		this->hide();
	}
	
	
}

void QtGuiArmyConfig::BtnB_Click() {
	this->parentWidget()->show();
	delete this;
}
