/*
 * HCSR04UltrasonicLCD/HCS04UltrasonicLCD.ino
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: ni9htfury $
 * $Date: 2013-02-19 22:08:00 +0*00 (Tue, 19 Feb 2013) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define TRIGGER_PIN  8
#define ECHO_PIN     9

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
  {
  Serial.begin(9600);
  lcd.begin(16, 2);
  }

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  delay(100);
  
  lcd.clear();
  //lcd.print("MS: ");
  lcd.print(microsec);
  lcd.print(" ms");
  lcd.setCursor(0, 1);
  //lcd.print(", CM: ");
  lcd.print(cmMsec);
  lcd.print(" cm");
  //lcd.print(", IN: ");
  //lcd.println(inMsec);
  }
