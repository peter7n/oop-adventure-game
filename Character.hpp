/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Header file for Character abstract base class
************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

enum Creature {HENCHMAN, COWBOY, GRIZZLY, DIABLO};

class Character
{
   protected:
      std::string name;
      Creature type;
      int strengthPts;
      int attackDice;
      int attackSides;
      int defenseDice;
      int defenseSides;
      int armor;
      int strengthDefault;
      int tourneyPoints;
   public:
      virtual int attack(Character*) = 0;
      virtual int defense(int) = 0;
      Character* combat(Character*);
      int rollDice(int);
      void heal();
      void setName(std::string);
      void setType(Creature);
      void setStrengthPts(int);
      void setAttackDice(int);
      void setAttackSides(int);
      void setDefenseDice(int);
      void setDefenseSides(int);
      void setArmor(int);
      void setTourneyPts(int);
      std::string getName();
      Creature getType();
      int getStrengthPts();
      int getAttackDice();
      int getAttackSides();
      int getDefenseDice();
      int getDefenseSides();
      int getArmor();
      int getStrengthDef();
      int getTourneyPts();
};

#endif
