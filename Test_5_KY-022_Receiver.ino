#include <IRremote.h>
#include <IRremoteInt.h>

// define input pin on Arduino 
int RECV_PIN1 = 12;
int RECV_PIN2 = 11;
int RECV_PIN3 = 10;
int RECV_PIN4 = 9;
int RECV_PIN5 = 8;

IRrecv irrecv1(RECV_PIN1);
IRrecv irrecv2(RECV_PIN2);
IRrecv irrecv3(RECV_PIN3);
IRrecv irrecv4(RECV_PIN4);
IRrecv irrecv5(RECV_PIN5);

decode_results results1, results2, results3, results4, results5; 

void setup() { 
	Serial.begin(9600); 
  // Start the receiver 
	irrecv1.enableIRIn();
  irrecv2.enableIRIn();
  irrecv3.enableIRIn();
  irrecv4.enableIRIn();
  irrecv5.enableIRIn();
} 

void loop() { 
	if (irrecv1.decode(&results1)) {
    Serial.println("Receiver 1");
		Serial.println(results1.value, HEX); 
		irrecv1.resume(); // Receive the next value 
	}
  if (irrecv2.decode(&results2)) {
    Serial.println("Receiver 2");
		Serial.println(results2.value, HEX); 
		irrecv2.resume(); // Receive the next value 
	}
  if (irrecv3.decode(&results3)) {
    Serial.println("Receiver 3");
		Serial.println(results3.value, HEX); 
		irrecv3.resume(); // Receive the next value 
	}
  if (irrecv4.decode(&results4)) {
    Serial.println("Receiver 4");
		Serial.println(results4.value, HEX); 
		irrecv4.resume(); // Receive the next value 
	}
  if (irrecv5.decode(&results5)) {
    Serial.println("Receiver 5");
		Serial.println(results5.value, HEX); 
		irrecv5.resume(); // Receive the next value 
	}
	delay (1000); // small delay to prevent reading errors
}
