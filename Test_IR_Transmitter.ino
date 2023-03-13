#include <IRremote.h>
#include <IRremoteInt.h>

IRsend irsend(3);

void setup()
{
    Serial.begin(9600); // Initialize serial interface
}

void loop() 
{
    for (int i = 0; i < 3; i++) {  //send signal 3 times
       irsend.sendNEC(0xF7807F, 32); // ir code 32-bit
       delay(40);
   }
   delay(2000); //2 seconds break
}
