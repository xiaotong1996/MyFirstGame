#pragma once
#include "Command.h"
/*AttackCommand used for Player to control a unit attack another one
*/
class AttackCommand :
	public Command
{
public:
	AttackCommand(std::shared_ptr<Unit> unit_a, std::shared_ptr<Unit> unit_d);
	~AttackCommand();
	virtual void execute();
	virtual void undo();

private:
	std::shared_ptr<Unit> unit_attacker;
	std::shared_ptr<Unit> unit_target;
	int targetHP_before;//used for undo
};

