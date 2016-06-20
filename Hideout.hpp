/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Hideout (Location subclass)
************************************************************/

#ifndef HIDEOUT_HPP
#define HIDEOUT_HPP

#include "Location.hpp"
#include "Diablo.hpp"
#include "Player.hpp"

class Hideout:public Location
{
  private:
    Diablo diablo1;
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
