#include "stdafx.h"
#include "Unit.h"

Unit::Unit(std::string id, int population, int HP_max, float position_x, float position_y, int move_distance)
	:id(id), population(population), HP(HP_max), HP_max(HP_max)
	, position(std::pair<float, float>(position_x, position_y))
	, move_distance(move_distance)
	, is_wait(false)
	, is_selected(false)
{

}

Unit::~Unit()
{
}


void Unit::moveTo(std::pair<float, float> position_new)
{
	position = position_new;
	mySprite.setPosition(sf::Vector2f(position_new.first, position_new.second));
}

void Unit::waitChange()
{
	if (is_wait) is_wait = false;
	else is_wait = true;
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

const bool Unit::isSelected() {
	return is_selected;
}

void Unit::setSelected() {
	is_selected = true;
}

void Unit::setUnSelected() {
	is_selected = false;
}





