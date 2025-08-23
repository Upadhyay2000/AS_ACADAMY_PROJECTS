# 🚦 Two-Way Traffic Light Control System using Arduino and RGB LEDs

## 📌 Project Overview
This project simulates a **two-way traffic light control system** using two RGB LEDs and an **Arduino Uno**.  
Each RGB LED represents traffic signals for one direction. The lights follow the standard sequence:

1. **Direction A = Green, Direction B = Red**  
2. **Both = Yellow** (transition state)  
3. **Direction A = Red, Direction B = Green**  
4. **Both = Yellow** (transition state)  

The sequence keeps repeating, just like a real-world traffic light system.

---

## 🎯 Aim of the Project
To design and implement a traffic light controller using Arduino and RGB LEDs that demonstrates the working of a real traffic signal system.

---

## 🎯 Purpose
- To learn **basic embedded system concepts** like digital outputs, timing control, and LED interfacing.  
- To simulate **real-world traffic control** using simple hardware.  
- To build a foundation for **smart traffic systems** that can later include sensors and pedestrian controls.  

---

## 🔧 Applications
- Educational demonstration of traffic lights.  
- Beginner-friendly Arduino project for learning digital electronics.  
- Foundation for advanced **smart traffic management systems**.  
- Can be extended with **sensors, pedestrian buttons, or IoT**.  

---

## 🛠️ Components Required
| S. No. | Quantity | Component |
|--------|----------|-----------|
| 1 | 1 | Arduino Uno |
| 2 | 2 | RGB LED (Common Cathode) |
| 3 | 6 | 220Ω Resistors |
| 4 | 1 | Breadboard |
| 5 | As required | Jumper Wires |


---

## 💡 Key Concepts
- **Traffic Light Sequencing**: Standard order Green → Yellow → Red.  
- **RGB LED**: Combines Red, Green, and Blue in one LED.  
- **Common Cathode RGB LED**: Long pin → GND; HIGH = ON.  
- **Common Anode RGB LED**: Long pin → +5V; LOW = ON.  
- **Yellow Color**: Achieved by turning ON Red + Green together.  
- **Timing Control**: Managed using Arduino’s `delay()` function.  

---

## ⚡ Circuit Diagram
> Two RGB LEDs connected to Arduino digital pins through resistors.  
> Common pins of both LEDs connected to **GND (Common Cathode type)**.  

*(Insert your circuit diagram image here: e.g. `circuit.png`)*

---

## 🖥️ Arduino Code

```cpp
const int A_R = 2, A_G = 3, A_B = 4;
const int B_R = 5, B_G = 6, B_B = 7;

const unsigned long T_GREEN = 5000;
const unsigned long T_YELLOW = 2000;

void setup() {
  pinMode(A_R, OUTPUT); pinMode(A_G, OUTPUT); pinMode(A_B, OUTPUT);
  pinMode(B_R, OUTPUT); pinMode(B_G, OUTPUT); pinMode(B_B, OUTPUT);
}

void loop() {
  // Step 1: A = Green, B = Red
  digitalWrite(A_G, HIGH); digitalWrite(A_R, LOW);
  digitalWrite(B_R, HIGH); digitalWrite(B_G, LOW);
  delay(T_GREEN);

  // Step 2: Both Yellow
  digitalWrite(A_R, HIGH); digitalWrite(A_G, HIGH);
  digitalWrite(B_R, HIGH); digitalWrite(B_G, HIGH);
  delay(T_YELLOW);

  // Step 3: A = Red, B = Green
  digitalWrite(A_R, HIGH); digitalWrite(A_G, LOW);
  digitalWrite(B_G, HIGH); digitalWrite(B_R, LOW);
  delay(T_GREEN);

  // Step 4: Both Yellow
  digitalWrite(A_R, HIGH); digitalWrite(A_G, HIGH);
  digitalWrite(B_R, HIGH); digitalWrite(B_G, HIGH);
  delay(T_YELLOW);
}
