#ifndef ACTION_H
#define ACTION_H
#include <string>
#include <sstream>
#include "character.h"

class Character;

class Action
{
    public:
        //Action();
        //Action(std::string, double);
        Action(std::string);
        virtual ~Action();
        virtual std::string toString() const;
        std::string getName() const;
        virtual std::string use(Character * source, Character * target) const;
    protected:
    private:
        std::string name;
};

#endif // ACTION_H
