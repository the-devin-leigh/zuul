// item header file

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

class Item{
public:
  Item(char*);
  char* getName();
private:
  char* name;  
};

#endif
