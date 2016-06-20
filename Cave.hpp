/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Cave (Location subclass)
************************************************************/

#ifndef CAVE_HPP
#define CAVE_HPP

#include "Location.hpp"
#include "Grizzly.hpp"
#include "Player.hpp"

class Cave:public Location
{
  private:
    Grizzly grizzly1;
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
