#include <Arduino.h>
#include <Servo.h>

//Has three pins: one for button, another for servo, and a last one for the shock sensor

#define pin_button 10       // button pin
#define pin_cont 11         // input pin
#define int shck_pin A0     // shock sensor
#define threshold 50        // threshold for shock sensor
#define jp_time 2500        // time for jump

#define inp_step 1          // step size for limited servo

int start_angle = 90;                   // start angle
int end_angle = 180-start_angle;        // terminal angle


Servo limited_movement;     // limited movement servo

void setup(){
    limited_movement.attach(pin_cont);
    limited_movement.write(start_angle);
    Serial.begin(9600);
    Serial.println("Hello World!");

    pinMode(pin_button, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(shck_pin, INPUT);
}

boolean jumping = false;
boolean top = false;
int current_angle = start_angle;

int jump_time = 0;          //time when jump initiated

void loop(){

    if(analogRead(shck_pin) < threshold){
        if(digitalRead(pin_button) && !jumping) {
            jumping = true;
            up = 1;
            // Serial.println("JUMPING");
        }

        if(jumping){
            if(!top){
                //go up
                limited_movement.write(0);
                jump_time = millis();
            }
            
            if(top && millis() - jump_time > jp_time){
                limited_movement.write(180);
                jumping = false;
            }
        }
    }
    
}
