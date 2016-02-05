#include<Sleep_n0m1.h>
#include "HX711.h"

#define calibration_factor -13110.0 

#define DOUT  3
#define CLK  2


HX711 scale(DOUT, CLK);
//Sleep sleep;
//unsigned long sleepTime;
void setup() {
  Serial.begin(9600);
 //sleepTime=  10000;
 pinMode(6,OUTPUT);
 

  scale.set_scale(calibration_factor); 
  scale.tare();	

  
}

void loop() {
 
  
 
  float w = abs(scale.get_units());
  w = w*453.59237 ;
  Serial.println(w);
  if(w >=3000 )
  { 
    digitalWrite(6,HIGH);
    }
    else
    { 
      digitalWrite(6,LOW);
    }
 delay(10000); 

 //sleep.pwrDownMode();
 //sleep.sleepDelay(sleeptime);
 
}
