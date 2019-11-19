#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

Room::Room(char* newName){
  name = newName;
}

char* Room::getName(){
  return name;
}
