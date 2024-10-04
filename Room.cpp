#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

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
