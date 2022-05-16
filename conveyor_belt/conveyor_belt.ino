#include <Arduino.h>
#include <Servo.h>

int pin_in = 7;
int pin_in2 = 6;

#define LOOP_TIME 6500      //time taken to lap

Servo conveyor1;
Servo conveyor2;

int start;          // start time

void setup(){
    conveyor1.attach(pin_in);
    conveyor2.attach(pin_in2);

    start = millis();
}

void loop(){


}

void move(){
    /*Moves the conveyor belts*/
    conveyor1.attach(pin_in);
    conveyor2.attach(pin_in2);

    conveyor1.write(180);
    conveyor2.write(180);
}

void stop(){
    conveyor1.detach();
    conveyor2.detach();
}
