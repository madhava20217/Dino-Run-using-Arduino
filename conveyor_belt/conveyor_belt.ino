#include <Servo.h>

int pin_in = 7;

Servo conveyor;

void setup(){
    conveyor.attach(pin_in);
}

void loop(){
    conveyor.write(0);
    delay(5000);
    conveyor.detach();
}
