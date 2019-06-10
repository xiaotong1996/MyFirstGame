#pragma once
#include "Command.h"
#include "Unit.h"
class MoveCommand :
	public Command
{
public:
	MoveCommand(std::shared_ptr<Unit> unit, std::pair<float, float> position);
	~MoveCommand();
	virtual void execute();
	virtual void undo();

private:
	std::shared_ptr<Unit> unit;
	std::pair<float, float> position_before;
	std::pair<float, float> position;
};

