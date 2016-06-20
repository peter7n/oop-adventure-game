/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Diablo subclass implementation file
************************************************************/

#include "Diablo.hpp"
#include <iostream>

// Constructor definitions
Diablo::Diablo(std::string nameSet)
{
   strengthDefault = 12;
   setName(nameSet);
   setType(DIABLO);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(10);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(0);
}

Diablo::Diablo()
{
   strengthDefault = 12;
   setName("El Diablo");
   setType(DIABLO);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(10);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(0);
}

/************************************************************
 ** Diablo::attack
 ** Description: Generates a dice roll from AttackDice and
 ** AttackSides values and returns an attack value
 ** Parameters: none
 ************************************************************/
int Diablo::attack(Character* defender)
{
   int attkTotal = 0;   // Reset accumulator

   for (int d = 0; d < getAttackDice(); d++)
   {
      attkTotal += rollDice(getAttackSides());
   }

   return attkTotal;
}

/************************************************************
 ** Diablo::defense
 ** Description: Generates a dice roll from DefenseDice and
 ** DefenseSides values and returns a final damage value
 ** after subtracting defense values. 50% chance that Diablo
 ** evades attack and takes no damage.
 ** Parameters: int attkValue
 ************************************************************/
int Diablo::defense(int attkValue)
{
   int defenseTotal = 0,   // Reset accumulator
       attkFinal = 0;

   // 50% chance for Special defense; return 0 damage
   if (rollDice(2) == 1)
   {
      std::cout << getName() << " vanished! No damage taken!\n";
      return 0;
   }

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
