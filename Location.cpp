/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Location abstract class implementation file
************************************************************/

#include "Location.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;


/************************************************************
 ** Plains::printMenu
 ** Description: Prints the standard menu
 ** Parameters: none
************************************************************/
void Location::printMenu()
{
  cout << "What do you want to do?\n";
  cout << "0. (Reveal goal of the game)\n";
  cout << "1. Move north\n";
  cout << "2. Move south\n";
  cout << "3. Move east\n";
  cout << "4. Move west\n";
  cout << "5. Recover strength (Fish required)\n";
}

/******* Set function definitions *******/

void Location::setNorth(Location* loc)
{
   north = loc;
}

void Location::setSouth(Location* loc)
{
   south = loc;
}

void Location::setEast(Location* loc)
{
   east = loc;
}

void Location::setWest(Location* loc)
{
   west = loc;
}

/******* Get function definitions *******/

Location* Location::getNorth()
{
  return north;
}

Location* Location::getSouth()
{
  return south;
}

Location* Location::getEast()
{
  return east;
}

Location* Location::getWest()
{
  return west;
}
