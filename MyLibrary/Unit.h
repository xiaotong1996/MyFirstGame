#pragma once
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>

/*Unit is the base class used to represent the pieces on the battlefield.
*/

enum solderType {
	WARRIOR,
	ARCHER,
};

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
	bool is_wait;
	bool is_selected;
public:
	const std::pair<float, float> getPosition();
	void moveTo(std::pair<float, float> position_new);
	void waitChange();
	virtual int getDamage() = 0;
	virtual int getDamageDistance() = 0;
	virtual solderType getType() = 0;
	const int getHP();
	const int getHPmax();
	const int getMoveDistance();
	void setHP(int HPnew);
	const std::string getID();
	virtual sf::Sprite getMySprite()=0;
	const bool isSelected();
	void setSelected();
	void setUnSelected();
	Unit(std::string id,int population,int HP_max, float position_x, float position_y,int move_distance);
	~Unit();
};

