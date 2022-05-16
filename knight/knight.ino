#include <Arduino.h>
#include <Servo.h>

#define START_ANGLE 115
#define END_ANGLE 160

const int JUMP_TIME = 1000;
const int cooldown_time = 1000;

int threshold = 20000;

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

long beginning = millis();       //start of the game

int start;      // for storing time of jumping
bool cooldown = false;

int i = 1;

void loop(){

    int pulse = pulseIn(shck_pin, HIGH);
    if(pulse >= threshold)
        {
            gameover();

            //exit(0);
        }

    int in = digitalRead(button);
    if(in == HIGH){
        if(start == 0 && !cooldown){
            // jump
            jump_down();
            start = millis();
        }
    }
    if(start != 0 && millis() - start > JUMP_TIME){
        // pulse = pulseIn(shck_pin, HIGH);
        // Serial.println("Jump pulse: ");
        // Serial.println(pulse);
        jump_up();
    }
    if(start != 0 && millis()-start > JUMP_TIME+cooldown_time){
        // pulse = pulseIn(shck_pin, HIGH);
        // Serial.println("Cooldown pulse: ");
        // Serial.println(pulse);
        start = 0;
    }

}

void jump_up(){
    movt.write(START_ANGLE);
}

void jump_down(){
    movt.write(END_ANGLE);
}

void gameover(){
    Serial.println("GAME OVER");
    Serial.print("You were alive for ");
    Serial.print((millis() - beginning)/1000);
    Serial.println(" seconds");
    delay(1000);

    beginning = millis();
}