int relay_1 = 5;
int MQ2pin = A0;
int sensorValue;
int MQ2Thres = 400;
#define Sensor 7
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
lcd.init();
lcd.init();
lcd.backlight();
Serial.begin(9600);
pinMode(Sensor, INPUT);
pinMode(relay_1, OUTPUT);
}
void loop() {
bool value = digitalRead(Sensor);
Serial.println(value);
sensorValue = analogRead(MQ2pin);
lcd.setCursor(0,0);
lcd.print(" Value ");
lcd.print(sensorValue);
lcd.print("ppm");
Serial.println(sensorValue, DEC);
if (sensorValue > 450){
delay(250);
digitalWrite(relay_1, HIGH);
delay(1000);
digitalWrite(relay_1, LOW);
delay(1000);
lcd.setCursor(0,1);
lcd.print("Smoke detected ");
}
else{
lcd.setCursor(0,1);
lcd.print("No Fire,No Gas");
}
if (value == 0) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print(sensorValue);
lcd.print(" No Fire and No Gas");
delay(250);
digitalWrite(relay_1, HIGH);
delay(1000);
digitalWrite(relay_1, LOW);
delay(1000);
}
}
