#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

Room* list[15];
vector<Room*> vector;

int main(){
  list[0] = new Room(new char*("First"));
  vector.push_back(list[0]);
}
