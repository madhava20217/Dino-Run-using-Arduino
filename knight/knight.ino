#include <Arduino.h>
#include <Servo.h>

#define START_ANGLE 115
#define END_ANGLE 160

const int JUMP_TIME = 1000;

int threshold = 10000;

int shck_pin = 5;           // pin for shock sensor
int movement = 7;           // pin for movement
int button = 8;             // pin for button

Servo movt;

void setup(){
    Serial.begin(9600);
    pinMode(shck_pin, INPUT);

    movt.attach(movement);

    pinMode(button, INPUT);
    movt.write(START_ANGLE);
}

int start;      // for storing time of jumping
bool pressed = false;

void loop(){

    // int pulse = pulseIn(shck_pin, HIGH);
    
    // Serial.println(pulse);

    int in = digitalRead(button);
    if(in == HIGH){
        //Serial.println("YEET");
        if(start == 0){
            // jump
            jump_down();
            start = millis();
        }
    }
    if(start != 0 && millis() - start > JUMP_TIME){
            start = 0;
            jump_up();
        }

}

void jump_up(){
    movt.write(START_ANGLE);
}

void jump_down(){
    movt.write(END_ANGLE);
}
