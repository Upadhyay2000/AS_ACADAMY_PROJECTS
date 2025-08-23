# Fan Speed Control Using Light (LDR-Based Motor Control)

This project demonstrates how to control the **speed and direction of a DC motor** using an **L293D Motor Driver IC** and an **Arduino Uno**, based on ambient light intensity sensed by an **LDR (Light Dependent Resistor)**. The system is simulated and tested using **Tinkercad**, providing a safe and interactive virtual environment for circuit design and debugging.

## 🧠 Project Aim
To design a light-controlled DC motor system that adjusts the **motor's speed** based on the **intensity of light**, while also allowing **direction control**. This project strengthens core concepts in **embedded systems**, including sensor interfacing, PWM, motor drivers, and circuit simulation.

---

## 🔧 Components Used

| S. No | Component               | Quantity |
|-------|-------------------------|----------|
| 1     | Arduino Uno             | 1        |
| 2     | L293D Motor Driver IC   | 1        |
| 3     | Light Dependent Resistor| 1        |
| 4     | DC Motor                | 1        |
| 5     | Breadboard              | 1        |
| 6     | Jumper Wires            | 4        |
| 7     | Power Supply (5V)       | 1        |

---

## 📐 Circuit Diagram (Tinkercad Layout)
- IN1 and IN2 of L293D connected to D2 and D3 of Arduino
- EN1 connected to PWM pin D9
- Motor connected to OUT1 and OUT2
- LDR connected to Analog Pin A0 of Arduino
- LDR's one terminal to A0, the other to 5V

---

## 🧩 How It Works
- The LDR senses ambient light and sends an analog signal to the Arduino.
- The `analogRead()` value (0-1023) is mapped to a PWM range (0-255) using `map()` function.
- The motor speed is controlled by `analogWrite()` using this mapped PWM value.
- Motor direction is set using digital pins via logic HIGH/LOW.

---

## 💡 Key Concepts

### ✅ PWM (Pulse Width Modulation)
Used to control motor speed by varying the average voltage using `analogWrite(pin, value)`.

### ✅ Mapping
Arduino's `map()` function scales sensor values to suitable output ranges (e.g., 0–1023 from LDR to 0–255 for PWM).

### ✅ H-Bridge & L293D
The L293D uses an H-Bridge configuration to control motor direction. It allows:
- Clockwise rotation
- Counter-clockwise rotation
- Stopping the motor

---

## 📄 Arduino Code

```cpp
int pin1 = 2, pin2 = 3, pin3 = 9;
int analog = A0;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(analog);
  int speed = map(value, 0, 1023, 0, 255);
  Serial.print(" | Speed: ");
  Serial.println(speed);
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  analogWrite(pin3, speed);
  delay(2000);
}
# AS_ACADAMY_PROJECTS
This repository contains all the projects including minor and major project that i have created during my training program of embedded system and IOT mentorship program. 
