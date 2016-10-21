#include "Command.h"

#include <queue>
#include <stdio.h>

std::queue <Command> commands;

void runCommand(Command command)
{
    switch(command)
    {
        case forward:
            stepperLeft.move(5000);
            stepperRight.move(5000);
            break;
        case back:
            stepperLeft.move(-5000);
            stepperRight.move(-5000);
            break;
        case left:
            stepperLeft.move(-TURN_ACTION_STEPS);
            stepperRight.move(TURN_ACTION_STEPS);
            break;
        case right:
            stepperLeft.move(TURN_ACTION_STEPS);
            stepperRight.move(-TURN_ACTION_STEPS);
            break;
    }
}

void addCommand(Command command)
{
    commands.push(command);
}

bool isDoneMoving()
{
    return stepperLeft.distanceToGo() == 0 && stepperRight.distanceToGo() == 0;
}

int processCommand(String command)
{
    if(command == "forward")
    {
        addCommand(forward);
        return 1;
    }
    else if(command == "back")
    {
        addCommand(back);
        return 1;
    }
    else if(command == "left")
    {
        addCommand(left);
        return 1;
    }
    else if(command == "right")
    {
        addCommand(right);
        return 1;
    }
    
    return -1;
}
