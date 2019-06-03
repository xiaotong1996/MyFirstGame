#include "stdafx.h"
#include "WaitCommand.h"


WaitCommand::WaitCommand(std::unique_ptr<Unit>& unit)
	:unit(std::move(unit))
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
