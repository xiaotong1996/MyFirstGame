#include "stdafx.h"
#include "WaitCommand.h"


WaitCommand::WaitCommand(std::shared_ptr<Unit> unit)
	:unit(unit)
{
}


WaitCommand::~WaitCommand()
{
}

void WaitCommand::execute()
{
	unit->waitChange();
}

void WaitCommand::undo()
{
	unit->waitChange();
}
