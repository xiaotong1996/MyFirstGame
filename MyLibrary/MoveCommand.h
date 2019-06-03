#pragma once
#include "Command.h"
#include "Unit.h"
class MoveCommand :
	public Command
{
public:
	MoveCommand(std::unique_ptr<Unit>& unit, std::pair<int, int> position);
	~MoveCommand();
	virtual void execute();
	virtual void undo();

private:
	std::unique_ptr<Unit> unit;
	std::pair<int, int> position_before;
	std::pair<int, int> position;
};

