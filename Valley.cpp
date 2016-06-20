/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Valley (Location subclass) implementation file
************************************************************/

#include "Valley.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Valley::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Valley::printDescription()
{
   cout << "\nYou come down into a lush valley.\n";
   cout << "There is a grizzled gun merchant here.\n\n";
   printMenu();
   cout << "6. Buy the Spencer rifle\n";
}

/************************************************************
 ** Valley::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Valley::specialAction(Player* pl)
{
   if (pl->getHasGold())
   {
     pl->setHasGold(false);
     pl->useBagItem("gold");
     pl->setHasGun(true);
     pl->addBagItem("rifle");
     if (pl->getHasBullets())
       return "\nYou bought the Spencer rifle!\nYour attack power has doubled!\n";
     else
       return "\nYou bought the Spencer rifle!\nHowever, you have no bullets ...";
   }
   else
     return "\nYou don't have any gold!\n";
}
