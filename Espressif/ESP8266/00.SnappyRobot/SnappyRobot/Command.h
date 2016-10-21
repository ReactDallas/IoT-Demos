#ifndef command_h_
#define command_h_

#include "Robot.h"

#include <queue>
#include <stdio.h>

typedef enum
{
    forward,
    back,
    left,
    right
} Command;

extern std::queue <Command> commands;

void runCommand(Command command);
void addCommand(Command command);
int processCommand(String command);
bool isDoneMoving();

#endif
