#include "stdafx.h"
#include "Unit.h"

Unit::Unit(std::string id, int population, int HP_max, float position_x, float position_y, int move_distance)
	:id(id), population(population), HP(HP_max), HP_max(HP_max)
	, position(std::pair<float, float>(position_x, position_y))
	, move_distance(move_distance)
{
	fsm.add_transitions({
		//  from state ,to state  ,triggers        ,guard                    ,action
		  { States::Unselected  ,States::Selected ,Triggers::Select  ,nullptr  ,nullptr },
		  { States::Selected  ,States::Unselected ,Triggers::UnSelect  ,nullptr  ,nullptr },
		  { States::Selected  ,States::Wait ,Triggers::BtnWait  ,nullptr  ,nullptr },
	      { States::Selected  ,States::Attacking ,Triggers::BtnAttack  ,nullptr  ,nullptr },
		  { States::Selected  ,States::Moving ,Triggers::BtnMove  ,nullptr  ,nullptr },
		  { States::Attacking  ,States::Attacked ,Triggers::MouseAttack  ,nullptr  ,nullptr },
		  { States::Moving  ,States::Moved ,Triggers::MouseMove  ,nullptr  ,nullptr },
		});
}

Unit::~Unit()
{
}


void Unit::moveTo(std::pair<float, float> position_new)
{
	position = position_new;
	mySprite.setPosition(sf::Vector2f(position_new.first, position_new.second));
}

const int Unit::getHP()
{
	return HP;
}

const int Unit::getHPmax()
{
	return HP_max;
}

const int Unit::getMoveDistance()
{
	return move_distance;
}

void Unit::setHP(int HPnew)
{
	HP = HPnew;
}

const std::string Unit::getID()
{
	return id;
}

const std::pair<float, float> Unit::getPosition()
{
	return position;
}









