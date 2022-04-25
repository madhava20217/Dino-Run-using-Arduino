#include <Arduino.h>

//macros
#define blink(pin, dur1, dur2) digitalWrite(pin, HIGH);delay(dur1);digitalWrite(pin, LOW);delay(dur2);

//port definition
#define button_in 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button_in, INPUT);
} 

void loop() {
  // put your main code here, to run repeatedly:
  int in = digitalRead(button_in);

  if(in == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("HIGH INPUT!");
  }

  else{
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LOW INPUT!");
  } 

  delay(500);
}

