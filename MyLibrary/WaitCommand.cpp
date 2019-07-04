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
	unit->fsm.execute(Unit::Triggers::BtnWait);
	unit->fsm.reset();
}

void WaitCommand::undo()
{
	unit->fsm.reset();
}
