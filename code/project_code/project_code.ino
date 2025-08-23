// Two-Way Traffic Light using 2 RGB LEDs (Common Cathode)
// One RGB LED = Direction A
// Another RGB LED = Direction B
// Yellow = Red + Green ON together

// ==== TIME SETTINGS (in milliseconds) ====
const unsigned long T_GREEN  = 10000; // 5 seconds green time
const unsigned long T_YELLOW = 5000; // 2 seconds yellow time

// ==== PIN MAPPING ====
// Direction A (First RGB LED)
const int A_R = 2;  // Red pin of LED A
const int A_G = 4;  // Green pin of LED A
const int A_B = 3;  // Blue pin of LED A (not used here)

// Direction B (Second RGB LED)
const int B_R = 5;  // Red pin of LED B
const int B_G = 7;  // Green pin of LED B
const int B_B = 6;  // Blue pin of LED B (not used here)

// === Helper: Turn ON or OFF any color ===
// For Common Cathode: HIGH = ON, LOW = OFF
void LED_ON (int pin) 
{
  digitalWrite(pin, HIGH);
}
void LED_OFF(int pin) 
{ 
  digitalWrite(pin, LOW);  
}

// === Function to set color of one RGB LED ===
// r,g,b = 1 (ON) or 0 (OFF)
void setColor(int rPin, int gPin, int bPin, int r, int g, int b)
{
  if (r) LED_ON(rPin); else LED_OFF(rPin);
  if (g) LED_ON(gPin); else LED_OFF(gPin);
  if (b) LED_ON(bPin); else LED_OFF(bPin);
}

// === Shortcuts for each LED ===
void setA(int r, int g, int b) 
{ 
  setColor(A_R, A_G, A_B, r, g, b); 
}
void setB(int r, int g, int b)
{ 
  setColor(B_R, B_G, B_B, r, g, b);
}

// === Function to turn OFF both LEDs ===
void allOff() {
 
  setA(0,0,0);
  setB(0,0,0);
}

void setup() {
 
  // Define all pins as output
  pinMode(A_R, OUTPUT); pinMode(A_G, OUTPUT); pinMode(A_B, OUTPUT);
  pinMode(B_R, OUTPUT); pinMode(B_G, OUTPUT); pinMode(B_B, OUTPUT);
  
  allOff(); // Start with all LEDs OFF
}

void loop() {
  
  // STEP 1: Direction A = GREEN, Direction B = RED
  setA(0,1,0);  // A = Green
  setB(1,0,0);  // B = Red
  delay(T_GREEN);

  // STEP 2: Both = YELLOW
  setA(1,1,0);  // A = Yellow
  setB(1,1,0);  // B = Yellow
  delay(T_YELLOW);

  // STEP 3: Direction A = RED, Direction B = GREEN
  setA(1,0,0);  // A = Red
  setB(0,1,0);  // B = Green
  delay(T_GREEN);

  // STEP 4: Both = YELLOW
  setA(1,1,0);  // A = Yellow
  setB(1,1,0);  // B = Yellow
  delay(T_YELLOW);

  // Loop repeats
}

