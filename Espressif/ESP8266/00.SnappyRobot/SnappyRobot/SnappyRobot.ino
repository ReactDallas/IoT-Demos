#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>

#include "Robot.h"
#include "Command.h"
#include "WebPage.h"

void setup()
{
    setupSteppers();
    setupWebPage();
    
    // Listen for commands from the web!
    //Spark.function("command", processCommand);
    
    /*
     * ==================================
     * Add your commands below this line!
     * ==================================
     */
    
    addCommand(forward);
    addCommand(back);
    //addCommand(left);
    //addCommand(right);
}

void loop()
{
    pageServerProcess();
    
    if(isDoneMoving() && commands.size())
    {
        runCommand(commands.front());
        commands.pop();
    }
    
    stepperLeft.run();
    stepperRight.run();
}
