/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Player (Character subclass)
************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Inventory.hpp"

class Location;

class Player:public Character
{
  private:
    Inventory bag;
    Location* playerLocation;
    bool hasGold;
    bool hasGun;
    bool hasBullets;
    bool killedGrizz;
    bool objectiveMet;

  public:
    Player(std::string);
    Player();
    virtual int attack(Character*);
    virtual int defense(int);
    void action();
    void setPlayerLoc(Location*);
    void setHasGold(bool);
    void setHasGun(bool);
    void setHasBullets(bool);
    void setKilledGrizz(bool);
    void setObjectiveMet(bool);
    Location* getPlayerLoc();
    bool getHasGold();
    bool getHasGun();
    bool getHasBullets();
    bool getKilledGrizz();
    bool getObjectiveMet();
    void addBagItem(std::string);
    void useBagItem(std::string);
};

#endif
