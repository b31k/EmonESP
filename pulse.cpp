#include "emonesp.h"
#include "pulse.h"


//Used to measure power.
unsigned long pulseTime,lastTime;

//power and energy
double power;

//Number of pulses per wh - found or set on the meter.
int ppwh = 1; //1000 pulses/kwh = 1 pulse per wh

String last_pulse="";


// The interrupt routine
void onPulse()
{
    boolean gotPulse = false;
    //used to measure time between pulses.
    lastTime = pulseTime;
    pulseTime = micros();



    //Calculate power
    power = (3600000000.0 / (pulseTime - lastTime))/ppwh;


    //Print the values.
    if(power<10000){
    last_pulse=String(power,2);

    }
    else{}
      //  Serial.println("error");


}
