#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "action.h"

class Action;

class Character
{
    public:
        Character();
        Character(std::string, double);
        virtual ~Character();
        double getLife() const;
        std::string getName() const;
        std::string toString() const;
        void setTarget(Character *);
        std::string doAction() const;
        std::string doAction(Action *);
        void setLife(double);
    protected:
    private:
        Character * target;
        std::string name;
        double life;
};

#endif // CHARACTER_H
