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
=========== TEST THE MODULE - SIM800L SMS TEST ============
 * Module : SIM800L
 * Board  : Arduino UNO
 *
 * Features:
 *  1. Auto SMS sent after upload
 *  2. Manual resend using Serial Monitor (SEND)
 *  3. Clean GSM text mode test
 ************************************************************/

#include <SoftwareSerial.h>

SoftwareSerial sim800(8, 7); // RX, TX

/**************** USER CONFIGURATION ****************/

const char receiverNumber[] = "+919876543210";  // 🔴 CHANGE THIS ONLY

/****************************************************/

bool smsSentOnce = false;

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);

  delay(3000);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - SIM800L SMS TEST");
  Serial.println("====================================");
  Serial.println("SMS will be sent automatically once.");
  Serial.println("Type SEND to send SMS again.");
  Serial.println("Baud Rate: 9600");
  Serial.println("------------------------------------");

  // Basic GSM init
  sim800.println("AT");
  delay(1000);

  sim800.println("AT+CMGF=1");   // Set SMS to Text Mode
  delay(1000);

  // Auto-send once after upload
  sendSMS();
  smsSentOnce = true;
}

void loop() {

  // Listen for Serial Monitor commands
  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "SEND") {
      sendSMS();
    }
    else {
      Serial.println("Unknown command. Type SEND");
    }
  }
}

void sendSMS() {

  Serial.println("Sending SMS...");

  sim800.print("AT+CMGS=\"");
  sim800.print(receiverNumber);
  sim800.println("\"");
  delay(1000);

  sim800.println("Congrats!");
  sim800.println("Your GSM module works perfectly.");
  sim800.println("");
  sim800.println("");
  sim800.println("=== TEST THE MODULE ===");
  sim800.println("------------------------------------------------------");
  sim800.println("Follow for more embedded hacks:");
  sim800.println("YouTube: https://www.youtube.com/@SahadNisham.K");
  sim800.println("Instagram: https://www.instagram.com/sahadnisham.k/");
  sim800.println("Instagram: https://www.instagram.com/axyz_edu/");
  sim800.println("LinkedIn: https://www.linkedin.com/in/sahad-nisham-k/");
  sim800.println("");
  sim800.println("Keep Building!");

  delay(500);

  sim800.write(26);  // CTRL+Z → Send SMS
  delay(5000);

  Serial.println("SMS sent successfully.");
  Serial.println("Type SEND to send again.");
}