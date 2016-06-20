/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for River (Location subclass)
************************************************************/

#ifndef RIVER_HPP
#define RIVER_HPP

#include "Location.hpp"
#include "Player.hpp"

class River:public Location
{
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
