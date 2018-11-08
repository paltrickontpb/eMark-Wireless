#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
const int busVoltageButton = 2; 
const int shuntVoltageButton = 3;
const int loadVoltageButton = 4;
const int currentButton = 5;
const int powerButton = 6;
int busState = 0;
int shuntState = 0;
int loadState = 0;
int currentState = 0;
int powerState = 0;

void setup() 
{
  Serial.begin(115200);
  while (!Serial) {
      delay(1);
  }
  uint32_t currentFrequency;
  ina219.begin();
  ina219.setCalibration_16V_400mA();
  pinMode(busVoltageButton, INPUT);
  pinMode(shuntVoltageButton, INPUT);
  pinMode(loadVoltageButton, INPUT);
  pinMode(currentButton, INPUT);
  pinMode(powerButton, INPUT);
}

void loop() 
{
  float busvoltage = 0;
  float shuntvoltage = 0;
  float loadvoltage = 0;
  float current_mA = 0;
  float power_mW = 0;
  busState = digitalRead(busVoltageButton);
  shuntState = digitalRead(shuntVoltageButton);
  loadState = digitalRead(loadVoltageButton);
  currentState = digitalRead(currentButton);
  powerState = digitalRead(powerButton);

  if (busState == HIGH) 
  {
  busvoltage = ina219.getBusVoltage_V();
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  }
  if (shuntState == HIGH) 
  {
    shuntvoltage = ina219.getShuntVoltage_mV();
    Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  }
  if (loadState == HIGH) 
  {
  busvoltage = ina219.getBusVoltage_V();
  shuntvoltage = ina219.getShuntVoltage_mV();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  }
  if (currentState == HIGH) 
  {
  current_mA = ina219.getCurrent_mA();
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  }
  if (powerState == HIGH) 
  { 
  power_mW = ina219.getPower_mW();
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  }
  
  Serial.println("");
  delay(2000);
}
