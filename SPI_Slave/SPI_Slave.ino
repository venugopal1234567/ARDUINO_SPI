#include<SPI.h>
volatile boolean received;
volatile char SlaveReceived,Slavesend;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

   pinMode(MISO,OUTPUT);                   // Sets MISO as OUTPUT (Have to Send data to Master IN (STM32F103C8)

  SPCR |= _BV(SPE);                       // Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                  // Interuupt ON is set for SPI commnucation

}

ISR (SPI_STC_vect)                        // Inerrrput routine function 
{
  SlaveReceived = SPDR;                   // Value received from master STM32F103C8 is stored in variable slavereceived
  received = true;                        // Sets received as True 
}

void loop() {
  // put your main code here, to run repeatedly:
  SPDR = 123;
  Serial.println("Master STM32 to Slave Arduino");   
  Serial.println(SlaveReceived);                   // Puts the received value from Master STM32F103C8 at Serial Monitor                   
  

}
