/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Cave (Location subclass) implementation file
************************************************************/

#include "Cave.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Cave::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Cave::printDescription()
{
   cout << "\nYou enter a dark and smelly cave.\n";
   cout << "You can smell the presence of a ";
   cout << "large grizzly bear. \n\n";
   printMenu();
   cout << "6. Fight the grizzly bear\n";
}

/************************************************************
 ** Cave::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Cave::specialAction(Player* pl)
{
   Character* winner;

   winner = pl->combat(&grizzly1);
   if (winner == pl)
   {
     pl->setKilledGrizz(true);
     return "\nYou killed the Grizzly!\n";
   }
   else
   {
     pl->setStrengthPts(5);
     return "\nThe Stranger escapes with only 5 hit points.\n";
   }
}
