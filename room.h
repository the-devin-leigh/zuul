#include <iostream>
#include <cstring>

using namespace std;

class Room{
 public:
  Room(char*);
  char* getName();
 private:
  char name[20];
};
