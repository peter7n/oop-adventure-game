/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Valley (Location subclass)
************************************************************/

#ifndef VALLEY_HPP
#define VALLEY_HPP

#include "Location.hpp"
#include "Player.hpp"

class Valley:public Location
{
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
