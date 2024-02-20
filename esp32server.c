#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>

// Set your access point network credentials
const char* ssid = "ESP32Server";
const char* password = "123server";

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);
  Serial.println();
  
  Serial.print("Cofigurando ponto de acesso...");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("IP do ponto de acesso: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "temperatura");
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "umidade");
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "pressao");
  });  
  // Start server
  server.begin();
}
 
void loop(){
  
}
