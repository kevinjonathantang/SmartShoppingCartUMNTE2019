void setup() {
  //initialize digital pin LED_BUILIN as an output.
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(11, HIGH);	//turns the LED on (HIGH is the voltage level)
  delay(1000)		//wait for a second
  digitalWrite(11, LOW);	//turns the LED off by making the voltage LOW
  delay(1000)		//wait for a second
}
