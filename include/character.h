#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <iostream>
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
        std::string listActions() const;
        void setTarget(Character *);
        Character * getTarget();
        Action * selectAction();
        void addAction(Action*);
        std::string doAction() const;
        std::string doAction(Action *);
        void setLife(double);
    protected:
    private:
        std::vector<Action*> actions;
        Character * target;
        std::string name;
        double life;
};

#endif // CHARACTER_H
