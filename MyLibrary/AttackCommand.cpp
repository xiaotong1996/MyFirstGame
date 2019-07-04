#include "stdafx.h"
#include "AttackCommand.h"


AttackCommand::AttackCommand(std::shared_ptr<Unit> unit_a, std::shared_ptr<Unit> unit_d)
	:unit_attacker(unit_a), unit_target(unit_d),targetHP_before(0)
{

}


AttackCommand::~AttackCommand()
{
}

void AttackCommand::execute()
{
	unit_attacker->fsm.execute(Unit::Triggers::MouseAttack);
	targetHP_before = unit_target->getHP();
	unit_target->setHP(unit_target->getHP() - unit_attacker->getDamage());
	unit_attacker->fsm.reset();
}

void AttackCommand::undo()
{
	unit_target->setHP(targetHP_before);
	unit_attacker->fsm.reset();
}
