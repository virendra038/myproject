#include "HX711.h"

#define calibration_factor -13110.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

void setup() {
  Serial.begin(9600);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);

  scale.set_scale(calibration_factor); 
  scale.tare();	

  
}

void loop() {
 
  delay(200);
  float w = abs(scale.get_units());
  w = w*453.59237 ;
  Serial.println(w);
  if(w >=2000 )
  { 
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    }
    else
    { digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
 delay(200); 
 Serial.println();
 
}
