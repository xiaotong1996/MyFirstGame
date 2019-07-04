#pragma once
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include "fsm.h"
/*Unit is the base class used to represent the pieces on the battlefield.
*/
class Unit
{
protected:
	sf::Texture myImage;
	sf::Sprite mySprite;
private:
	std::string id;
	int population;
	int HP;
	int HP_max;
	std::pair<float, float> position;
	int move_distance;
public:
	enum class States { Unselected, Selected, Attacking, Moving, Attacked, Moved, Wait };
	enum class Triggers { Select, UnSelect, BtnAttack, BtnMove, MouseAttack, MouseMove, BtnWait };
	FSM::Fsm<States, States::Unselected, Triggers> fsm;

	const std::pair<float, float> getPosition();
	void moveTo(std::pair<float, float> position_new);
	virtual int getDamage() = 0;
	virtual int getDamageDistance() = 0;
	const int getHP();
	const int getHPmax();
	const int getMoveDistance();
	void setHP(int HPnew);
	const std::string getID();
	virtual sf::Sprite getMySprite()=0;
	Unit(std::string id,int population,int HP_max, float position_x, float position_y,int move_distance);
	~Unit();
};

