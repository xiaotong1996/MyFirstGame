#pragma once
#include "Unit.h"
class Boss :
	public Unit
{
private:
	int damage;
	int damage_distance;
	int head_dose;
public:
	Boss();
	~Boss();
	virtual int getDamage();
	virtual int getDamageDistance();
};

