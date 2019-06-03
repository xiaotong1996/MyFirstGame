#pragma once
#include "Command.h"
class WaitCommand :
	public Command
{
public:
	WaitCommand(std::unique_ptr<Unit>& unit);
	~WaitCommand();
	virtual void execute();
	virtual void undo();
private:
	std::unique_ptr<Unit> unit;
};

