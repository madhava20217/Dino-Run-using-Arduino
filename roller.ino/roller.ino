#include <Arduino.h>
#include <Servo.h>
#include <IRremote.h>


Servo motor;

int serv_pin = 8;

int recv_pin = 2;

IRrecv irrecv(recv_pin);

void setup(){


    motor.attach(serv_pin);
    Serial.begin(9600);
    irrecv.enableIRIn();

    Serial.println("HELLO!");
}

decode_results results;

void loop(){

    if(irrecv.decode(&results)){
        //int results.value = results;
        Serial.println(" ");
        Serial.print("CODE: ");
        Serial.println(results.value, HEX);


        delay(1500);
        irrecv.resume();
    }
    
    // if(!in) {
    //     digitalWrite(13, HIGH);
    //     delay(1000);
    //     digitalWrite(13, LOW);
    // }
    
    //if(!in) servo_protocol();
}

void servo_protocol(){
    for(int i = 0; i <= 180; i++){
        motor.write(i);
        delay(2);
    }
}