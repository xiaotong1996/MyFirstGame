#pragma once
#include "Gamer.h"
#include <memory>
#include "GameConfigue.h"
class GameManager
{
public:
	static GameManager& instance() { return instance_; }
	std::shared_ptr<Gamer> getGamer() { return gamer_; }
	std::shared_ptr<GameConfigue> getGameConfigue() { return gameConfigue_; }
	void initGamer() { gamer_ = std::make_shared<Gamer>(); }
	void initGameConfigue() { gameConfigue_ = std::make_shared<GameConfigue>(); }
private:
	static GameManager instance_;
	std::shared_ptr<Gamer> gamer_;
	std::shared_ptr<GameConfigue> gameConfigue_;

};

