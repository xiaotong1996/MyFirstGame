#pragma once
#include "Unit.h"
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute() = 0;
	virtual void undo() = 0;
};

