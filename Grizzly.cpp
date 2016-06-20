/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Grizzly subclass implementation file
************************************************************/

#include "Grizzly.hpp"

// Constructor definitions
Grizzly::Grizzly(std::string nameSet)
{
   strengthDefault = 18;
   setName(nameSet);
   setType(GRIZZLY);
   setStrengthPts(strengthDefault);
   setAttackDice(3);
   setAttackSides(6);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(7);
}

Grizzly::Grizzly()
{
   strengthDefault = 18;
   setName("Grizzly Bear");
   setType(GRIZZLY);
   setStrengthPts(strengthDefault);
   setAttackDice(3);
   setAttackSides(6);
   setDefenseDice(1);
   setDefenseSides(6);
   setArmor(7);
}

/************************************************************
 ** Grizzly::attack
 ** Description: Generates a dice roll from AttackDice and
 ** AttackSides values and returns an attack value
 ** Parameters: none
 ************************************************************/
int Grizzly::attack(Character* defender)
{
   int attkTotal = 0;   // Reset accumulator

   for (int d = 0; d < getAttackDice(); d++)
   {
      attkTotal += rollDice(getAttackSides());
   }

   return attkTotal;
}

/************************************************************
 ** Grizzly::defense
 ** Description: Generates a dice roll from DefenseDice and
 ** DefenseSides values and returns a final damage value
 ** after subtracting defense values
 ** Parameters: int attkValue
 ************************************************************/
int Grizzly::defense(int attkValue)
{
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
