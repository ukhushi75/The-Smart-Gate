#include <Servo.h>
#define Trigpin 1
#define Echopin 0
#define led 3
float distance;
int duration;
int ll = 700;
Servo servo;

void setup() {
  pinMode (Trigpin, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (Echopin, INPUT);
  pinMode(2,OUTPUT);//BUZZER
  Serial.begin(9600);
  digitalWrite (led, LOW);
  servo.attach(4);
  servo.write(0);
}

void loop() {
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration = pulseIn(Echopin, HIGH);
  distance = duration * (0.034 / 2);
  delay (ll);

  if (distance<16 && distance>=0)
  { 
    Serial.println ("Someone Is Infront Of the Sensor");
    digitalWrite (led,HIGH);
    digitalWrite(2,HIGH);  
    servo.write(90);
    
  }
    else
    {
    Serial.println ("Nobody Is Infront Of the Sensor");
    digitalWrite (led,LOW);
    digitalWrite(2,LOW);
    servo.write(0);
   }
  
}
