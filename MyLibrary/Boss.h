#pragma once
#include "Unit.h"
/*Boss represents a boss unit
*/
class Boss :
	public Unit
{
private:
	int damage;
	int damage_distance;
	int heal_dose;
public:
	Boss(std::string id,int HP_max, float position_x, float position_y,int damage,int damage_distance,int heal_dose,int move_distance);
	~Boss();
	virtual int getDamage() override;
	virtual int getDamageDistance() override;
	//solderType getType() override;
	const int getHeal();
	sf::Sprite getMySprite();
};

