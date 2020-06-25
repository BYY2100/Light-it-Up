#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

void setup() {
    WiFi.disconnect();
   WiFi.begin("Light It Up","123698741");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
  }
}


void loop() {
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "R0ZQ3145W2EFETZD";
      request_string += "&";
      request_string += "field1";
      request_string += "=";
      request_string += (random(0,100));
      http.begin(request_string);
      http.GET();
      http.end();
      delay(15000);
    }
}