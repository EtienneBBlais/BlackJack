#include <Arduino.h>
#include <Arduino.h>
#include <librobus.h>
#include <math.h>
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <string.h>

enum COULEUR{
  rouge,
  jaune,
  vert,
  bleu, 
  tapis,
  blanc,
  noir,
  sol,
}color;

Adafruit_TCS34725 capteur = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);



int lectureCouleur()
{
  enum COULEUR couleur;
  uint16_t red, green, blue, clear, temp;
  capteur.getRawData(&red, &green, &blue, &clear);
  temp = capteur.calculateColorTemperature(red, green, blue);
  /*
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.print("\tT:\t"); Serial.println(temp);
  */
  //Serial.println(temp);
  if(temp>10000){
    couleur = bleu;
    //Serial.println("bleu");
  }
  else if(temp > 5700){
    if(clear > 500){
      couleur = tapis;
      //Serial.println("tapis");
    }
    else {
    couleur = vert;
    Serial.println("vert");
  }
  }
  else if(temp > 5000){
    if(clear > 500){
      couleur = noir;
      //Serial.println("noir");
    }
    else {
    couleur = sol;
    //Serial.println("sol");
  }
  }
  else if (temp > 4300){
    couleur = blanc;
    //Serial.println("blanc");
  }
  else {
    if(clear > 700){
      couleur = jaune;
      //Serial.println("jaune");
    }
    else {
    couleur = rouge;
    //Serial.println("rouge");
  }
  
  
  }  
  //Serial.println(clear);
  return couleur;
  
}

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