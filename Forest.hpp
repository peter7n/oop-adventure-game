/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Forest (Location subclass)
************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Location.hpp"
#include "Player.hpp"

class Forest:public Location
{
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
