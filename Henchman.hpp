/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Header file for Henchman subclass
************************************************************/

#ifndef HENCHMAN_HPP
#define HENCHMAN_HPP

#include "Character.hpp"

class Henchman:public Character
{
   private:
      bool achilles; // Flag for achilles special attack
   public:
      Henchman(std::string);
      Henchman();
      virtual int attack(Character*);
      virtual int defense(int);
      void setAchilles(bool);
      bool getAchilles();
};

#endif
