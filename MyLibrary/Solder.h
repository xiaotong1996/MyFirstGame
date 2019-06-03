#pragma once
#include "Unit.h"
class Solder :
	public Unit
{
public:
	Solder();
	~Solder();
	void attack(std::unique_ptr<Unit> unit_target);
private:
	int damage;
	int damage_distance;
};

