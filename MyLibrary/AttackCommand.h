#pragma once
#include "Command.h"
class AttackCommand :
	public Command
{
public:
	AttackCommand(std::unique_ptr<Unit>& unit_a, std::unique_ptr<Unit>& unit_d);
	~AttackCommand();
	virtual void execute();
	virtual void undo();

private:
	std::unique_ptr<Unit> unit_attacker;
	std::unique_ptr<Unit> unit_target;
	int targetHP_before;
};

