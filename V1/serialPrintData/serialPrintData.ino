#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
const int voltage16Button = 2; 
const int voltage32Button = 3;
const int current400Button = 4;
const int current1Button = 5;
const int current2Button = 6;
int voltage16State = 0;
int voltage32State = 0;
int current400State = 0;
int current1State = 0;
int current2State = 0;
SoftwareSerial BTserial(10, 11);

void setup() 
{
  ina219.begin();
  pinMode(voltage16Button, INPUT);
  pinMode(voltage32Button, INPUT);
  pinMode(current400Button, INPUT);
  pinMode(current1Button, INPUT);
  pinMode(current2Button, INPUT);
  BTserial.begin(9600);
}

void loop() 
{
  float voltage16 = 0;
  float voltage32 = 0;
  float current400 = 0;
  float current1 = 0;
  float current2 = 0;
  voltage16State = digitalRead(voltage16Button);
  voltage32State = digitalRead(voltage32Button);
  current400State = digitalRead(current400Button);
  current1State = digitalRead(current1Button);
  current2State = digitalRead(current2Button);
  
  if (voltage16State == HIGH) 
  {
  ina219.setCalibration_16V_400mA();
  voltage16 = ina219.getBusVoltage_V();
  BTserial.print(voltage16);
  BTserial.print(",");
  }
  if (voltage32State == HIGH) 
  {
  ina219.setCalibration_32V_1A();
  voltage32 = ina219.getBusVoltage_V();
  BTserial.print(voltage32);
  BTserial.print(",");
  }
  if (current400State == HIGH) 
  {
  ina219.setCalibration_16V_400mA();
  current400 = ina219.getCurrent_mA();
  BTserial.print(current400);
  BTserial.print(",");
  }
  if (current1State == HIGH) 
  {
  ina219.setCalibration_32V_1A();
  current1 = ina219.getCurrent_mA();
  BTserial.print(current1);
  BTserial.print(",");
  }
  if (current2State == HIGH) 
  {
  ina219.setCalibration_32V_2A();
  current2 = ina219.getCurrent_mA();
  BTserial.print(current2);
  BTserial.print(",");
  }
  
  BTserial.print(";");
  delay(2000);
}
