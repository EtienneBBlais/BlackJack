#include <Arduino.h>
#include <Arduino.h>
#include <librobus.h>
#include <math.h>
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <string.h>

Adafruit_TCS34725 capteur = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);





void setup()
{
  Serial.begin(9600);
  BoardInit();
  Wire.begin();
  SERVO_Enable(0);
  SERVO_SetAngle(0, 45);
  SERVO_Disable(0);
  delay(1500);
}

void loop() 
{
  
}