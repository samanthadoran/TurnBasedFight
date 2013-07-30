#ifndef ATTACK_H
#define ATTACK_H

#include "action.h"


class Attack: public Action
{
    public:
        Attack(std::string, double);
        Attack();
        std::string use(Character *, Character *) const;
        std::string toString() const;
        virtual ~Attack();
    protected:
    private:
        double hpEffect;
};

#endif // ATTACK_H
