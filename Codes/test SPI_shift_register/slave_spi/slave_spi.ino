#include <SPI.h>
volatile boolean process;
byte i=0;
byte c;

void setup (void) {
   Serial.begin (115200);
   pinMode(MISO, OUTPUT); // have to send on master in so it set as output
   SPCR |= _BV(SPE); // turn on SPI in slave mode
   process = false;
   SPI.attachInterrupt(); // turn on interrupt
}

ISR (SPI_STC_vect){ // SPI interrupt routine
   c = SPDR; // read byte from SPI Data Register
   SPDR = i;
   process = true;
}

void loop (void) {
   if (process) {
      process = false;
      Serial.print("Received : ");
      Serial.print(c);
      Serial.print(" Next To Send : ");
      Serial.println(i);
      i++;
   }
}

