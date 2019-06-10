#include "pch.h"
#include "../MyLibrary/GameManager.h"
#include "../MyLibrary/MoveCommand.h"
#include "../MyLibrary/AttackCommand.h"
/*
1. 测collision
2. 测移动
3. 测xml解析
4. 测UI关联
*/
/*test GameConfigue class
* this class is used to configue all game constant variables.
*/
TEST(TestMyLibrary, TestConfigure) {
	GameManager::instance().initGamer();
	GameManager::instance().initGameConfigue();
	bool getconfig = false;
	if (GameManager::instance().getGameConfigue()) getconfig = true;
	EXPECT_TRUE(getconfig);
	float boss_position_x = GameManager::instance().getGameConfigue()->boss1_position_x();
	EXPECT_EQ(boss_position_x, 960);
	const int population_limit_boss1 = GameManager::instance().getGameConfigue()->population_limit_boss1();
	EXPECT_EQ(population_limit_boss1, 20);
}

TEST(TestMyLibrary, TestUnitMove) {
	std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR, "warrior0", 100, 128, 288, 10, 128, 160);
	std::shared_ptr<Command> moveCommande = std::make_shared<MoveCommand>(warrior, std::pair<float, float>(100, 200));
	moveCommande->execute();
	EXPECT_EQ(warrior->getPosition().first, 100.0);
	EXPECT_EQ(warrior->getPosition().second, 200.0);
}

TEST(TestMyLibrary, TestUnitUndoMove) {
	std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR, "warrior0", 100, 128, 288, 10, 128, 160);
	std::shared_ptr<Command> moveCommande = std::make_shared<MoveCommand>(warrior, std::pair<float, float>(100, 200));
	moveCommande->execute();
	moveCommande->undo();
	EXPECT_EQ(warrior->getPosition().first, 128);
	EXPECT_EQ(warrior->getPosition().second, 288);
}

TEST(TestMyLibrary, TestUnitAttack) {
	std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR, "warrior0", 100, 128, 288, 10, 128, 160);
	std::shared_ptr<Boss> boss = std::make_shared<Boss>("boss1", 100, 960, 320, 20, 160, 20, 160);
	std::shared_ptr<Command> attackCommand = std::make_shared<AttackCommand>(warrior, boss);
	attackCommand->execute();
	EXPECT_EQ(boss->getHP(), 90);
}

TEST(TestMyLibrary, TestUnitUndoAttack) {
	std::shared_ptr<Unit> warrior = std::make_shared<Solder>(WARRIOR, "warrior0", 100, 128, 288, 10, 128, 160);
	std::shared_ptr<Boss> boss = std::make_shared<Boss>("boss1", 100, 960, 320, 20, 160, 20, 160);
	std::shared_ptr<Command> attackCommand = std::make_shared<AttackCommand>(warrior, boss);
	attackCommand->execute();
	attackCommand->undo();
	EXPECT_EQ(boss->getHP(), 100);
}