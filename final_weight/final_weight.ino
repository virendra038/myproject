#include "HX711.h"

#define calibration_factor -13110.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

void setup() {
  Serial.begin(9600);
 

  scale.set_scale(calibration_factor); 
  scale.tare();	

  
}

void loop() {
 
  delay(200);
  Serial.println(scale.get_units()*453.59237, 3);

 delay(200); 
 Serial.println();
 
}
