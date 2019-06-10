#include "stdafx.h"
#include "MoveCommand.h"


MoveCommand::MoveCommand(std::shared_ptr<Unit> unit, std::pair<float, float> position)
	:unit(unit),
	position(position),
	position_before(std::pair<float, float>(0,0))
{
}

MoveCommand::~MoveCommand()
{
}

void MoveCommand::execute()
{
	position_before = unit->getPosition();
	unit->moveTo(position);
}

void MoveCommand::undo()
{
	unit->moveTo(position_before);
}
