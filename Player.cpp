/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Player (Character subclass) implementation file
************************************************************/

#include "Player.hpp"
#include "Location.hpp"
#include "Inventory.hpp"
#include <iostream>
using std::cout;
using std::cin;

// Constructor definitions
Player::Player(std::string nameSet)
{
   strengthDefault = 14;
   setName(nameSet);
   setType(COWBOY);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(6);
   setDefenseDice(2);
   setDefenseSides(6);
   setArmor(0);
}

Player::Player()
{
   strengthDefault = 14;
   setName("The Stranger");
   setType(COWBOY);
   setStrengthPts(strengthDefault);
   setAttackDice(2);
   setAttackSides(6);
   setDefenseDice(2);
   setDefenseSides(6);
   setArmor(0);
}

/************************************************************
 ** Player::action
 ** Description:
 ** Parameters: none
************************************************************/
void Player::action()
{
  int choice;
  char bagChoice;
  Character* winner;

  // Print Location description & menu options
  getPlayerLoc()->printDescription();

  // Get input
  cout << "Enter your choice: ";
  cin >> choice;

  switch(choice)
  {
    // Reveal secret goal of the game (for grader)
    case 0:
      cout << "\n**** GOAL OF THE GAME ****\n";
      cout << "MAIN OBJECTIVE: Fight and beat El Diablo\n";
      cout << "SECONDARY OBJECTIVES:\n";
      cout << "- At the plateau, fight the Henchman to get gold\n";
      cout << "- In the valley, buy the rifle with the gold\n";
      cout << "- At the mine, find bullets\n";
      cout << "- At the river, catch some fish\n";
      cout << "- Fish recovers 5 hit points\n";
      cout << "- Having both gun and bullets doubles attack\n";
      cout << "- Beat the Grizzly to reach El Diablo\n";
      cout << "- There is a time limit of 60 turns\n";
      cout << "**************************\n\n";
      break;

    // Move North
    case 1:
      if (getPlayerLoc()->getNorth() != NULL)
        setPlayerLoc(getPlayerLoc()->getNorth());
      else
      {
        cout << "\n**** You can't go that way ****\n";
        cout << "The treacherous desert prevents you ...\n";
      }
      break;

    // Move South
    case 2:
      if (getPlayerLoc()->getSouth() != NULL)
        setPlayerLoc(getPlayerLoc()->getSouth());
      else
      {
        cout << "\n**** You can't go that way ****\n";
        cout << "The treacherous desert prevents you ...\n";
      }
      break;

    // Move East
    case 3:
      if (getPlayerLoc()->getEast() != NULL)
        setPlayerLoc(getPlayerLoc()->getEast());
      else
      {
        cout << "\n**** You can't go that way ****\n";
        cout << "The treacherous desert prevents you ...\n";
      }
      break;

    // Move West
    case 4:
      if (getPlayerLoc()->getWest() != NULL)
        setPlayerLoc(getPlayerLoc()->getWest());
      else
      {
        cout << "\n**** You can't go that way ****\n";
        cout << "The treacherous desert prevents you ...\n";
      }
      break;

    // Heal
    case 5:
      if (bag.useItem("fish"))
      {
        heal();
        cout << "You recovered 5 hit points!\n";
        cout << "Current hit points: ";
        cout << getStrengthPts() << "\n\n";
        bag.printContents();
      }
      break;

    // Special action
    case 6:
      cout << getPlayerLoc()->specialAction(this) << "\n";
      if (!getObjectiveMet())
      {
        cout << "Current hit points: ";
        cout << getStrengthPts() << "\n";
        bag.printContents();
      }
      break;

    default:
      cout << "Invalid choice.\n\n";
  }
}

/******* Accesses bag functions *******/

void Player::addBagItem(std::string itm)
{
  bag.addItem(itm);
}

void Player::useBagItem(std::string itm)
{
  bag.useItem(itm);
}

/******* Set function definitions *******/

void Player::setPlayerLoc(Location* loc)
{
  playerLocation = loc;
}

void Player::setHasGold(bool hgd)
{
  hasGold = hgd;
}

void Player::setHasGun(bool hg)
{
  hasGun = hg;
}

void Player::setHasBullets(bool hb)
{
  hasBullets = hb;
}

void Player::setKilledGrizz(bool kg)
{
  killedGrizz = kg;
}

void Player::setObjectiveMet(bool objmet)
{
  objectiveMet = objmet;
}

/******* Get function definitions *******/

Location* Player::getPlayerLoc()
{
  return playerLocation;
}

bool Player::getHasGold()
{
  return hasGold;
}

bool Player::getHasGun()
{
  return hasGun;
}

bool Player::getHasBullets()
{
  return hasBullets;
}

bool Player::getKilledGrizz()
{
  return killedGrizz;
}

bool Player::getObjectiveMet()
{
  return objectiveMet;
}

/************************************************************
 ** Player::attack
 ** Description: Generates a dice roll from AttackDice and
 ** AttackSides values and returns an attack value
 ** Parameters: none
 ************************************************************/
int Player::attack(Character* defender)
{
   int attkTotal = 0;   // Reset accumulator

   for (int d = 0; d < getAttackDice(); d++)
   {
      attkTotal += rollDice(getAttackSides());
   }
   // If player has gun & bullets, double attack
   if (getHasGun() && getHasBullets())
      attkTotal = attkTotal * 2;

   return attkTotal;
}

/************************************************************
 ** Player::defense
 ** Description: Generates a dice roll from DefenseDice and
 ** DefenseSides values and returns a final damage value
 ** after subtracting defense values
 ** Parameters: int attkValue
 ************************************************************/
int Player::defense(int attkValue)
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
