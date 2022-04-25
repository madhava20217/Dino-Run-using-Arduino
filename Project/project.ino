#define test_period 5000000         //define test period in microseconds
#define threshold 450               //defines a threshold for a hit to be registered
#define correction_val 112          //defines a value used for correction for counting hit time
#define input_port A0               //defines the input port


void setup(){
    Serial.begin(9600);
    pinMode(input_port, INPUT);
}

int loop_iter = 0;

void loop(){
    double accuracy = timer();

    Serial.print("Accuracy is :");
    Serial.print(accuracy);
    Serial.println("%");
}

double timer(){
    long int start = micros();
    long int hits = 0;             //calculates the number of times a hit is registered
    while(micros()- start < test_period){
        if(analogRead(input_port) < threshold) hits+=100;
    }
    return (double)hits / (double) test_period * correction_val;
}