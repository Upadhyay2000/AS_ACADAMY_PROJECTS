#include<LiquidCrystal.h>
#include<Keypad.h>

// LCD Configuration

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad Configuration

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0,A1,A2,A3};
byte colPins[COLS] = {A4,A5,6,7};

Keypad keypad = Keypad(makeKeymap(keys) , rowPins, colPins, ROWS, COLS);

void setup(){
  
  lcd.begin(16, 2);
  lcd.print("Press a Key:");
}

void loop(){
  
  char key = keypad.getKey();
  if(key)
  {
    lcd.setCursor(0, 1);
    lcd.print("Key : ");
    lcd.print(key);
  }
}
