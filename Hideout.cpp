/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Hideout (Location subclass) implementation file
************************************************************/

#include "Hideout.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Hideout::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Hideout::printDescription()
{
   cout << "\nYou enter an inner cave.\n";
   cout << "This is the hideout of the notorious mystic ";
   cout << "and killer El Diablo. \n\n";
   printMenu();
   cout << "6. Fight El Diablo\n";
}

/************************************************************
 ** Hideout::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Hideout::specialAction(Player* pl)
{
   Character* winner;

   if (pl->getKilledGrizz())
   {
     winner = pl->combat(&diablo1);
     if (winner == pl)
     {
       pl->setObjectiveMet(true);
       return "\nYou killed El Diablo!\n";
     }
     else
     {
       pl->setStrengthPts(5);
       return "\nThe Stranger escapes with only 5 hit points.\n";
     }
   }
   else
     return "\nYou need to get past the Grizzly first!\n";
}
