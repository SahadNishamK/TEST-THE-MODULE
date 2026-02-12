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
=========== TEST THE MODULE - SIM800L CALL TEST ===========
 * Module : SIM800L
 * Board  : Arduino UNO
 *
 * Features:
 *  1. Auto call after upload
 *  2. Manual call using Serial Monitor
 *  3. Mic & Speaker enabled
 ************************************************************/

#include <SoftwareSerial.h>

SoftwareSerial sim800(8, 7);  // RX, TX

/**************** USER CONFIGURATION ****************/

const char callNumber[] = "+919876543210";   // 🔴 CHANGE THIS ONLY

/****************************************************/

bool callSentOnce = false;

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);

  delay(3000);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - SIM800L CALL TEST");
  Serial.println("====================================");
  Serial.println("Calling automatically once...");
  Serial.println("Type CALL to dial again");
  Serial.println("Type HANG to end call");
  Serial.println("------------------------------------");

  // Basic AT test
  sim800.println("AT");
  delay(1000);

  // Enable audio
  sim800.println("AT+CHFA=0");   // Audio channel: handset
  delay(500);

  sim800.println("AT+CLVL=80");  // Speaker volume (0–100)
  delay(500);

  // Auto-call once after upload
  makeCall();
  callSentOnce = true;
}

void loop() {

  // Serial Monitor commands
  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "CALL") {
      makeCall();
    }
    else if (command == "HANG") {
      hangCall();
    }
    else {
      Serial.println("Unknown command.");
      Serial.println("Use: CALL or HANG");
    }
  }
}

void makeCall() {

  Serial.println("Dialing number...");

  sim800.print("ATD");
  sim800.print(callNumber);
  sim800.println(";");   // Semicolon = voice call

  delay(1000);
}

void hangCall() {

  Serial.println("Hanging up call...");
  sim800.println("ATH");
  delay(500);
}
