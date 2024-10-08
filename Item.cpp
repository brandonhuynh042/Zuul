#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName) {
  strcpy(name, newName);
}

Item* Item::getItem() {
  return this;
}

void Item::print() {
  cout << name << " ";
}
