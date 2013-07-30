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

Action * Character::selectAction()
{
    //Prompt the user for their choice
    int selection = 0;
    do
    {
        std::cout << toString() << std::endl;
        std::cout << "-1. Return to the previous menu..." << std::endl;
        std::cout << listActions() << std::endl;
        std::cin >> selection;
        std::cout << std::endl;
    }while(selection == 0 || selection > actions.size());

    if(selection == -1)
    {
        std::cout << "Returning to main menu." << std::endl;
        return nullptr;
    }
    else
    {
        return actions[selection-1];
    }
}

double Character::getLife() const
{
    return life;
}

std::string Character::getName() const
{
    return name;
}

std::string Character::listActions() const
{
    //std::string toRet = toString();
    std::stringstream toRet;
    //toRet += "\n";
    for(int i = 0; i < actions.size(); ++i)
    {
        toRet << " " << i + 1 << ". " << actions[i]->toString() << "\n";
    }
    //return toRet.append(working.str());
    return toRet.str();
}

std::string Character::toString() const
{
    std::stringstream toRet;
    toRet << name << ": " << life;
    if(target == nullptr)
        toRet << "\t No current target!";
    else
        toRet << "\t Current target: " << target->getName() << ".";

    return toRet.str();
}

void Character::setTarget(Character * target)
{
    this->target = target;
}

Character * Character::getTarget()
{
    return target;
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

void Character::addAction(Action * act)
{
    actions.push_back(act);
}

void Character::setLife(double life)
{
    this->life = life;
}

Character::~Character()
{
    //dtor
}
