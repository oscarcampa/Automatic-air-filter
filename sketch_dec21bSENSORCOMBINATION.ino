%%%% Temperature sensor reading code 
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();  // Start up the library
  Serial.begin(9600);
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
  
  delay(500);
}


%% End of Temperature Code 

%% Initiate Voltage sensor Code 
#include "LiquidCrystal.h"

const int voltageSensor = A0;

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

void setup()
{
//Serial.begin(9600);
lcd.begin(16,2);
lcd.print(" Measure > 25V  ");
delay(2000);
}

void loop()
{
  value = analogRead(voltageSensor);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
  //Serial.print("Input = ");
  //Serial.println(vIN);
  lcd.setCursor(0,0);
  lcd.print("Input =         ");
  lcd.setCursor(9,0);
  lcd.print(vIN);
  delay(500);
}


%% End of voltage sensor Code 

%% BEgin Current Sensor Code 

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
 
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Current Sensor ");
  lcd.setCursor(0,1);
  lcd.print("  with Arduino  ");
  delay(2000);
}
 
void loop()
{
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  
  Serial.print("Raw Sensor Value = " );
  Serial.print(adcValue);
 
  lcd.clear();
  delay(1000);
  //lcd.display();
  lcd.setCursor(0,0);
  lcd.print("ADC Value =     ");
  lcd.setCursor(12,0);
  lcd.print(adcValue);

  delay(2000);

  Serial.print("\t Voltage(mV) = ");
  Serial.print(adcVoltage,3);
  
  lcd.setCursor(0,0);
  lcd.print("V in mV =       ");
  lcd.setCursor(10,0);
  lcd.print(adcVoltage,1);

  delay(2000);
 
  Serial.print("\t Current = ");
  Serial.println(currentValue,3);
 
  lcd.setCursor(0,0);
  lcd.print("Current =       ");
  lcd.setCursor(10,0);
  lcd.print(currentValue,2);
  lcd.setCursor(14,0);
  lcd.print("A");
  delay(2500);
}

%% End of current Code 
