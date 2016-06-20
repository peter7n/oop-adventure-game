/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Henchman subclass implementation file
************************************************************/

#include "Henchman.hpp"
#include <iostream>

// Constructor definitions

Henchman::Henchman(std::string nameSet)
{
   strengthDefault = 8;
   setName(nameSet);
   setType(HENCHMAN);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(6);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(3);
   setAchilles(false);
}

Henchman::Henchman()
{
   strengthDefault = 8;
   setName("Henchman");
   setType(HENCHMAN);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(6);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(3);
   setAchilles(false);
}

/******** Set and get function definitions ********/

void Henchman::setAchilles(bool ach)
{
   achilles = ach;
}

bool Henchman::getAchilles()
{
   return achilles;
}

/************************************************************
 ** Henchman::attack
 ** Description: Generates a dice roll from AttackDice and
 ** AttackSides values and returns an attack value.
 ** If a 12 is rolled, the achilles attack is successful
 ** Parameters: Character& defender
 ************************************************************/
int Henchman::attack(Character* defender)
{
   int attkTotal = 0;   // Reset accumulator

   for (int d = 0; d < getAttackDice(); d++)
   {
      attkTotal += rollDice(getAttackSides());
   }

   // Achilles attack successful if 12 is rolled and defender
   // is not another Henchman
   if (attkTotal == 12 && defender->getType() != HENCHMAN)
      setAchilles(true);

   return attkTotal;
}

/************************************************************
 ** Henchman::defense
 ** Description: Generates a dice roll from DefenseDice and
 ** DefenseSides values and returns a final damage value
 ** after subtracting defense values. If achilles attack
 ** is successful, damage is halved.
 ** Parameters: int attkValue
 ************************************************************/
int Henchman::defense(int attkValue)
{
   if (getAchilles())  // Achilles attack is succesful
   {
      attkValue = (attkValue / 2);
      std::cout << "Damage is halved!\n";
   }

   int defenseTotal = 0,   // Reset accumulator
       attkFinal = 0;

   for (int d = 0; d < getDefenseDice(); d++)
   {
      defenseTotal += rollDice(getDefenseSides());
   }

   attkFinal = attkValue - defenseTotal - getArmor();

   if (attkFinal < 0)   // Don't allow negative attack values
      return 0;
   else
      return attkFinal;
}
