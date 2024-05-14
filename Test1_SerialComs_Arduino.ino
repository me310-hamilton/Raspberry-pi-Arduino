//This program reads the Serial and when it receives data from the Raspberry pi turns on an LED for 5 seconds
#include <ArduinoJson.h>

const int ledPin=LED_BUILTIN;


void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop() {
  if(Serial.available()>0){
    StaticJsonDocument<200> doc;
    DeserializationError error=deserializeJson(doc,Serial);
    if(!error){
      const char* event= doc["event"];
      const char* tray=doc["tray"];
      int mediaAmountInMl=doc["mediaAmountInMl"];

      Serial.println(event);
      Serial.println(tray);
      Serial.println(mediaAmountInMl);

      //Turn on the LED
      digitalWrite(ledPin,HIGH);
      delay(5000);
      digitalWrite(ledPin,LOW);
      }
      else{
        Serial.println("Failed tp parse JSON");
        }
      
    }
  // put your main code here, to run repeatedly:

}
