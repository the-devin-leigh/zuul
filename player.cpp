// player c++ file

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(Room* startRoom){
  currentRoom = startRoom; //sets input to startRoom
}

Room* Player::getCurrentRoom(){ //returns current room
  return currentRoom;	
}

vector<Item*>* Player::getItems(){ //returns the address of obtained items
  return &items;	
}

void Player::setCurrentRoom(Room* newRoom){ //allows you to change the room (move)
  currentRoom = newRoom;
}

void Player::addItem(Item* item){ //adds item to player items
  items.push_back(item);
}

Item* Player::takeItem(char* itemName){ //removes taken item from room item vector
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
      Item* i = (*it);
	  it = items.erase(it); //prevents segmentation fault
	  return (i);
    }
  }
  return 0;
}

bool Player::validItem(char* itemName){ //checks if item requested exists
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  return true;
    }
  }
  return false;
}

bool Player::keyItem(char* itemName){ //checks if player has key item
  const char* str[7] = {"Hammer"}; //main item
  for(int i = 0; i < 5; i++){
    if(strcmp(str[i], itemName) == 0){
	  return true;
    }
  }
  return false;
}


void Player::printInventory(){ //prints out items in inventory
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << "\"" << (*it)->getName() << "\"" << " ";
  }
  cout << endl;
}
