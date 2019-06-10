#pragma once
#include "Command.h"
class WaitCommand :
	public Command
{
public:
	WaitCommand(std::shared_ptr<Unit> unit);
	~WaitCommand();
	virtual void execute();
	virtual void undo();
private:
	std::shared_ptr<Unit> unit;
};

