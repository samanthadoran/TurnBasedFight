#include <iostream>

#include "include/attack.h"
#include "include/potion.h"
#include "include/spell.h"
#include "include/character.h"
#include "include/party.h"

int main()
{

    Party party1;
    Party party2;
    Party usable;

    party1.insertMember(new Character("Sammi" , 30.0));
    party1.insertMember(new Character("Helwig", 30.0));
    party1.insertMember(new Character("Shadow", 30.0));
    party1.insertMember(new Character("Travis", 30.0));

    usable = party1;

    party2.insertMember(new Character("Bobert", 15.0));
    party2.insertMember(new Character("Crowbar Guy", 15.0));

    while(usable.getSize() > 0)
    {
        //Prompt the user
        std::cout << "Enter the number of the character you wish to select" << std::endl;

        //Get the character we are using
        Character * charSelected = usable.select();

        //The user asked to return to the previous menu (selecting a source character), just restart the loop.
        if(charSelected == NULL)
            continue;

        Character * target = NULL;

        do
        {
            //Prompt the user whether or not they would like to select a member of their own party, or the other.
            unsigned int selection;
            do
            {
                std::cout << "Enter 0 if you would like " << charSelected->getName() <<  " to target a character from your team, or 1 if from the opposing team" << std::endl;
                std::cin >> selection;
            }while( selection > 1);

            if(selection == 1)
            {
                std::cout << "Enter the number of the enemy you wish to select" << std::endl;
                target = party2.select();
            }
            else
            {
                std::cout << "Enter the number of the character you wish to select" << std::endl;
                target = party1.select();
            }
        //If target is null, the user asked to return to the previous menu, restart the loop.
        }while(target == NULL);

        //They have locked in.
        std::cout << "***" << charSelected->getName() << " has selected " << target->getName() << " as their target.***\n\n" << std::endl;
        charSelected->setTarget(target);
        usable.removeMember(charSelected);
    }

    std::cout << party1.toString() << std::endl;
    std::cout << party2.toString() << std::endl;

    return 0;
}
