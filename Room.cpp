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

void Room::setExit(char* direction, Room* newRoom) {
  pair<char*, Room*> newExit(direction, newRoom);
  exits.insert(newExit);
}
void Room::printDescription() {
  cout << description << endl;
}
Room* Room::getExit(char* direction) {
  for (map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); ++it) {  
    if (strcmp(direction, it->first) == 0) {
      return it->second;
    }
  }
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
     cout << (*it)->getName() << " ";
   }
}

int Room::getItemAmount() {
  return roomItems.size();
}

bool Room::hasItem(char* itemName) {
  for (vector<Item*>:: iterator it = roomItems.begin(); it != roomItems.end(); ++it) {
    if (strcmp(itemName, (*it)->getName()) == 0) {
      return true;
    }
  }
  return false;
}

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
