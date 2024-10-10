#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName) {
  name = new char[60];
  strcpy(name, newName);
}

Item* Item::getItem() {
  return this;
}

char* Item::getName() {
  return name;
}
