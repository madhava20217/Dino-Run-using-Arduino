#include <Arduino.h>
#include <Servo.h>

#define pin_button 10       // button pin
#define pin_cont 11         // input pin

#define inp_step 1          // step size for limited servo

#define start_angle 45      // start angle
#define end_angle 180-start_angle       // terminal angle


Servo limited_movement;     // limited movement servo

void setup(){
    limited_movement.attach(pin_cont);
    limited_movement.write(start_angle);
    Serial.begin(9600);
    Serial.println("Hello World!");
    limited_movement.write(start_angle);

    pinMode(pin_button, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

int iterations = 0;         // iterations for loop
boolean jumping = false;    // jumping is false
boolean up = 1;             // jumping up, is 1 if jumping
int current_angle = start_angle;

void loop(){
    if(digitalRead(pin_button) && !jumping) {
        jumping = true;
        Serial.println("JUMPING");
    }

    if(jumping){
        if(current_angle >= end_angle) up = -1;     //for moving down

        current_angle+=up*inp_step;

        limited_movement.write(current_angle);


        if(current_angle <= start_angle){
            jumping = false;
            //ending jumps
        }
    }
    
}
