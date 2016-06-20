/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Plateau (Location subclass) implementation file
************************************************************/

#include "Plateau.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Plateau::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Plateau::printDescription()
{
   cout << "\nYou are on a high plateau.\n";
   cout << "There is a cabin here where one of ";
   cout << "El Diablo's henchman hide out. \n";
   cout << "He's known to hoard a large amount of gold.\n\n";
   printMenu();
   cout << "6. Fight the Henchman\n";
}

/************************************************************
 ** Plateau::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Plateau::specialAction(Player* pl)
{
   Character* winner;

   if (!pl->getHasGold())
   {
     winner = pl->combat(&henchman1);
     if (winner == pl)
     {
       pl->setHasGold(true);
       pl->addBagItem("gold");
       return "\nYou defeated the Henchman and got the gold!\n";
     }
     else
     {
       pl->setStrengthPts(5);
       return "\nThe Stranger escapes with only 5 hit points.\n";
     }
   }
   else
     return "\nYou already got the gold!\n";
}
