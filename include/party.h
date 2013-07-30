#ifndef PARTY_H
#define PARTY_H
#include <vector>
#include <string>
#include <iostream>
#include "character.h"

class Party
{
    public:
        Party();
        std::string toString() const;
        Character * select();
        Character * get(unsigned int);
        void removeMember(Character *);
        unsigned int getSize() const;
        void insertMember(Character *);
        virtual ~Party();
    protected:
    private:
        std::vector<Character*> members;
};

#endif // PARTY_H
