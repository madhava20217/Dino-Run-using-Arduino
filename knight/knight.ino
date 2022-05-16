#include <Arduino.h>
#include <Servo.h>

#define START_ANGLE 115
#define END_ANGLE 160

int threshold = 30;         //creates an alarm if greater than the value specified

int shck_pin = 5;           // pin for shock sensor
int movement = 7;           // pin for movement
int button = 8;             // pin for button

Servo movt;

void setup(){
    Serial.begin(9600);
    pinMode(shck_pin, INPUT);

    movt.attach(movement);

    pinMode(button, INPUT);
}



void loop(){

    // if(analogRead(shck_pin) > threshold){
    //     //Do something
    //     Serial.print("ALARM ");
    //     Serial.println(num++);
    //     delay(500);
    // }
    pulseIn(shck_pin, HIGH);
    
    movt.write(START_ANGLE);
    Serial.println(START_ANGLE);
    delay(5000);
    movt.write(END_ANGLE);
    Serial.println("END ANGLE");
    delay(5000);
}
