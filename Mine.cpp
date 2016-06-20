/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Mine (Location subclass) implementation file
************************************************************/

#include "Mine.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::string;

/************************************************************
 ** Mine::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void Mine::printDescription()
{
   cout << "\nYou are in a decrepit old mine.\n";
   cout << "There are old munitions and bullets laying about.\n\n";
   printMenu();
   cout << "6. Search the area\n";
}

/************************************************************
 ** Mine::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string Mine::specialAction(Player* pl)
{
  int roll = 0;
  static int seedIncrement = 0;
  unsigned seed;
  seed = time(0) + seedIncrement++;   // Ensures a different
  srand(seed);                        // seed value each time
                                      // function is called
  roll = rand() % 2 + 1;
  if (roll == 2 && !pl->getHasBullets())
  {
    pl->addBagItem("bullets");
    pl->setHasBullets(true);
    if (pl->getHasGun())
      return "\nYou found some bullets!\nYour attack power has now doubled!\n";
    else
      return "\nYou found some bullets!\n";
  }
  else
    return "\nYou didn't find anything ...\n";
}
