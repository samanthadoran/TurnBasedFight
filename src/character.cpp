#include "../include/character.h"

Character::Character()
{
    //ctor
}

Character::Character(std::string name, double life)
{
    this->name = name;
    this->life = life;
}

double Character::getLife() const
{
    return life;
}

std::string Character::getName() const
{
    return name;
}

std::string Character::toString() const
{
    std::stringstream toRet;
    toRet << name << ": " << life;
    if(target == NULL)
        toRet << "\t No current target!";
    else
        toRet << "\t Current target: " << target->getName() << ".";
    return toRet.str();
}

void Character::setTarget(Character * target)
{
    this->target = target;
}

std::string Character::doAction() const
{
    std::stringstream toRet;
    toRet << this->getName() << " did nothing to " << target->getName() << "!";
    return toRet.str();
}

std::string Character::doAction(Action * act)
{
    std::stringstream toRet;
    return act->use(this, target);
}

void Character::setLife(double life)
{
    this->life = life;
}

Character::~Character()
{
    //dtor
}
