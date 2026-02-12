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
=========== TEST THE MODULE - IR SENSOR TEST ===========
 * Module : IR Obstacle / Proximity Sensor
 * Board  : Arduino UNO
 *
 * This code tests:
 *  1. Digital output of IR sensor
 *  2. Object detection response
 *  3. Built-in LED indication
 ************************************************************/

const int irPin  = 2;    // IR sensor OUT pin
const int ledPin = 13;   // Built-in LED

void setup() {
  Serial.begin(9600);

  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - IR SENSOR");
  Serial.println("====================================");
  Serial.println("Bring an object near the sensor...");
}

void loop() {

  int irState = digitalRead(irPin);

  if (irState == LOW) {
    Serial.println("Object Detected!");
    digitalWrite(ledPin, HIGH);
  } 
  else {
    Serial.println("No Object Detected");
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}
