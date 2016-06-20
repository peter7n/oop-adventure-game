/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Plateau (Location subclass)
************************************************************/

#ifndef Plateau_HPP
#define Plateau_HPP

#include "Location.hpp"
#include "Henchman.hpp"
#include "Player.hpp"

class Plateau:public Location
{
  private:
    Henchman henchman1;
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
