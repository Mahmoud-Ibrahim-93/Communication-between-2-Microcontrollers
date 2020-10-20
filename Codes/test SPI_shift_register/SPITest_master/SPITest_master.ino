#include <SPI.h>
byte c,d;
void setup (void) {
  
   Serial.begin(115200); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin ();
   SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8
   Serial.println(sizeof SPDR);
   delay(1000);

}

void loop (void) {
   digitalWrite(SS, LOW); // enable Slave Select
   // send test string
      SPI.transfer (c);
      Serial.print("Sent :");
      Serial.print(c++);   
      d=SPDR;
      Serial.print("Received :");
      Serial.println(d);
   
   digitalWrite(SS, HIGH); // disable Slave Select
   delay(2000);
}
