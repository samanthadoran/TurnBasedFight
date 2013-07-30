#ifndef POTION_H
#define POTION_H

#include "action.h"


class Potion : public Action
{
    public:
        Potion(std::string, double);
        std::string use(Character *, Character *) const;
        std::string toString() const;
        virtual ~Potion();
    protected:
    private:
        double hpEffect;
};

#endif // POTION_H
