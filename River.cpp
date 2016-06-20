/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: River (Location subclass) implementation file
************************************************************/

#include "River.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::string;

/************************************************************
 ** River::printDescription
 ** Description: Prints description of the Location
 ** Parameters: none
************************************************************/
void River::printDescription()
{
   cout << "\nYou are in a lush green forest.\n";
   cout << "There is a river here teaming with fish.\n\n";
   printMenu();
   cout << "6. Try to catch some fish\n";
}

/************************************************************
 ** River::specialAction
 ** Description: Performs special action for the location
 ** Parameters: none
************************************************************/
string River::specialAction(Player* pl)
{
  int roll = 0;
  static int seedIncrement = 0;
  unsigned seed;
  seed = time(0) + seedIncrement++;   // Ensures a different
  srand(seed);                        // seed value each time
                                      // function is called
  roll = rand() % 4 + 1;
  if (roll == 4)
  {
    pl->addBagItem("fish");
    return "\nYou caught a fish!\n";
  }
  else
    return "\nYou didn't catch anything ...\n";
}
