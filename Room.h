#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"
using namespace std;

class Room {
 public:
  Room(char* newDescription);
  void setExit(char* newDirection, Room* newRoom);
  void printExits();
  void printDescription();
  Room* getExit(char* direction);
  void addItem(Item* newItem);
  void printItems();
  int getItemAmount();
  bool hasItem(char* itemName);
  Item* getItem(char* itemName);
 protected:
  char* description;
  vector<Item*> roomItems; 
  map<char*, Room*> exits;
};

#endif
