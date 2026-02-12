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
====== TEST THE MODULE - ULTRASONIC SENSOR (HC-SR04) ======
 * Module : HC-SR04 Ultrasonic Sensor
 * Board  : Arduino UNO
 *
 * This code tests:
 *  1. Trigger & Echo pins
 *  2. Distance measurement
 *  3. Serial output verification
 ************************************************************/

const int trigPin = 9;
const int echoPin = 10;
const int ledPin  = 13;   // Built-in LED (optional)

long duration;
float distanceCm;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - ULTRASONIC SENSOR");
  Serial.println("====================================");
}

void loop() {

  // Clear trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout

  if (duration == 0) {
    Serial.println("No echo detected");
    digitalWrite(ledPin, LOW);
  }
  else {
    // Distance calculation
    distanceCm = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    // LED indication if object is close
    if (distanceCm < 20) {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }

  delay(500);
}
