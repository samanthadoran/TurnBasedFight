#include "../include/attack.h"

Attack::Attack(std::string name, double hpEffect):Action(name)
{
    this->hpEffect = hpEffect;
}

std::string Attack::use(Character * source, Character * target) const
{
    target->setLife(target->getLife() - hpEffect);
    std::stringstream ss;
    ss << source->getName() << " uses " << this->getName() << " on " << target-> getName();
    return ss.str();
}

std::string Attack::toString() const
{
    std::stringstream ss;
    ss << this->getName() << ": Dmg(" <<hpEffect << ")";
    return ss.str();
}

Attack::~Attack()
{
    //dtor
}
