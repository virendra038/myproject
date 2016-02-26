
#include "HX711.h"

#define calibration_factor -60300.0 

#define DOUT  3
#define CLK  2


//int i = 0 ;

HX711 scale(DOUT, CLK);

void setup() {
  Serial.begin(9600);
 
 pinMode(6,OUTPUT);
 
 

  scale.set_scale(calibration_factor); 
  //scale.tare();	

  
}
//void(*resetFunc) (void) = 0; 

void loop() {
 
  
 
  float w = abs(scale.get_units());
  w = w*453.59237 ;
  w = w - 500.00000;
  float m = abs(w);
  Serial.println(m);
  if(w >=1000 )
  { 
    digitalWrite(6,HIGH);
    }
    else
    { 
      digitalWrite(6,LOW);
    }

 
 delay(20000); 
// i = i+1 ;
// if(i == 3)
// {
//  i = 0;
//  resetFunc();
// }

 
}




