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
=========== TEST THE MODULE - ADXL345 TEST ===========
 * Module : ADXL345 Accelerometer
 * Board  : Arduino UNO
 *
 * This code tests:
 *  1. I2C communication
 *  2. X, Y, Z acceleration readings
 *  3. Orientation and motion response
 ************************************************************/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  Serial.begin(9600);
  Serial.println("====================================");
  Serial.println("TEST THE MODULE - ADXL345");
  Serial.println("====================================");

  if (!accel.begin()) {
    Serial.println("❌ ADXL345 not detected!");
    Serial.println("Check wiring and I2C address.");
    while (1);
  }

  Serial.println("✅ ADXL345 detected successfully");

  // Set measurement range
  accel.setRange(ADXL345_RANGE_16_G);

  Serial.print("Range set to: ");
  Serial.print(16);
  Serial.println(" G");

  delay(1000);
}

void loop() {

  sensors_event_t event;
  accel.getEvent(&event);

  Serial.print("X: ");
  Serial.print(event.acceleration.x / 9.81);
  Serial.print(" g   ");

  Serial.print("Y: ");
  Serial.print(event.acceleration.y / 9.81);
  Serial.print(" g   ");

  Serial.print("Z: ");
  Serial.print(event.acceleration.z / 9.81);
  Serial.println(" g");

  delay(500);
}
