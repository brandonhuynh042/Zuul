#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

Room::Room(char* newDescription) {
  description = new char[60];
  strcpy(description, newDescription);
  
}

// Inserts a given pair of exit direction and room that it leads to
void Room::setExit(char* direction, Room* newRoom) {
  pair<char*, Room*> newExit(direction, newRoom);
  exits.insert(newExit);
}

void Room::printDescription() {
  cout << description << endl;
}
// Given the direction key, return the room it leads to
Room* Room::getExit(char* direction) {
  for (map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); ++it) {  
    if (strcmp(direction, it->first) == 0) {
      return it->second;
    }
  }
  // this would be if it doesn't find anything - returns itsself, keeping them in the same room
  return this;
}
void Room::printExits() {
  for (map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); ++it) {
    cout << it->first << " ";
  }
  cout << '\n';
}

void Room::addItem(Item* newItem) {
  roomItems.push_back(newItem);
}
void Room::printItems() {
   for (vector<Item*>:: iterator it = roomItems.begin(); it != roomItems.end(); ++it) {
     cout << (*it)->getName() <<  " ";
   }
}

int Room::getItemAmount() {
  return roomItems.size();
}

// traverses through the room to see if it has a specific item
bool Room::hasItem(char* itemName) {
  for (vector<Item*>:: iterator it = roomItems.begin(); it != roomItems.end(); ++it) {
    if (strcmp(itemName, (*it)->getName()) == 0) {
      return true;
    }
  }
  return false;
}

//returns a specific item
Item* Room::getItem(char* itemName) {
   for (vector<Item*>:: iterator it = roomItems.begin(); it != roomItems.end(); ++it) {
    if (strcmp(itemName, (*it)->getName()) == 0) {
      Item* returnItem = *it;
      roomItems.erase(it);
      return returnItem;
    }
  }
  return nullptr;
}
