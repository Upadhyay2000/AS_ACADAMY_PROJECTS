#include<LiquidCrystal.h>    // Include the LCD Library

// Initialize LCD: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

// Define pins for output devices

int redled = 2;   // Red LED pin (denger indicator)
int greenled = 3;  // Green LED pin (Safe indicator)
int buzzer = 4;    // Buzzer pin for alarm

// Define analog input for sensor

int sensor = A0;         // Sensor connected to analog pin A0
int sensorThresh = 400;  // Thresold value for denger detection 

void setup()
{
  // Set LED and buzzer pins as OUTPUT
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // set sensor pin as INPUT
  pinMode(sensor, INPUT);
  
  // start serial monitor for debugging
  Serial.begin(9600);
  
  // Initialize LCD with 16 column and 2 rows
  lcd.begin(16,2);
 
}

void loop()
{
  // Read sensor value from analog pin
  int analogValue = analogRead(sensor);
  
  // print sensor value to serial monitor for observation
  Serial.println(analogValue);
  
  // if sensor value exceeds thresold -> DENGER
  if(analogValue > sensorThresh)
  {
    digitalWrite(redled, HIGH);         // Turn on red LED
    digitalWrite(greenled, LOW);       // Turn off green LED
    tone(buzzer, 1000, 10000);          // play buzzer tone at 1000 Hz for 10s
    
    // Display "ALERT" message
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALERT");
    delay(1000);
    
     // Display "EVACUATE" message
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("EVACUATE");
    delay(1000);
  }
  else
  {
    // safe condition
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    noTone(buzzer);
    
     // Display "SAFE" message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SAFE");
    delay(1000);
    
     // Display "ALL CLEAR" message
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }
 
}
