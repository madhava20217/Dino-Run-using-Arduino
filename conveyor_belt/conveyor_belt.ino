#include <Servo.h>

int pin_in = 7;
int pin_in2 = 6;

Servo conveyor1;
Servo conveyor2;

void setup(){
    conveyor1.attach(pin_in);
    conveyor2.attach(pin_in2);
}

void loop(){
    conveyor1.write(0);
    conveyor2.write(0);

}
