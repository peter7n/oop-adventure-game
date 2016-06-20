/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Mine (Location subclass)
************************************************************/

#ifndef MINE_HPP
#define MINE_HPP

#include "Location.hpp"
#include "Player.hpp"

class Mine:public Location
{
  public:
    virtual void printDescription();
    virtual std::string specialAction(Player*);
};

#endif
