/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Game class implementation file
************************************************************/

#include "Game.hpp"
#include <iostream>

// Constructor
Game::Game()
{
  // Define pointers for the 10 Locations
  plains1.setNorth(NULL);
  plains1.setSouth(NULL);
  plains1.setEast(NULL);
  plains1.setWest(&plains2);

  plains2.setNorth(NULL);
  plains2.setSouth(NULL);
  plains2.setEast(NULL);
  plains2.setWest(&plateau1);

  plateau1.setNorth(&plains3);
  plateau1.setSouth(NULL);
  plateau1.setEast(&plains2);
  plateau1.setWest(NULL);

  plains3.setNorth(&forest1);
  plains3.setSouth(&plateau1);
  plains3.setEast(NULL);
  plains3.setWest(&valley1);

  valley1.setNorth(NULL);
  valley1.setSouth(NULL);
  valley1.setEast(&plains3);
  valley1.setWest(NULL);

  forest1.setNorth(&cave1);
  forest1.setSouth(&plains3);
  forest1.setEast(&river1);
  forest1.setWest(NULL);

  river1.setNorth(&mine1);
  river1.setSouth(NULL);
  river1.setEast(NULL);
  river1.setWest(&forest1);

  mine1.setNorth(NULL);
  mine1.setSouth(&river1);
  mine1.setEast(NULL);
  mine1.setWest(&cave1);

  cave1.setNorth(NULL);
  cave1.setSouth(&forest1);
  cave1.setEast(&mine1);
  cave1.setWest(&hideout1);

  hideout1.setNorth(NULL);
  hideout1.setSouth(NULL);
  hideout1.setEast(&cave1);
  hideout1.setWest(NULL);

  // Initialize player location, flags and clock
  you.setPlayerLoc(&plains1);
  you.setHasGold(false);
  you.setHasGun(false);
  you.setHasBullets(false);
  you.setKilledGrizz(false);
  you.setObjectiveMet(false);
  setClock(0);
}

// Set and get functions
void Game::setClock(int time)
{
  clock = time;
}

int Game::getClock()
{
  return clock;
}

/************************************************************
 ** Game::play
 ** Description: Plays the game & displays results
 ** Parameters: none
************************************************************/
void Game::play()
{
  // Play while the objective is not met, player has not
  // been killed or time limit is reached
  while (!you.getObjectiveMet() && (getClock() != 60))
  {
    you.action();
    setClock(getClock() + 1);
  }

  if (you.getObjectiveMet())
  {
    std::cout << "\nCongratulations! You beat El Diablo ";
    std::cout << "and rescued the girl!\n";
  }
  else if (getClock() == 60)
  {
    std::cout << "\nYou ran out of time!\n";
    std::cout << "El Diablo killed the girl!\n";
  }
}
