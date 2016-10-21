#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>

#include "Command.h"
#include "WebPage.h"

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer pageServer(80);

const char *testPage = "test";

void servePage()
{
  pageServer.send(200, "text/html", testPage);
/*
  pageServer.send(200, "text/html", "<!DOCTYPE><html><head><title>SnappyRobot</title>\
<meta name=\"viewport\" content=\"initial-scale=2, maximum-scale=2\"></head>\
<body>\
<form id=\"forward\" action=\"/forward\" method=\"POST\">\
  <input type=\"submit\" value=\"Forward\">\
</form>\
<form id=\"back\" action=\"/back\" method=\"POST\">\
  <input type=\"submit\" value=\"Back\">\
</form>\
<form id=\"left\" action=\"/left\" method=\"POST\">\
  <input type=\"submit\" value=\"Left\">\
</form>\
<form id=\"right\" action=\"/right\" method=\"POST\">\
  <input type=\"submit\" value=\"Right\">\
</form>\
</body>\
</html>");
*/
}

void pageServerProcess()
{
  dnsServer.processNextRequest();
  pageServer.handleClient();
}


void goForward()
{
  addCommand(forward);
  servePage();
}

void goBack()
{
  addCommand(back);
  servePage();
}

void goLeft()
{
  addCommand(left);
  servePage();
}

void goRight()
{
  addCommand(right);
  servePage();
}

void setupWebPage()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(AP_SSID, AP_PASS);

  dnsServer.start(DNS_PORT, "*", apIP);

  pageServer.onNotFound([]() {
    pageServer.send(200, "text/html", "testhtml");
  });
  
  pageServer.on("/", servePage);
  pageServer.on("/forward", goForward);
  pageServer.on("/back", goBack);
  pageServer.on("/left", goLeft);
  pageServer.on("/right", goRight);
  pageServer.begin();
}
