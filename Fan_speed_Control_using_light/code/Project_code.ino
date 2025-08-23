int pin1 = 2,pin2 = 3,pin3 = 9;
int analog = A0;
void setup()
{
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(analog);
  int speed = map(value,0,1023,0,255);
  Serial.print(" | Speed: ");
  Serial.println(speed);
  
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  analogWrite(pin3,speed);
  delay(2000);
}
