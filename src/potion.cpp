#include "../include/potion.h"

Potion::Potion(std::string name, double hpEffect) : Action(name)
{
    this->hpEffect = hpEffect;
}

std::string Potion::use(Character * source, Character * target) const
{
    target->setLife(target->getLife() + hpEffect);
    std::stringstream ss;
    ss << source->getName() << " gives " << this->getName() << " to " << target-> getName();
    ss << "\n" << target->getName() << " drinks " << this->getName();
    return ss.str();
}

std::string Potion::toString() const
{
    std::stringstream ss;
    ss << this->getName() << ": HP Eff.(" <<hpEffect << ")";
    return ss.str();
}

Potion::~Potion()
{
    //dtor
}
