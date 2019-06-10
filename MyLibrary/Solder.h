#pragma once
#include "Unit.h"
/*Solder is used to represent the unit that has attack ability 
except the boss on the board.
*/

class Solder :
	public Unit
{
public:
	Solder(solderType type,std::string id, int HP_max, float position_x, float position_y, int damage, int damage_distance, int move_distance);
	~Solder();
	void attack(std::unique_ptr<Unit> unit_target);
	virtual int getDamage() override;
	virtual int getDamageDistance() override;
	solderType getType() override;
	sf::Sprite getMySprite();
private:
	
	solderType type;
	int damage;
	int damage_distance;
};

