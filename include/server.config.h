#ifndef SERVERCONFIG
#define SERVERCONFIG

#include <DNSServer.h>
#include "WiFi.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const int port = 80;
const char* ssid = "Wifi@Home";
const char* password = "02062000";
DNSServer dnsServer;
AsyncWebServer server(port);

#endif