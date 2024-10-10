#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char* newName);
  Item* getItem();
  char* getName();
 protected:
  char* name;
};
#endif
