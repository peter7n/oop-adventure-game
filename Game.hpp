/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Game class
************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Plains.hpp"
#include "Plateau.hpp"
#include "Valley.hpp"
#include "Forest.hpp"
#include "River.hpp"
#include "Mine.hpp"
#include "Cave.hpp"
#include "Hideout.hpp"
#include "Player.hpp"

class Game
{
  private:
    Plains plains1;
    Plains plains2;
    Plains plains3;
    Plateau plateau1;
    Valley valley1;
    Forest forest1;
    River river1;
    Mine mine1;
    Cave cave1;
    Hideout hideout1;
    Player you;
    int clock;
  public:
    Game();
    void play();
    void setClock(int);
    int getClock();
};

#endif
