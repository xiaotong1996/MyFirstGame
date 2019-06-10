#include "stdafx.h"
#include "Gamer.h"


Gamer::Gamer()
{
}

void Gamer::addRound(int population_max)
{
	GameRound gameround = GameRound(population_max);
	rounds.push_back(gameround);
}

GameRound& Gamer::getCurrentRound() {
	return rounds.back();
}

Gamer::~Gamer()
{
}
