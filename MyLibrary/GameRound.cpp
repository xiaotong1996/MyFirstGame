#include "stdafx.h"
#include "GameRound.h"
#include <algorithm>


//GameRound::GameRound(int population_max, std::shared_ptr<Boss> boss) :population_max(population_max), turn_time(0), boss(boss)
//{
//}
static int recordtime=0;
GameRound::GameRound(int bossID, int numberWarrior, int numberArcher) : turn_time(0), is_start(false), is_end(false), recordID(recordtime), is_canceled(false), roundState(INIT)
{
	fsm.add_transitions({
		{RoundState::INIT, RoundState::START, Triggers::gameStart, nullptr, nullptr},
		{RoundState::START, RoundState::WIN, Triggers::winOrLoss, [&] {return WIN == winOrLoss(); }, nullptr},
		{RoundState::START, RoundState::LOSS, Triggers::winOrLoss, [&] {return LOSS == winOrLoss(); }, nullptr},
		{RoundState::START, RoundState::DRAW, Triggers::winOrLoss, [&] {return DRAW == winOrLoss(); }, nullptr},
		{RoundState::INIT, RoundState::END, Triggers::gameEnd, nullptr, nullptr},
		{RoundState::START, RoundState::END, Triggers::gameEnd, nullptr, nullptr},
		{RoundState::WIN, RoundState::END, Triggers::gameEnd, nullptr, nullptr},
		{RoundState::LOSS, RoundState::END, Triggers::gameEnd, nullptr, nullptr},
		{RoundState::DRAW, RoundState::END, Triggers::gameEnd, nullptr, nullptr},
		});

	recordtime++;
	//init boss
	float boss_position_x = GameConfigue::boss1_position_x();
	float boss_position_y = GameConfigue::boss1_position_y();
	std::string boss1_id = GameConfigue::boss1_id();
	int boss1_HP_max = GameConfigue::boss1_HP_max();
	int boss1_damage = GameConfigue::boss1_damage();
	int boss1_damage_distance = GameConfigue::boss1_damage_distance();
	int boss1_heal_dose = GameConfigue::boss1_heal_dose();
	int boss1_move_distance = GameConfigue::boss1_move_distance();

	std::shared_ptr<Boss> boss = std::make_shared<Boss>(boss1_id, boss1_HP_max, boss_position_x, boss_position_y, boss1_damage, boss1_damage_distance, boss1_heal_dose, boss1_move_distance);
	bosss.push_back(boss);
	//init army
	float solder_position_x = GameConfigue::warrior_position_x();
	float solder_position_y = GameConfigue::warrior_postition_y();
	std::string warrior_id = GameConfigue::warrior_id();
	int warrior_HP_max = GameConfigue::warrior_HP_max();
	int warrior_damage = GameConfigue::warrior_damage();
	int warrior_damage_distance = GameConfigue::warrior_damage_distance();
	int warrior_move_distance = GameConfigue::warrior_move_distance();
	std::string archer_id = GameConfigue::archer_id();
	int archer_HP_max = GameConfigue::archer_HP_max();
	int archer_damage = GameConfigue::archer_damage();
	int archer_damage_distance = GameConfigue::archer_damage_distance();
	int archer_move_distance = GameConfigue::archer_move_distance();

	int scale = GameConfigue::default_scale();

	for (int i = 0; i < numberWarrior; i++) {
		std::string warrior_id_ = warrior_id + std::to_string(i);
		float solder_position_x_ = solder_position_x + scale * 2;
		float soler_position_y_ = solder_position_y + i * scale * 2;
		std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR, warrior_id_, warrior_HP_max, solder_position_x_, soler_position_y_, warrior_damage, warrior_damage_distance, warrior_move_distance);
		army.push_back(warrior);
	}
	for (int i = 0; i < numberArcher; i++) {
		std::string archer_id_ = archer_id + std::to_string(i);
		float solder_position_x_ = solder_position_x;
		float soler_position_y_ = solder_position_y + i * scale * 2;
		std::shared_ptr<Unit> archer = std::make_shared<Solder>(ARCHER, archer_id_, archer_HP_max, solder_position_x_, soler_position_y_, archer_damage, archer_damage_distance, archer_move_distance);
		army.push_back(archer);
	}


}

//GameRound::GameRound(int population_max) : population_max(population_max), turn_time(0), is_start(false), is_end(false), recordID(recordtime), is_canceled(false),roundState(RUNNING)
//{
//	recordtime++;
//}


GameRound::~GameRound()
{
}

//const int GameRound::getPopulationMax() const
//{
//	// TODO: insert return statement here
//	return population_max;
//}

std::vector<std::shared_ptr<Boss>>& GameRound::getBosss()
{
	return bosss;
}


std::vector<std::shared_ptr<Unit>>& GameRound::getArmy()
{
	// TODO: insert return statement here
	return army;
}

void GameRound::add2Army(std::shared_ptr<Unit> unit)
{
	army.push_back(unit);
}

void GameRound::add2Boss(std::shared_ptr<Boss> boss)
{
	bosss.push_back(boss);
}

void GameRound::addTurn()
{
	turn_time++;
	is_canceled = false;
}

const int GameRound::getTurn()
{
	return turn_time;
}

RoundState GameRound::winOrLoss()
{
	if (roundState == END) return END;
	auto isBossKilled = [](std::shared_ptr <Boss> boss) {if (boss->getHP() <= 0) return true; else return false; };
	bool isAllBosskilled = std::all_of(bosss.begin(), bosss.end(), isBossKilled);
	auto isUnitsKilled = [](std::shared_ptr <Unit> unit) {if (unit->getHP() <= 0) return true; else return false; };
	bool isAllUnitkilled = std::all_of(army.begin(), army.end(), isUnitsKilled);


	if (isAllBosskilled&&isAllUnitkilled) {
		return DRAW;
	}
	else if (isAllBosskilled && !isAllUnitkilled)
	{
		return WIN;
	}
	else if (!isAllBosskilled && isAllUnitkilled) {
		return LOSS;
	}
	else {
		return START;
	}
	
}


void GameRound::setCanceled(bool i)
{
	is_canceled = i;
}

bool GameRound::getCanceled()
{
	return is_canceled;
}


void GameRound::addCommand2Boss(std::shared_ptr<Command> command)
{
	command_boss.push_back(command);
}

void GameRound::addCommand2Army(std::shared_ptr<Command> command)
{
	command_army.push_back(command);
}

void GameRound::cancelLastCommand()
{
	if (!is_canceled) {
		turn_time--;
		if (!command_army.empty())
			command_army.back()->undo();
		if (!command_boss.empty())
			command_boss.back()->undo();
	}
	is_canceled = true;
}







