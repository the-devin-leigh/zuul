//player header file

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

class Player{
 public:
  Player(Room*); 
  Room* getCurrentRoom();
  vector<Item*>* getItems();
  void setCurrentRoom(Room*);
  void addItem(Item*);
  Item* takeItem(char*);
  void printInventory();
  bool validItem(char*);
  bool keyItem(char*);
private:
  char name[50];
  vector<Item*> items;
  Room* currentRoom;
};
