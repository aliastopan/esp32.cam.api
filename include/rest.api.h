#ifndef RESTAPI
#define RESTAPI

#include <SPIFFS.h>
#include <StringArray.h>
#include "server.config.h"
#include "board.h"

class API{
    public:
        static void Setup()
        {
            WiFi.begin(ssid, password);
            while (WiFi.status() != WL_CONNECTED) {
                delay(1000);
                Serial.println("connecting to an access point...");
            }
            if (!SPIFFS.begin(true)) {
                Serial.println("[ restarting ] an error has occurred while mounting SPIFFS");
                ESP.restart();
            }
            Serial.print("standy by: ");
            Serial.println(WiFi.localIP());
        }

        static void Start()
        {
            server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
                request->send(200, "text/plain", "ready");
            });

            server.begin();
        }

};

#endif