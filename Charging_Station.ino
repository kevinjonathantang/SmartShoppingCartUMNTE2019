#include <IRremote.h>
//IR Transmitter
IRsend irsend1(3);
IRsend irsend2(5);
IRsend irsend3(6);

//Ultrasonic HC-SR04
int trigPin = 7;    // Trigger
int echoPin = 8;    // Echo
long duration, cm;

//Relay
const int Relay_Pin = 4; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial interface

  //Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Relay
  pinMode(Relay_Pin, OUTPUT);
}

void loop() {
  irsend1.sendNEC(0xF7807F, 32);
  irsend2.sendNEC(0xF7807F, 32);
  irsend3.sendNEC(0xF7807F, 32);
  //avoid error when transferring
  delay(40);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm <= 15){
    delay(4000);
    digitalWrite(Relay_Pin, LOW);
  }
  else{
    digitalWrite(Relay_Pin, HIGH);
  }
}
