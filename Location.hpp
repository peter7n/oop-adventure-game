/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Location abstract base class
************************************************************/

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>
#include "Player.hpp"

class Location
{
   protected:
      Location* north;
      Location* south;
      Location* east;
      Location* west;
   public:
      virtual void printDescription() = 0;
      virtual std::string specialAction(Player*) = 0;
      void printMenu();
      void setNorth(Location*);
      void setSouth(Location*);
      void setEast(Location*);
      void setWest(Location*);
      Location* getNorth();
      Location* getSouth();
      Location* getEast();
      Location* getWest();
};

#endif
