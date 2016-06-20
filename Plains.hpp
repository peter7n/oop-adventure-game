/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Plains (Location subclass)
************************************************************/

#ifndef PLAINS_HPP
#define PLAINS_HPP

#include "Location.hpp"
#include "Player.hpp"

class Plains:public Location
{
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
