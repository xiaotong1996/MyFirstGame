#pragma once
#include <memory>
#include <utility>

class Unit
{
private:
	int id;
	int population;
	int HP;
	std::pair<int, int> position;
	int move_distance;
	bool is_wait;
public:
	void moveTo(std::pair<int, int> position_new);
	void waitChange();
	virtual void attack() = 0;
	virtual int getDamage() = 0;
	virtual int getDamageDistance() = 0;
	int getHP();
	void setHP(int HPnew);
	Unit();
	~Unit();
};

