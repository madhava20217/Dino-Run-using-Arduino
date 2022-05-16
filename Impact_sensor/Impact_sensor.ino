#include <Arduino.h>

int threshold = 30;         //creates an alarm if greater than the value specified

int shck_pin = A0;

void setup(){
    Serial.begin(9600);
    pinMode(shck_pin, INPUT);
}
int num = 0;
void loop(){

    if(analogRead(shck_pin) > threshold){
        //Do something
        Serial.print("ALARM ");
        Serial.println(num++);
        delay(500);
    }
}