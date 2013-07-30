#include "../include/party.h"

Party::Party()
{
    //ctor
}

/*Returns the party as a string on multiple lines
 *EX.)
 * 1. Derpy Hooves
 * 2. Rainbow Dash
 * 3. Twilight Sparkle
 * 4. Doctor Whooves.
*/
std::string Party::toString() const
{
    std::stringstream ss;
    //for(Character * i: members)
    for(unsigned int i = 0; i < members.size(); ++i)
        ss <<" "<< i + 1 << ". " << members[i]->toString() << "\n";
    return ss.str();
}

//Draws a simple menu and prompts the user to select a member.
Character * Party::select()
{
    //Draw the "menu"
    std::cout << "-1. Return to the previous menu..." << std::endl;
    std::cout << toString() << std::endl;

    //Prompt the user for their choice
    int selection = 0;
    do
    {
        std::cout << "Please enter an integer [1, " << members.size() << "]."<<std::endl;
        std::cin >> selection;
    }while((selection < 1 || (unsigned int)selection > members.size()) && selection != -1);

    //They didn't want to be here! Take them back!
    if(selection == -1)
    {
        std::cout << "Returning to previous menu..." << std::endl;
        std::cout << "\n\n\n" << std::endl;
        return NULL;
    }

    //Inform the user of their choice.
    std::cout << "You have selected: " << members[selection-1]->toString() << std::endl;
    std::cout << "\n\n\n" << std::endl;

    return members[selection-1];
}

unsigned int Party::getSize() const
{
    return members.size();
}

void Party::removeMember(Character * toRemove)
{
    //Loop through until equal.
    unsigned int i;
    for(i = 0; i < members.size() && members[i] != toRemove; ++i);

    //Remove the character who has confirmed their selections.
    if(members[i] == toRemove)
        members.erase(members.begin() + i);
    else
        std::cout << "Crisis averted! We almost deleted the wrong member!" << std::endl;
}

void Party::insertMember(Character * toInsert)
{
    members.push_back(toInsert);
}

Party::~Party()
{
    //dtor
}
