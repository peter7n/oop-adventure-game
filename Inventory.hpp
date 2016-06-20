/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Header file for Inventory class
************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>

class Inventory
{
  private:
    int maxItems;
    std::vector<std::string> contents;
  public:
    Inventory();
    void addItem(std::string);
    bool useItem(std::string);
    void printContents();
};

#endif
