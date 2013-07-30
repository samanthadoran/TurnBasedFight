#include "../include/spell.h"

Spell::Spell(std::string name, double hpEffect):Action(name)
{
    this->hpEffect = hpEffect;
}

std::string Spell::use(Character * source, Character * target) const
{
    target->setLife(target->getLife() + hpEffect);
    std::stringstream ss;
    ss << source->getName() << " casts " << this->getName() << " on " << target-> getName();
    return ss.str();
}

std::string Spell::toString() const
{
    std::stringstream ss;
    ss << this->getName() << ": HP eff.(" <<hpEffect << ")";
    return ss.str();
}

Spell::~Spell()
{
    //dtor
}
