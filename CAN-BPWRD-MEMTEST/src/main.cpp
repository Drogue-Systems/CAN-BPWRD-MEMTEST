#include <Arduino.h>
#include "N24C32.h"
#include <Wire.h>



void setup() {

  N24C32_wire_config(PA15, PB7, 400);


  Serial2.begin(115200);
  Serial2.println("start");



  delay(100);

}

void loop() {


  Serial2.println("write 0xAB to address 0x02 0x02");
  N24C32_byte_write(0x02, 0x02, 0xAB);
  delay(500);
  Serial2.println("write 0xCD to address 0x02 0x03");
  N24C32_byte_write(0x02, 0x03, 0xCD);
  delay(500);
  Serial2.println("write 0xEF to address 0x13 0x09");
  N24C32_byte_write(0x13, 0x09, 0xEF);


  byte mydata = 0x00;
  delay(1000);
  Serial2.print("read 0x02 0x02: ");
  N24C32_selective_read(0x02, 0x02, &mydata, 1);
  Serial2.println(mydata, HEX);

  mydata = 0x00;
  delay(500);
  Serial2.print("read 0x02 0x03: ");
  N24C32_selective_read(0x02, 0x03, &mydata, 1);
  Serial2.println(mydata, HEX);

  mydata = 0x00;
  delay(500);
  Serial2.print("read 0x13 0x09: ");
  N24C32_selective_read(0x13, 0x09, &mydata, 1);
  Serial2.println(mydata, HEX);


  delay(5000);

}

