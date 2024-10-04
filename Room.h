#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  Room(char* newDescription);
  void setExit(char* newDirection, Room* newRoom);
  void printExits();
  void printDescription();
  Room* getExit(char* direction);
 protected:
  char* description;
  map<char*, Room*> exits;
};

#endif
