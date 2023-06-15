#include <IRremote.h>
#include <IRremoteInt.h>
#include <AFMotor.h>
#include <NewPing.h>
#define Max_Distance 200

//Ultrasonik
int TriggerPin = 37;
int EchoPin = 35;
long duration;
int c_distance;
NewPing sonar(TriggerPin, EchoPin, Max_Distance);

//Motor
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//KY-022 Receiver
//Depan
const int receiver1 = 32;
const int receiver2 = 34;

//Kiri
const int receiver3 = 36;
const int receiver4 = 38;

//Kanan
const int receiver5 = 30;
const int receiver6 = 28;

IRrecv irrecv1(receiver1);
IRrecv irrecv2(receiver2);
IRrecv irrecv3(receiver3);
IRrecv irrecv4(receiver4);
IRrecv irrecv5(receiver5);
IRrecv irrecv6(receiver6);

decode_results results1, results2, results3, 
results4, results5, results6;

void setup(){
    Serial.begin(9600);
    // Infrared receiver will start
     irrecv1.enableIRIn();
     irrecv2.enableIRIn();
     irrecv3.enableIRIn();
     irrecv4.enableIRIn();
     irrecv5.enableIRIn();
     irrecv6.enableIRIn();
    
    //If it blinks, it will send the data
    irrecv1.blink13(true);
    irrecv2.blink13(true);
    irrecv3.blink13(true);
    irrecv4.blink13(true);
    irrecv5.blink13(true);
    irrecv6.blink13(true);
}

void loop() {
    delay(100);
    unsigned int uS = sonar.ping();
    pinMode(EchoPin,OUTPUT);
    digitalWrite(EchoPin,LOW);
    pinMode(EchoPin,INPUT);
    Serial.print("Ping: ");
    Serial.print(uS / US_ROUNDTRIP_CM);
    Serial.println("cm");
    
    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(5);
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(TriggerPin, LOW);
    duration = pulseIn(EchoPin, HIGH);
    c_distance = (duration * 0.034)/2;
    Serial.println(c_distance);

    //Salah Satu Bagian 
    if (irrecv1.decode(&results1)) {
         Maju();
         irrecv1.resume();
    }

    if (irrecv2.decode(&results2)) {
         Maju();
         irrecv2.resume();
    }

    if (irrecv3.decode(&results3)) {
         KiriCepat();
         irrecv3.resume();
    }

    if (irrecv4.decode(&results4)) {
        KiriCepat();
        irrecv4.resume();
    }
    
    if (irrecv5.decode(&results5)) {
         KananCepat();
         irrecv5.resume();
    }

    if (irrecv6.decode(&results6)) {
         KananCepat();
         irrecv6.resume();
    }

    //Bagian Depan
     if (irrecv1.decode(&results1) && irrecv2.decode(&results2)) {
         Maju();
         irrecv1.resume();
         irrecv2.resume();
     }

    // //Bagian Kiri
     if (irrecv3.decode(&results3) && irrecv4.decode(&results4)) {
         KiriCepat();
         irrecv3.resume();
         irrecv4.resume();
     }

    //Bagian Kanan
     if (irrecv5.decode(&results5) && irrecv6.decode(&results6)) {
         KananCepat();
         irrecv5.resume();
         irrecv6.resume();
     }

    // //Satu Bagian Depan Satu dan Kiri
     if (irrecv1.decode(&results1) && irrecv3.decode(&results3)) {
         KiriCepat();
         irrecv1.resume();
         irrecv3.resume();
     }

    // //Satu Bagian Depan dan Satu Kanan
     if (irrecv2.decode(&results2) && irrecv5.decode(&results5)) {
         KananCepat();
         irrecv2.resume();
         irrecv5.resume();
     }

    // //Bagian Depan dan Satu Kiri
     if (irrecv1.decode(&results1) && irrecv2.decode(&results2) && irrecv3.decode(&results3)) {
         KiriPelan();
         irrecv1.resume();
         irrecv2.resume();
         irrecv3.resume();
     }

    // //Bagian Depan dan Satu Kanan
     if (irrecv1.decode(&results1) && irrecv2.decode(&results2) && irrecv5.decode(&results5)) {
         KananPelan();
         irrecv1.resume();
         irrecv2.resume();
         irrecv5.resume();
     }
}

void Maju(){
  if(c_distance <= 50){
          motor1.run(BACKWARD);
          motor1.setSpeed(40);
          motor2.run(BACKWARD); 
          motor2.setSpeed(40);
          motor3.run(BACKWARD);
          motor3.setSpeed(40);
          motor4.run(BACKWARD);
          motor4.setSpeed(40);
  }
  else if((c_distance <= 10)){
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          motor3.run(RELEASE);
          motor4.run(RELEASE);
  }
  else{
          motor1.run(BACKWARD);
          motor1.setSpeed(120);
          motor2.run(BACKWARD);
          motor2.setSpeed(120);
          motor3.run(BACKWARD);
          motor3.setSpeed(120);
          motor4.run(BACKWARD);
          motor4.setSpeed(120);
  }
}

void KiriPelan(){
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor2.setSpeed(180);
  motor3.run(BACKWARD);
  motor3.setSpeed(180);
  motor4.run(RELEASE);
}

void KiriCepat(){
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  motor3.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.run(RELEASE);
}

void KananPelan(){
  motor1.run(BACKWARD);
  motor1.setSpeed(180);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
  motor4.setSpeed(180);
}

void KananCepat(){
  motor1.run(BACKWARD);
  motor1.setSpeed(200);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
  motor4.setSpeed(200);
}
