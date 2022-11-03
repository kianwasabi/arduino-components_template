/*
  Template for testing your Arduino components and wiring. 
*/

// Include Libraries
#include <Arduino.h> 
#include <LiquidCrystal_I2C.h>
#include "Class.h"

// Pin Definitions
#define AAA  9
#define BBB  8

// Define Components characteristics (e.g. I2C LCD)
#define LCD_ADDRESS 0x27 //0x3f ...
#define LCD_ROWS 4
#define LCD_COLUMNS 20

// Initialization Objects
CLASS obj1(AAA);
CLASS obj2(BBB);

// Define global vars (e.g. for testing menu)
const int timeout = 15000;
char menuOption = 0;
long time;
boolean lcdprinted = false;

// Setup circuit. Put your setup code here, to run once.
void setup()
{
  Serial.begin(9600);
  while (!Serial) ; 
  Serial.println("start");
  lcd.init();
  pushButton.init();
  menuOption = menu();
}

// Testing menu in serial monitor
char menu()
{
  Serial.println(F("\nWhich component would you like to test?"));
  Serial.println(F("[1] Component #1"));
  Serial.println(F("[2] Component #2"));
  Serial.println(F("[Menu] send anything else or press on board reset button\n"));
  while (!Serial.available());

  while (Serial.available())
  {
    char c = Serial.read();
    if (isAlphaNumeric(c))
    {
      if (c == '1')
        Serial.println(F("Now Testing Component #1"));
      else if (c == '2')
        Serial.println(F("Now Testing Component #2"));
      else
      {
        Serial.println(F("invalid input"));
        return 0;
      }
      time = millis();
      return c;
    }
  }
}

// Looping Louie! Put your main code here, to run repeatedly.
void loop()
{
  if (menuOption == '1') {
    //Code for testing Component #1
    //Add your Code here, e.g.: 
    float var_obj1 = obj1.func();
    Serial.print(F("Output: "));
    Serial.print(var_obj1);
  }
  else if (menuOption == '2') {
    //Code for testing Component #1
    //Add your Code here, e.g.: 
    float var_obj2 = obj2.func();
    Serial.print(F("Output: "));
    Serial.print(var_obj2);
  }
  if (millis() - time > timeout)
  {
    menuOption = menu();
  }
}
