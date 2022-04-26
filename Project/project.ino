#include <LiquidCrystal.h>

#define test_period 5000000         //define test period in microseconds
#define threshold  500              //defines a threshold for a hit to be registered
#define correction_val 112          //defines a value used for correction for counting hit time
#define input_port A0               //defines the input port



const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
    Serial.begin(9600);
    pinMode(input_port, INPUT);
    lcd.begin(16, 2);
}

int loop_iter = 0;

void loop(){

    double accuracy = timer();

    Serial.print("Accuracy is :");
    Serial.print(accuracy);
    Serial.println("%");
    lcd.clear();
    lcd.print("Accuracy is:");
    lcd.setCursor(0, 1);
    lcd.print(accuracy);

    delay(1000);
}

double timer(){
    long int start = micros();
    long int hits = 0;             //calculates the number of times a hit is registered
    while(micros()- start < test_period){
        if(analogRead(input_port) > threshold) hits+=100;
    }
    return (double)hits / (double) test_period * correction_val;
}