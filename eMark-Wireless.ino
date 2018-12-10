#include <Wire.h>
#include <Adafruit_INA219.h>
#include "StringSplitter.h"

Adafruit_INA219 ina219;
byte flag = 0;
char cM[1];
char cS[1];
char cA[1];

void setup() {
  Serial.begin(115200);
  while(!Serial){
    delay(1);
  }

  uint32_t currentFrequency;

  ina219.begin();


}

void loop() {
  flag = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  String inputCommand = Serial.readString();
  StringSplitter *commands = new StringSplitter(inputCommand, ' ', 3);
  int itemCount = commands->getItemCount();
  
  String commandMain = commands->getItemAtIndex(0); 
  String commandSub = commands->getItemAtIndex(1);
  String commandArg = commands->getItemAtIndex(2);
  
  //Define State Machine Here
  if(commandMain=="volt"){
    while(1){
      float volts = getVolts();
      Serial.println(volts);
      if(flag==0){
        break;
        }
      }
    } else if(commandMain=="current"){
      while(1){
      float curr = getAmps();
      Serial.println(curr);
      if(flag==0){
        break;
        }
      }
    } else {
      Serial.println("Wrong input");
      flag = 0;
  }
  
}

float getVolts(){
  flag = 1;
  float shuntvoltage = ina219.getShuntVoltage_mV();
  float busvoltage = ina219.getBusVoltage_V();
  float temp = busvoltage + (shuntvoltage / 1000);
  return temp;
}

float getAmps(){
  flag = 1;
  float temp = ina219.getCurrent_mA();
  return temp;
}

//Add More Functions to this section
