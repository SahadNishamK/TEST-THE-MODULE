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
=========== TEST THE MODULE - LDR SENSOR TEST ===========
 * Module : LDR Sensor (Light Dependent Resistor)
 * Board  : Arduino UNO
 *
 * Supports:
 *  - Digital-only LDR modules (3-pin)
 *  - Analog + Digital LDR modules (4-pin)
 *  - Active HIGH and Active LOW logic
 ************************************************************/

const int ldrDigitalPin = 2;    // DO pin (optional)
const int ldrAnalogPin  = A0;   // AO pin (optional)
const int ledPin        = 13;   // Built-in LED

void setup() {
  Serial.begin(9600);

  pinMode(ldrDigitalPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - LDR SENSOR");
  Serial.println("====================================");
  Serial.println("Cover the sensor or shine light...");
}

void loop() {

  bool digitalAvailable = true;
  int digitalValue = digitalRead(ldrDigitalPin);

  int analogValue = analogRead(ldrAnalogPin);

  // Determine if analog pin is actually connected
  bool analogAvailable = (analogValue != 0 && analogValue != 1023);

  Serial.println("------------------------------------");

  // ----- ANALOG OUTPUT -----
  if (analogAvailable) {
    Serial.print("Analog Value: ");
    Serial.println(analogValue);

    if (analogValue < 400) {
      Serial.println("Light Level: DARK");
    }
    else if (analogValue < 700) {
      Serial.println("Light Level: DIM");
    }
    else {
      Serial.println("Light Level: BRIGHT");
    }
  } 
  else {
    Serial.println("Analog Output: Not Available");
  }

  // ----- DIGITAL OUTPUT -----
  Serial.print("Digital Output: ");
  Serial.println(digitalValue);

  // Auto-interpret logic
  if (digitalValue == LOW) {
    Serial.println("Digital Status: LIGHT DETECTED (Active LOW)");
    digitalWrite(ledPin, HIGH);
  } 
  else {
    Serial.println("Digital Status: NO LIGHT / THRESHOLD NOT MET");
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
