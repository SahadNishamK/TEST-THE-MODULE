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
====== TEST THE MODULE - ADXL335 ACCELEROMETER ======
 * Module : ADXL335 (Analog 3-Axis Accelerometer)
 * Board  : Arduino UNO
 *
 * This code tests:
 *  1. X, Y, Z analog outputs
 *  2. Sensor response to tilt and motion
 *  3. Serial output verification
 ************************************************************/

const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

const float referenceVoltage = 3.3;   // ADXL335 uses 3.3V

void setup() {
  Serial.begin(9600);

  Serial.println("====================================");
  Serial.println("TEST THE MODULE - ADXL335");
  Serial.println("====================================");
  Serial.println("Tilt or move the sensor...");
}

void loop() {

  int xRaw = analogRead(xPin);
  int yRaw = analogRead(yPin);
  int zRaw = analogRead(zPin);

  // Convert ADC values to voltage
  float xVolt = (xRaw * referenceVoltage) / 1023.0;
  float yVolt = (yRaw * referenceVoltage) / 1023.0;
  float zVolt = (zRaw * referenceVoltage) / 1023.0;

  Serial.print("X: ");
  Serial.print(xRaw);
  Serial.print(" (");
  Serial.print(xVolt, 2);
  Serial.print(" V)");

  Serial.print(" | Y: ");
  Serial.print(yRaw);
  Serial.print(" (");
  Serial.print(yVolt, 2);
  Serial.print(" V)");

  Serial.print(" | Z: ");
  Serial.print(zRaw);
  Serial.print(" (");
  Serial.print(zVolt, 2);
  Serial.println(" V)");

  delay(300);
}
