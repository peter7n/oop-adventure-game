/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Header file for Diablo subclass
************************************************************/

#ifndef DIABLO_HPP
#define DIABLO_HPP

#include "Character.hpp"

class Diablo:public Character
{
   public:
      Diablo(std::string);
      Diablo();
      virtual int attack(Character*);
      virtual int defense(int);
};

#endif
