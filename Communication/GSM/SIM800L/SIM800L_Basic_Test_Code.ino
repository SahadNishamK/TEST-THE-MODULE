/************************************************************

░█████╗░██╗░░██╗██╗░░░██╗███████╗      ███████╗██████╗░██╗░░░██╗
██╔══██╗╚██╗██╔╝╚██╗░██╔╝╚════██║      ██╔════╝██╔══██╗██║░░░██║
███████║░╚███╔╝░░╚████╔╝░░░███╔═╝      █████╗░░██║░░██║██║░░░██║
██╔══██║░██╔██╗░░░╚██╔╝░░██╔══╝░░      ██╔══╝░░██║░░██║██║░░░██║
██║░░██║██╔╝╚██╗░░░██║░░░███████╗      ███████╗██████╔╝╚██████╔╝
╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝      ╚══════╝╚═════╝░░╚═════╝░

Instagram: https://www.instagram.com/sahadnisham.k/
LinkedIn : https://www.linkedin.com/in/sahad-nisham-k/

*************************************************************
=============== TEST THE MODULE - SIM800L Basic Test ===============
 * Module : SIM800L
 * Board  : Arduino UNO
 
 This code tests:
  1. Serial communication
  2. Built-in LED (Pin 13)
  3. Digital I/O pins (2 to 12)
 ************************************************************/


#include <SoftwareSerial.h>

int baudrate = 9600;

SoftwareSerial sim800(8, 7); // RX, TX

void setup() {
  Serial.begin(baudrate);
  sim800.begin(baudrate);

  Serial.println("===== TEST THE MODULE =====");
  Serial.println("SIM800L Basic AT Test");
  Serial.println("Type AT commands below:");
}

void loop() {

  // Send data from Serial Monitor to SIM800
  if (Serial.available()) {
    sim800.write(Serial.read());
  }

  // Read data from SIM800 and print to Serial Monitor
  if (sim800.available()) {
    Serial.write(sim800.read());
  }
}
