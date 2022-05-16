#include <Arduino.h>
#include <Servo.h>

#define START_ANGLE 115
#define END_ANGLE 160

const int pingPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

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

    long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

    int pulse = pulseIn(shck_pin, HIGH);
    if(pulse >= threshold)
        {
            gameover();

            //exit(0);
        }

    //int in = digitalRead(button);
    Serial.println(cm);
    int in = (cm < 10) ? HIGH: LOW;
    if(in == HIGH){
        if(start == 0 && !cooldown){

            // jump
            movt.write(END_ANGLE);
            start = millis();
        }
    }
    if(start != 0 && millis() - start > JUMP_TIME){
        movt.write(START_ANGLE);
        start = 0;
    }
    // if(start != 0 && millis()-start > JUMP_TIME+cooldown_time){
    //     // pulse = pulseIn(shck_pin, HIGH);
    //     // Serial.println("Cooldown pulse: ");
    //     // Serial.println(pulse);
    //     start = 0;
    // }

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

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}