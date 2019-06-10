#include "stdafx.h"
#include "GameRound.h"
#include <algorithm>


//GameRound::GameRound(int population_max, std::shared_ptr<Boss> boss) :population_max(population_max), turn_time(0), boss(boss)
//{
//}
static int recordtime=0;
GameRound::GameRound(int population_max) : population_max(population_max), turn_time(0), is_start(false), is_end(false), recordID(recordtime), is_canceled(false),roundState(RUNNING)
{
	recordtime++;
}


GameRound::~GameRound()
{
}

const int GameRound::getPopulationMax() const
{
	// TODO: insert return statement here
	return population_max;
}

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

void GameRound::gameStart()
{
	is_start = true;
}

bool GameRound::isStart()
{
	return is_start;
}

void GameRound::gameEnd()
{
	is_end = true;
	roundState = END;
}

bool GameRound::isEnd()
{
	return is_end;
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
		return RUNNING;
	}
}







