#include "stdafx.h"
#include "Unit.h"


void Unit::moveTo(std::pair<int, int> position_new)
{
	position = position_new;
}

void Unit::waitChange()
{
	if (is_wait) is_wait = false;
	else is_wait = true;
}

int Unit::getHP()
{
	return HP;
}

void Unit::setHP(int HPnew)
{
	HP = HPnew;
}

Unit::Unit()
{
}


Unit::~Unit()
{
}


