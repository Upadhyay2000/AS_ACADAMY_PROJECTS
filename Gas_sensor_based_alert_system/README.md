# Gas Sensor Based Alert System using Arduino UNO

This project implements a **gas leakage alert system** using an **MQ gas sensor**, **Arduino UNO**, **16x2 LCD**, **LEDs**, and a **buzzer**. The system continuously monitors the environment for gas presence and triggers alerts when dangerous levels are detected. It's an ideal beginner-level embedded systems project combining analog sensing, display interface, and real-time alerts.

---

## 🎯 Project Aim

To design an **Arduino-based alert system** that senses the level of gas concentration in the environment using an analog sensor and issues visual (LED, LCD) and audio (buzzer) alerts when the gas level exceeds a defined safe threshold. This project strengthens core concepts in **embedded systems**, including sensor interfacing, analog data reading, and actuator control.

---

## 🧰 Components Used

| S. No | Component               | Quantity |
|-------|--------------------------|----------|
| 1     | Arduino UNO              | 1        |
| 2     | MQ Gas Sensor            | 1        |
| 3     | 16x2 LCD Display         | 1        |
| 4     | Red LED (Danger)         | 1        |
| 5     | Green LED (Safe)         | 1        |
| 6     | Buzzer                   | 1        |
| 7     | Resistors (220Ω)         | 3        |
| 8     | Breadboard               | 1        |
| 9     | Jumper Wires             | as required |

---

## 🔌 Circuit Diagram (Tinkercad Layout)


- **MQ Gas Sensor** output → Analog pin **A0** of Arduino
- **Red LED** → Digital pin **2**
- **Green LED** → Digital pin **3**
- **Buzzer** → Digital pin **4**
- **LCD** → Pins **5, 6, 8, 9, 10, 11**
- LCD contrast connected directly (fixed or internally configured)

---

## ⚙️ How It Works

- The MQ sensor detects gas levels and sends an analog signal to the Arduino.
- The Arduino compares this value against a set **threshold** (e.g., 400).
- If the value exceeds the threshold:
  - **Red LED** turns on
  - **Buzzer** activates
  - **LCD** displays "ALERT" and "EVACUATE"
- If the value is below the threshold:
  - **Green LED** turns on
  - **LCD** shows "SAFE" and "ALL CLEAR"
- Real-time sensor values are printed via the Serial Monitor for observation.

---

## 📘 Key Concepts

✅ **Analog Sensor Reading**  
Analog values (0–1023) from the MQ gas sensor are read using `analogRead()` and compared with a threshold.

✅ **Alert Mechanism**  
Combining **LEDs**, **buzzer**, and **LCD display** to alert users visually and audibly.

✅ **LCD Display with LiquidCrystal Library**  
Used to output messages indicating safe or dangerous conditions.

✅ **Thresholding**  
Setting a boundary value to trigger emergency response based on sensor readings.

---

## 🔢 Arduino Code

```cpp
#include<LiquidCrystal.h>

LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;

void setup() {
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  int analogValue = analogRead(sensor);
  Serial.println(analogValue);
  
  if (analogValue > sensorThresh) {
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    tone(buzzer, 1000, 10000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("EVACUATE");
    delay(1000);
  } else {
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }
}
