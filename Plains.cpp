/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Plains (Location subclass) implementation file
************************************************************/

#include "Plains.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Plains::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Plains::printDescription()
{
   cout << "\nYou are on a vast and bleak plain.\n";
   cout << "It's a desolate place devoid of life.\n\n";
   printMenu();
}

/************************************************************
 ** Plains::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Plains::specialAction(Player* pl)
{
   return "\nYou can't do that.\n";
}
