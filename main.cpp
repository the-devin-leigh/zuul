/*Author: Devin Leigh
  Project: Zuul Game - text based adventure
  Date: 12/2/2019

 */

#include <iostream>
#include <cstring>
#include "room.h"
#include "player.h"
#include "commands.h"

using namespace std;

int main()
{
  //initialization of variables
  Commands c; //creating a new commands object to use command functions
  char str[50]; //input variable
  bool running = true; //quit condition
  //objective
  cout << "You walk into an abandoned mansion. Don't ask me how you got here. The large double doors slam behind you." << endl;
  cout << "You have to get out! Figure it out yourself, I still dont know how you ended up here." << endl << "The commands are \"go\", \"inventory\", \"take\", \"drop\", \"room items\", \"exits\" and \"exit\"" << endl;
  //Room creation
  Room* room1 = new Room(); //creates new room
  strcpy(room1->getName(), "Entryway"); //changes room name
  strcpy(room1->getDescription(), "The high ceiling soars above you as the boom of the doors shutting still echoes. You feel despair."); //sets description of room
  Room* room2 = new Room();
  strcpy(room2->getName(), "Hallway 1");
  strcpy(room2->getDescription(), "Just a hallway, nothing special here.");
  Room* room3 = new Room();
  strcpy(room3->getName(), "Great Hall 1");
  strcpy(room3->getDescription(), "A huge great hall. You can barely see the end, it's so large.");
  Room* room4 = new Room();
  strcpy(room4->getName(), "Grand Ballroom");
  strcpy(room4->getDescription(), "Shiny chandeliers blind you and you see the once-gaudy decor on the walls. I bet there were some pretty crazy dance parties in here.");
  Room* room5 = new Room();
  strcpy(room5->getName(), "Great Hall 2");
  strcpy(room5->getDescription(), "The great hall is still huge. It feels like you'll be walking through the great hall forever.");
  Room* room6 = new Room();
  strcpy(room6->getName(), "Great Hall 3");
  strcpy(room6->getDescription(), "Still in the great hall... There is a door to the south.");
  Room* room7 = new Room();
  strcpy(room7->getName(), "Great Hall 4");
  strcpy(room7->getDescription(), "Finally you can see some rooms beyond the reaches of the great hall. They're up a few flights of stairs, though.");
  Room* room8 = new Room();
  strcpy(room8->getName(), "Banquet Hall");
  strcpy(room8->getDescription(), "You step into a fancy looking banquet hall. There's still some dusty utensils and rancid food on the tables.");
  Room* room9 = new Room();
  strcpy(room9->getName(), "North Gallery");
  strcpy(room9->getDescription(), "It's a small room with windows. All these windows are strongly secured, though. If you're going to open them you'll need a tool.");
  Room* room10 = new Room();
  strcpy(room10->getName(), "Foyer");
  strcpy(room10->getDescription(), "It's a foyer that has a door to a garden outside. Pretty boring.");
  Room* room11 = new Room();
  strcpy(room11->getName(), "Armor Room");
  strcpy(room11->getDescription(), "This family must have had some enemies. There is a wall of swords here across from a wall of bows.");
  Room* room12 = new Room();
  strcpy(room12->getName(), "Storage Room");
  strcpy(room12->getDescription(), "This room is full of tools. They're all rusty, though.");
  Room* room13 = new Room();
  strcpy(room13->getName(), "Hallway 2");
  strcpy(room13->getDescription(), "Yet another boring hallway.");
  Room* room14 = new Room();
  strcpy(room14->getName(), "Stairwell");
  strcpy(room14->getDescription(), "A narrow stairwell beckons you. It's one of those ancient spiralling ones.");
  Room* room15 = new Room();
  strcpy(room15->getName(), "South Gallery");
  strcpy(room15->getDescription(), "A fully windowed room. The windows look breakable. You can see your surroundings. The mansion is in the middle of a vast forest. If you think you can interact with the windows, press enter.");
  Room* room16 = new Room();
  strcpy(room16->getName(), "Garden");
  strcpy(room16->getDescription(), "Tall hedges line a barren garden. You're not escaping through here.");
    
  //Room exits
  room1->getExits()->insert(pair<const char*, Room*>("north", room2)); //setting exits in vector for each room
  room2->getExits()->insert(pair<const char*, Room*>("north", room3));
  room2->getExits()->insert(pair<const char*, Room*>("east", room13));
  room2->getExits()->insert(pair<const char*, Room*>("south", room1));
  room3->getExits()->insert(pair<const char*, Room*>("north", room4));
  room3->getExits()->insert(pair<const char*, Room*>("east", room5));
  room3->getExits()->insert(pair<const char*, Room*>("south", room2));
  room4->getExits()->insert(pair<const char*, Room*>("southwest", room3));
  room4->getExits()->insert(pair<const char*, Room*>("southeast", room5));
  room4->getExits()->insert(pair<const char*, Room*>("east", room11));
  room5->getExits()->insert(pair<const char*, Room*>("north", room4));
  room5->getExits()->insert(pair<const char*, Room*>("west", room3));
  room5->getExits()->insert(pair<const char*, Room*>("east", room6));
  room6->getExits()->insert(pair<const char*, Room*>("west", room5));
  room6->getExits()->insert(pair<const char*, Room*>("south", room13));
  room6->getExits()->insert(pair<const char*, Room*>("east", room7));
  room7->getExits()->insert(pair<const char*, Room*>("north", room10));
  room7->getExits()->insert(pair<const char*, Room*>("west", room6));
  room7->getExits()->insert(pair<const char*, Room*>("south", room12));
  room7->getExits()->insert(pair<const char*, Room*>("east", room8));
  room8->getExits()->insert(pair<const char*, Room*>("north", room9));
  room8->getExits()->insert(pair<const char*, Room*>("west", room7));
  room8->getExits()->insert(pair<const char*, Room*>("south", room15));
  room9->getExits()->insert(pair<const char*, Room*>("west", room10));
  room9->getExits()->insert(pair<const char*, Room*>("south", room8));
  room10->getExits()->insert(pair<const char*, Room*>("north", room16));
  room10->getExits()->insert(pair<const char*, Room*>("west", room11));
  room10->getExits()->insert(pair<const char*, Room*>("south", room7));
  room10->getExits()->insert(pair<const char*, Room*>("east", room9));
  room11->getExits()->insert(pair<const char*, Room*>("west", room4));
  room11->getExits()->insert(pair<const char*, Room*>("east", room10));
  room12->getExits()->insert(pair<const char*, Room*>("north", room7));
  room13->getExits()->insert(pair<const char*, Room*>("north", room6));
  room13->getExits()->insert(pair<const char*, Room*>("west", room2));
  room13->getExits()->insert(pair<const char*, Room*>("south", room14));
  room14->getExits()->insert(pair<const char*, Room*>("north", room13));
  room14->getExits()->insert(pair<const char*, Room*>("east", room15));
  room15->getExits()->insert(pair<const char*, Room*>("north", room8));
  room15->getExits()->insert(pair<const char*, Room*>("west", room14));
  
  Player* p = new Player(room1); //creating player in starting room
  
  //Items
  //win condition item
  Item* hammer = new Item((char*)"Hammer"); //new item "hammer", etc.
  room12->addItem(hammer);
  //normal items
  Item* fork = new Item((char*)"Fork");
  room8->addItem(fork);
  Item* spoon = new Item((char*)"Spoon");
  room8->addItem(spoon);
  Item* sword = new Item((char*)"Sword");
  room11->addItem(sword);
  Item* flower = new Item((char*)"Dead Flower");
  room16->addItem(flower);
  Item* tux = new Item((char*)"Tuxedo");
  room4->addItem(tux);
  
  while(running){ //run loop
    cin.get(str, 50); //gets input string
    cin.clear();
    cin.ignore(10000, '\n');
    running = c.processCommand(str, p); //if the command returns false running becomes false
  }
  return 0;//exits program
}
