#include <Arduino.h>
#line 1 "C:\\Users\\bongi\\OneDrive\\Documents\\Arduino\\sketch_sep29a\\sketch_sep29a.ino"
#include <LiquidCrystal.h>
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int sensor = A1;
int tempc;
float tempf;
float vout;
float adc;

#line 10 "C:\\Users\\bongi\\OneDrive\\Documents\\Arduino\\sketch_sep29a\\sketch_sep29a.ino"
void setup();
#line 23 "C:\\Users\\bongi\\OneDrive\\Documents\\Arduino\\sketch_sep29a\\sketch_sep29a.ino"
void loop();
#line 10 "C:\\Users\\bongi\\OneDrive\\Documents\\Arduino\\sketch_sep29a\\sketch_sep29a.ino"
void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Argya Anindya Maghfirridho");
  lcd.setCursor(0, 1);
  lcd.print("01111940000012");
  delay(100);
  lcd.clear();
}

void loop()
{
  adc = analogRead(sensor);
  vout = adc / 1023 * 5;
  tempc = vout * 100;
  tempf = (tempc * 1.8) + 32;

  lcd.setCursor(0, 0);
  lcd.print("Suhu= ");
  lcd.print(tempc);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Suhu= ");
  lcd.print(tempf);
  lcd.print((char)223);
  lcd.print("F");
  delay(100);
}

