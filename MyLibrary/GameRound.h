#pragma once
#include <vector>
#include "Unit.h"
#include "Boss.h"
#include "Solder.h"
#include "Command.h"

enum RoundState {
	WIN,
	LOSS,
	DRAW,
	RUNNING,
	START,
	END
};
/*GameRoud used to manage a player's one whole round
* It contains this round the maximum population player can use,
* how many turns player has played,
* which boss player has chosen, etc.
*/
class GameRound
{
public:
	//GameRound(int population_max, std::shared_ptr<Boss> boss);
	GameRound(int population_max);//constructor set population
	~GameRound();
	const int getPopulationMax() const;//get population maximam
	std::vector<std::shared_ptr<Boss>>& getBosss();//get all boss player has choosen to challenge in this Round
	std::vector<std::shared_ptr<Unit>> & getArmy();//get all solders player has choosen to use in this Round
	void add2Army(std::shared_ptr<Unit> unit);//add a solder 
	void add2Boss(std::shared_ptr<Boss> boss);//add a boss
	void addTurn();//add turn time
	const int getTurn();//get turn time
	void gameStart();//set this round start
	bool isStart();//check is this round start
	void gameEnd();//set this round end
	bool isEnd();//check is this round end
	void setCanceled(bool i);//set cancel function usable or not
	bool getCanceled();//check if cancek function has been used
	void addCommand2Boss( std::shared_ptr<Command> command);//add a boss command
	void addCommand2Army( std::shared_ptr<Command> command);//add a unit's command
	void cancelLastCommand();//undo boss and unit's last command
	RoundState winOrLoss();//check round state
private:	
	int recordID;//unique id to record this round
	bool is_canceled;//cancel function usable or not
	bool is_start;//whole round start or not
	bool is_end;//whole round end or not
	std::vector<std::shared_ptr<Boss>> bosss;//boss chosen to be challenged in this whole round
	std::vector<std::shared_ptr<Command>> command_boss;//AI's commands for boss
	int turn_time;//turn time
	int population_max;//population MAX
	std::vector<std::shared_ptr<Unit>> army;//army chosen to defeat bosses
	std::vector<std::shared_ptr<Command>> command_army;//player's command for army
	RoundState roundState;
};

