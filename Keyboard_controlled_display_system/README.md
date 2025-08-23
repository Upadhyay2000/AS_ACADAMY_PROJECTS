# 🔢 Keypad-Controlled LCD Display using Arduino

This project demonstrates how to interface a **4x4 Matrix Keypad** with a **16x2 LCD Display** using an **Arduino Uno**. The pressed key is displayed on the LCD in real-time, making it a simple and interactive input/output system.

## 🧠 Project Objective

To develop a system where the user can press any key on a 4x4 keypad, and the corresponding character is instantly displayed on a 16x2 LCD.

---

## ⚙️ Components Used

| Component            | Quantity |
|----------------------|----------|
| Arduino Uno          | 1        |
| 16x2 LCD Display     | 1        |
| 4x4 Matrix Keypad    | 1        |
| 10k Potentiometer    | 1        |
| Breadboard           | 1        |
| Jumper Wires         | As needed |
| USB Cable            | 1        |

---

## 🔌 Circuit Connections

### LCD to Arduino:
- RS → Pin 12  
- Enable → Pin 11  
- D4 → Pin 5  
- D5 → Pin 4  
- D6 → Pin 3  
- D7 → Pin 2  
- VSS → GND  
- VDD → 5V  
- V0 → Center pin of Potentiometer  
- RW → GND  
- A → 5V  
- K → GND  

### Keypad to Arduino:
- Row 1 → A0  
- Row 2 → A1  
- Row 3 → A2  
- Row 4 → A3  
- Col 1 → A4  
- Col 2 → A5  
- Col 3 → Pin 6  
- Col 4 → Pin 7  

### Potentiometer:
- One side → GND  
- Other side → 5V  
- Middle (wiper) → LCD V0 (contrast control)

---

## 🧾 Arduino Code

```cpp
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

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  lcd.begin(16, 2);
  lcd.print("Press a Key:");
}

void loop(){
  char key = keypad.getKey();
  if(key){
    lcd.setCursor(0, 1);
    lcd.print("Key : ");
    lcd.print(key);
  }
}
