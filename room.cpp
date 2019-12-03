//room c++ file
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room(){
}

char* Room::getName(){ //returns name of room
  return name;
}

char* Room::getDescription(){ //returns description of room
  return description;
}

vector<Item*>* Room::getItems(){ //returns the item vector
  return &items;	
}

map<const char*, Room*>* Room::getExits(){ //returns whole map of exits
  return &exits;
}

bool Room::isValidRoom(char* room){ //returns true if the room is the same as the input string
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){ //it->first gets the map key
      return true;
    }
  }
}

Room* Room::getExitRoom(char* room){ //returns the exit room pointer 
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){
      return it->second;
    }
  }
  return 0; 
}

void Room::getExitDirections(){ //prints out possible directions
  int i = 0;
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(i == 0){
		cout << it->first;
		i++;
	}
	else{
		cout << ", " << it->first;
	}
  }
  cout << endl;
}

void Room::addItem(Item* item){ //adds item to the room (if dropped)
  items.push_back(item);
}

bool Room::validItem(char* itemName){ //checks if the item exists in current room
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  return true;
    }
  }
  return false;
}

void Room::printItems(){ //lists items in room
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}


Item* Room::takeItem(char* itemName){ //returns item and removes the item from the room vector
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  Item* i = (*it);
	  it:items.erase(it);
	  return (i);
    }
  }
  return NULL;
}
