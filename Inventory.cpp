/************************************************************
 ** Author: Peter Nguyen
 ** CS162-400, Final project
 ** Date: 6/6/15
 ** Description: Implementation file for Inventory class
************************************************************/

#include "Inventory.hpp"
#include <iostream>
using std::cout;

// Constructor
Inventory::Inventory()
{
  maxItems = 5;
}

/************************************************************
 ** Inventory::addItem
 ** Description: Adds an item to the inventory
 ** Parameters: string itm
************************************************************/
void Inventory::addItem(std::string itm)
{
  if (contents.size() == maxItems)
    cout << "The bag is full.\n";
  else
    contents.push_back(itm);
}

/************************************************************
 ** Inventory::useItem
 ** Description: Finds item and removes it from Inventory.
 ** Returns true if the item was used.
 ** Parameters: string itm
************************************************************/
bool Inventory::useItem(std::string itm)
{
  bool itemFound = false;

  if (contents.empty())
  {
    cout << "The bag is empty.\n";
    return itemFound;
  }
  else
  {
    for (int i = 0; i < contents.size(); i++)
    {
      if (contents[i] == itm)
      {
        contents.erase(contents.begin() + i);
        itemFound = true;
        cout << "You used the " << itm << "\n";
        return itemFound;
      }
    }
    if (!itemFound)
    {
      cout << "You don't have the " << itm << "\n";
      return itemFound;
    }
  }
}

/************************************************************
 ** Inventory::printContents
 ** Description: Prints contents of inventory
 ** Parameters: none
************************************************************/
void Inventory::printContents()
{
  if (contents.empty())
    cout << "The bag is empty.\n";
  else
  {
    cout << "Bag contents:\n";
    for (int i = 0; i < contents.size(); i++)
    {
      cout << contents[i] << "\n";
    }
  }
}
