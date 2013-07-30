#ifndef SPELL_H
#define SPELL_H

#include "action.h"


class Spell : public Action
{
    public:
        Spell(std::string, double);
        std::string use(Character *, Character *) const;
        std::string toString() const;
        virtual ~Spell();
    protected:
    private:
        double hpEffect;
};

#endif // SPELL_H
