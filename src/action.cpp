#include "../include/action.h"

Action::Action(std::string name)
{
    this->name = name;
}

std::string Action::toString() const
{
   return "";
}

std::string Action::getName() const
{
    return name;
}

std::string Action::use(Character * source, Character * target) const
{
    return "";
}

Action::~Action()
{
    //dtor
}
