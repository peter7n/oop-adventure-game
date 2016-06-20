/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Forest (Location subclass) implementation file
************************************************************/

#include "Forest.hpp"
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Forest::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Forest::printDescription()
{
   cout << "\nYou are in a lush green forest.\n";
   cout << "It appears a large animal has been here.\n\n";
   printMenu();
}

/************************************************************
 ** Forest::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Forest::specialAction(Player* pl)
{
   return "\nYou can't do that.\n";
}
