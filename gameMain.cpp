/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Main method for adventure game project
************************************************************/

#include "Game.hpp"
#include <iostream>
using std::cout;

int main()
{
  cout << "\n\nYou are The Stranger, a legendary gun for hire.\n";
  cout << "The feared killer and mystic El Diablo has\n";
  cout << "escaped prison and is hiding in parts unknown.\n";
  cout << "He is holding a girl hostage...\n";
  cout << "Time is running out...\n\n";

  Game adventure;
  adventure.play();

  cout << "Thanks for playing!\n";
  return 0;
}
