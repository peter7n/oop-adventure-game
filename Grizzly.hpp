/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Header file for Grizzly subclass
************************************************************/

#ifndef GRIZZLY_HPP
#define GRIZZLY_HPP

#include "Character.hpp"

class Grizzly:public Character
{
   public:
      Grizzly(std::string);
      Grizzly();
      virtual int attack(Character*);
      virtual int defense(int);
};

#endif
