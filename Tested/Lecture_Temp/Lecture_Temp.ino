#include "Thermistance.h"

void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Thermistance Temp;
  
  double sensorValue = Temp.GetTempratureCelsius();
  Serial.print("sensor = ");
  Serial.println(sensorValue);

  delay(1000);
}