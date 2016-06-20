/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Assignment 4
 ** Date: 5/22/15
 ** Description: Character abstract class implementation file
************************************************************/

#include "Character.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using std::cout;
using std::string;

/************************************************************
 ** Character::combat
 ** Description: Loops combat between an attacker and
 ** defender until one of them dies; returns the winner
 ** Parameters: Character& defender
************************************************************/
Character* Character::combat(Character* defender)
{
   int damage = 0,       // Damage taken by defender
       attk = 0,         // Attack roll of current attacker
       updateStrPts = 0, // Strength points minus damage
       round = 1;        // Current round

   cout << "\n**************** " << getName() << " vs. ";
   cout << defender->getName() << " ****************\n\n";

   // Loop while attacker and defender are alive
   while ( (getStrengthPts() > 0) &&
           (defender->getStrengthPts() > 0) )
   {
      cout << "- ROUND " << round << " -\n";
      round++;

      // Attacker attacks, update defender's strength points
      attk = attack(defender);

      cout << "> " << getName() << " attacks ";
      cout << defender->getName();
      cout << " (Attack: " << attk << ")\n";

      damage = defender->defense(attk);
      updateStrPts = defender->getStrengthPts() - damage;
      defender->setStrengthPts(updateStrPts);

      cout << defender->getName() << " takes ";
      cout << damage << " damage (" << updateStrPts;
      cout << " strength points remaining)\n\n";

      if (defender->getStrengthPts() > 0)
      {
         // Defender attacks, update attacker's strength points
         attk = defender->attack(defender);

         cout << "> " << defender->getName() << " attacks ";
         cout << getName();
         cout << " (Attack: " << attk << ")\n";

         damage = defense(attk);
         updateStrPts = getStrengthPts() - damage;
         setStrengthPts(updateStrPts);

         cout << getName() << " takes ";
         cout << damage << " damage (" << updateStrPts;
         cout << " strength points remaining)\n\n";
      }
   }

   // Declare and return the winner
   if (defender->getStrengthPts() <= 0)
   {
      cout << "* " << defender->getName() << " is killed!\n";
      cout << "* " << getName() << " wins!\n\n";
      return this;
   }
   else
   {
      cout << "* " << getName() << " is defeated!\n";
      cout << "* " << defender->getName() << " wins!\n\n";
      return defender;
   }
}

/************************************************************
 ** Character::rollDice
 ** Description: Returns a random die roll depending on the
 ** number of sides of the die
 ** Parameters: int numSides
************************************************************/
int Character::rollDice(int numSides)
{
   int roll = 0;
   static int seedIncrement = 0;
   unsigned seed;

   seed = time(0) + seedIncrement++;   // Ensures a different
   srand(seed);                        // seed value each time
                                       // function is called

   roll = rand() % numSides + 1;
   return roll;
}

/************************************************************
 ** Character::heal
 ** Description: Restores 5 strength points
 ** Parameters: none
************************************************************/
void Character::heal()
{
   int restorePoints = 0;
   restorePoints = getStrengthPts() + 5;
   // Cap healing at Character's max strength points
   if (restorePoints > strengthDefault)
      restorePoints = strengthDefault;
   setStrengthPts(restorePoints);
}

/******* Set function definitions *******/

void Character::setName(std::string nme)
{
   name = nme;
}

void Character::setType(Creature tp)
{
   type = tp;
}

void Character::setStrengthPts(int str)
{
   strengthPts = str;
}

void Character::setAttackDice(int attkD)
{
   attackDice = attkD;
}

void Character::setAttackSides(int attkS)
{
   attackSides = attkS;
}

void Character::setDefenseDice(int defD)
{
   defenseDice = defD;
}

void Character::setDefenseSides(int defS)
{
   defenseSides = defS;
}

void Character::setArmor(int arm)
{
   armor = arm;
}

void Character::setTourneyPts(int tp)
{
  tourneyPoints = tp;
}

/******* Get function definitions *******/

std::string Character::getName()
{
   return name;
}

Creature Character::getType()
{
   return type;
}

int Character::getStrengthPts()
{
   return strengthPts;
}

int Character::getAttackDice()
{
   return attackDice;
}

int Character::getAttackSides()
{
   return attackSides;
}

int Character::getDefenseDice()
{
   return defenseDice;
}

int Character::getDefenseSides()
{
   return defenseSides;
}

int Character::getArmor()
{
   return armor;
}

int Character::getStrengthDef()
{
   return strengthDefault;
}

int Character::getTourneyPts()
{
  return tourneyPoints;
}
