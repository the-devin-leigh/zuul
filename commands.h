//command interpreter header file

#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

class Commands{
 public:
  bool processCommand(char*, Player*); //reads/processes user inputed commands
 private:
  char* substr(char*, int, int); //returns section of input string
};

#endif
