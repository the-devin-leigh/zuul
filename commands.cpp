#include <iostream>
#include <string.h>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"
#include "commands.h"

using namespace std;

char* Commands::substr(char* str, int start, int end){ //returns section of cstring
  char* sub = new char[end-start+1];
  int x = 0;//counter int
  for(int i = start; i < end; i++){
    sub[x] = str[i];//make characters eaqual
    x++;//add one to the counter
  }
  return sub;
}

bool Commands::processCommand(char* str, Player* player){ //interprets user input
  if(strncmp(str, "go ", 3) == 0){ //if first 3 characters are "go "
    char* direction = substr(str, 3, strlen(str) + 1); //gets the direction by finding the substring after "go "
    if(player->getCurrentRoom()->isValidRoom(direction)){ //finds if the exit exists
      player->setCurrentRoom(player->getCurrentRoom()->getExitRoom(direction)); //changes player current room
      cout << player->getCurrentRoom()->getDescription() << endl; //prints out the description of current room
      delete direction; //deletes the direction char
    }
    else{
      cout << "That is not a valid direction." << endl;
    }
  }
  else if(strncmp(str, "take ", 5) == 0){ //are first 5 char "take "
	char* ItemName = substr(str, 5, strlen(str) + 1); //gets the object name by finding the substring after "take "
	if(player->getCurrentRoom()->validItem(ItemName)){ //checks if the room has the item
		player->addItem(player->getCurrentRoom()->takeItem(ItemName)); //adds it to player and removes it from the room
		cout << "You now have " << ItemName << endl;
	}
	else{
		cout << "Not a valid item." << endl;
	}
  }
  else if(strcmp(str, "help") == 0){ //print out help
	cout << "The commands you can use are \"go\", \"inventory\", \"take\", \"drop\", \"room items\", \"exits\" and \"exit\"" << endl;
  }
  else if(strncmp(str, "drop ", 5) == 0){ //are first 5 char "drop "
	char* ItemName = substr(str, 5, strlen(str) + 1); //gets the object name by finding the substring after "drop "
	if(player->validItem(ItemName)){ //checks if the player has the item
		player->getCurrentRoom()->addItem(player->takeItem(ItemName)); //adds it to the room and removes it from the player
		cout << "You dropped the " << ItemName << endl;
	}
	else{
		cout << "Not a valid item!" << endl;
	}
  }
  else if(strcmp(str, "exits") == 0){ //prints out exits of current room
    player->getCurrentRoom()->getExitDirections();
  }
  else if(strcmp(str, "inventory") == 0){ //prints out inventory
    player->printInventory();
  }
  else if(strcmp(str, "room items") == 0){ //prints out items in current room
    player->getCurrentRoom()->printItems();
  }
  else if(strcmp(player->getCurrentRoom()->getName(), "South Gallery") == 0){ //win condition
    char str[7] = "Hammer"; 
    if(player->keyItem(str) == true){
	  cout << "You smash your way out of the South Gallery window and jump out! You've escaped, but you've also broken both of your legs. Congratulations!" << endl;
	  return false;
	}else{
	  return true;
	}
  }
  else if(strcmp(str, "exit") == 0){//returns false 
	cout << "Thanks for playing." << endl;
    return false;
  }
  else{
	cout << "Not a valid command" << endl;
  }
  return true;
}
