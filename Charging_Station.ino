#include <IRremote.h>
//IR Transmitter
IRsend irsend1(3);
IRsend irsend2(5);
IRsend irsend3(6);

//Ultrasonic HC-SR04
int trigPin = 8;    // Trigger
int echoPin = 7;    // Echo
long duration;
int distance;

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
    delay(100);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Convert the time into a distance
  distance = (duration * 0.034)/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance <= 15){
    delay(4000);
    digitalWrite(Relay_Pin, LOW);
  }
  else{
    digitalWrite(Relay_Pin, HIGH);
  }
}
