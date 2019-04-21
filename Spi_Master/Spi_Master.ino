#include<SPI.h>
#define SS PA4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  digitalWrite(SS, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
   byte  MasterReceive;
   char MasterSend = 'a';
    digitalWrite(SS, LOW);
   MasterReceive = SPI.transfer(MasterSend);
   Serial.print("Receivng Data from sllave:");
   Serial.println(MasterReceive);
   digitalWrite(SS, HIGH);
}
