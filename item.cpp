// item c++ file

#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* setName){ //set the name of the item
  name = setName;
}

char* Item::getName(){ //returns item name
  return name;
}
