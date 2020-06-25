#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

int  i;

void setup() {
	Serial.begin(9600);
	ThingSpeak.begin(client);

	WiFi.disconnect();
	delay(3000);
	Serial.println("START");
	WiFi.begin("Private Network","password_123456");
	while ((!(WiFi.status() == WL_CONNECTED))){
		delay(300);
    		Serial.print("..");
	}
	Serial.println("Connected");
	Serial.println("Your IP is");
	Serial.println((WiFi.localIP().toString()));
}

void loop() {
	i = (ThingSpeak.readIntField(613228,1,"EEAP5XAB5RW2E7PP"));
	delay(1000);
	if (i <= 30) {
		analogWrite(14, 1023);;
    	} else if (i <= 75) {
		analogWrite(14, 820);;
    	} else if (i <= 130) {
		analogWrite(14, 680);;
	} else if (i <= 200) {
      		analogWrite(14, 512);;
    	} else {
      		analogWrite(14, 0);;
  	}
    	delay(1000);
}
