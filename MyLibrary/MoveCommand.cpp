#include "stdafx.h"
#include "MoveCommand.h"


MoveCommand::MoveCommand(std::unique_ptr<Unit> & unit, std::pair<int, int> position)
	:unit(std::move(unit)),
	position(position),
	position_before(std::pair<int,int>(0,0))
{
}

MoveCommand::~MoveCommand()
{
}

void MoveCommand::execute()
{
	position_before = position;
	unit->moveTo(position);
}

void MoveCommand::undo()
{
	unit->moveTo(position_before);
}
