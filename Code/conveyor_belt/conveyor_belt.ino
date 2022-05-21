#include <Arduino.h>
#include <Servo.h>

int pin_in = 7;
int pin_in2 = 6;
int stop_button = 11;


Servo conveyor1;
Servo conveyor2;

int start;          // start time

void setup(){
    Serial.begin(9600);
    conveyor1.attach(pin_in);
    conveyor2.attach(pin_in2);


    pinMode(stop_button, INPUT);
    start = millis();

    move();     //get it to move first
}


boolean pause = false;


void loop(){

    int in = digitalRead(stop_button);

    if(in == HIGH){
        Serial.println("TESTING");
        if(pause){
            attach();
            move();
        }

        else{
            stop();
        }

        pause = !pause;
        delay(500);
    }

}

void move(){
    /*Moves the conveyor belts*/

    conveyor1.write(180);
    conveyor2.write(180);
}

void stop(){
    conveyor1.detach();
    conveyor2.detach();
}

void attach(){
    conveyor1.attach(pin_in);
    conveyor2.attach(pin_in2);

}