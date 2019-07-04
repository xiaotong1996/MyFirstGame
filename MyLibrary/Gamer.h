#pragma once
#include <vector>
#include <memory>
#include "GameRound.h"
/*Gamer contains players gameround records
* It can be used to save player's own configuation. used for more further functions.
*/
//NOT used 
class Gamer
{
public:
	Gamer();
	~Gamer();
	//void addRound(int population_max);
	GameRound& getCurrentRound();
private:
	std::vector<GameRound> rounds;
};

