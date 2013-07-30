#include <iostream>
#include "include/attack.h"
#include "include/potion.h"
#include "include/spell.h"
#include "include/character.h"
#include "include/party.h"

int main()
{

    Attack * punch = new Attack("Punch", 5.0);

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


    party1.get(0)->addAction(punch);
    party1.get(1)->addAction(punch);
    party1.get(2)->addAction(punch);
    party1.get(3)->addAction(punch);

    std::cout << "***ENTERING TARGET SELECTION PHASE!***" << std::endl;

    while(usable.getSize() > 0)
    {
        //Prompt the user
        std::cout << "Enter the number of the character you wish to select\n\n" << std::endl;

        //Get the character we are using
        Character * charSelected = usable.select();

        //The user asked to return to the previous menu (selecting a source character), just restart the loop.
        if(charSelected == nullptr)
            continue;

        do
        {
            //Prompt the user whether or not they would like to select a member of their own party, or the other.
            unsigned short int selection;
            do
            {
                std::cout << "Enter 0 if you would like " << charSelected->getName() <<  " to target a character from your team, or 1 if from the opposing team" << std::endl;
                std::cin >> selection;
            }while( selection > 1);

            if(selection == 1)
            {
                std::cout << "Enter the number of the enemy you wish to select\n\n" << std::endl;
                charSelected->setTarget(party2.select());
            }
            else
            {
                std::cout << "Enter the number of the character you wish to select\n\n" << std::endl;
                charSelected->setTarget(party1.select());
            }
        //If target is null, the user asked to return to the previous menu, restart the loop.
        }while(charSelected->getTarget() == nullptr);

        //They have locked in.
        std::cout << "***" << charSelected->getName() << " has selected " << charSelected->getTarget()->getName() << " as their target.***\n\n" << std::endl;
        usable.removeMember(charSelected);
    }
    //Now do attack selection.
    usable = party1;

    std::cout << "***ENTERING ACTION SELECTION PHASE!***" << std::endl;

    while(usable.getSize() > 0)
    {
        std::cout << "Enter the number of the character you wish to select\n\n" << std::endl;
        Character * charSelected = usable.select();

        //They want to repick.
        if(charSelected == nullptr)
            continue;

        Action * act = nullptr;

        std::cout << "Enter the number of the action you wish for " << charSelected->getName() << " to perform on " << charSelected->getTarget()->getName() <<"\n\n"<< std::endl;
        act = charSelected->selectAction();

        if(act == nullptr)
            continue;

        std::cout << charSelected->doAction(act) << std::endl;
        usable.removeMember(charSelected);
    }

    std::cout << party1.toString() << std::endl;
    std::cout << party2.toString() << std::endl;

    return 0;
}
