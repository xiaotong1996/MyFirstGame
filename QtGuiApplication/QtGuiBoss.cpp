#include "QtGuiBoss.h"
#include "QtGuiArmyConfig.h"
#include "../MyLibrary/GameManager.h"



QtGuiBoss::QtGuiBoss(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtGuiBoss::~QtGuiBoss()
{
}


void QtGuiBoss::Btn1_Click()
{
	//set boss1
	/*float boss_position_x = GameManager::instance().getGameConfigue()->boss1_position_x();
	float boss_position_y = GameManager::instance().getGameConfigue()->boss1_position_y();
	std::string boss1_id = GameManager::instance().getGameConfigue()->boss1_id();
	int boss1_HP_max = GameManager::instance().getGameConfigue()->boss1_HP_max();
	int boss1_damage = GameManager::instance().getGameConfigue()->boss1_damage();
	int boss1_damage_distance = GameManager::instance().getGameConfigue()->boss1_damage_distance();
	int boss1_heal_dose = GameManager::instance().getGameConfigue()->boss1_heal_dose();
	int boss1_move_distance = GameManager::instance().getGameConfigue()->boss1_move_distance();


	std::shared_ptr<Boss> boss=std::make_shared<Boss>(boss1_id, boss1_HP_max, boss_position_x, boss_position_y, boss1_damage, boss1_damage_distance, boss1_heal_dose, boss1_move_distance);
	const int population_limit_boss1 = GameManager::instance().getGameConfigue()->population_limit_boss1();
	GameManager::instance().getGamer()->addRound(population_limit_boss1);
	GameManager::instance().getGamer()->getCurrentRound().add2Boss(boss);*/
	
	QtGuiArmyConfig* gui_army = new QtGuiArmyConfig(this);
	gui_army->setBossID(1);
	gui_army->show();
	this->hide();
}

void QtGuiBoss::BtnB_Click() {
	this->parentWidget()->show();
	delete this;
}
