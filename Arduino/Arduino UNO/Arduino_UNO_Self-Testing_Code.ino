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
=============== TEST THE MODULE - Arduino UNO ===============
 * Arduino UNO Basic Self-Test Code
 * Board      : Arduino UNO
 
 This code tests:
  1. Serial communication
  2. Built-in LED (Pin 13)
  3. Digital I/O pins (2 to 12)
 ************************************************************/

const int ledPin = 13;          // Built-in LED pin
int testPins[] = {2,3,4,5,6,7,8,9,10,11,12};
int totalPins = 11;
int duration = 1000;              // LED ON-OFF Duration

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial);  // Wait for Serial Monitor (important for some systems)

  Serial.println("===== TEST THE MODULE =====");
  Serial.println("Arduino UNO Self-Test Started");
  Serial.println("----------------------------");

  // Built-in LED setup
  pinMode(ledPin, OUTPUT);

  // Set test pins as OUTPUT initially
  for (int i = 0; i < totalPins; i++) {
    pinMode(testPins[i], OUTPUT);
  }

  Serial.println("Setup complete.\n");
}

void loop() {

  // 1. Built-in LED Test
  Serial.println("Testing Built-in LED (Pin 13)");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  Serial.println("Built-in LED test done.\n");

  // 2. Digital Pin Test
  Serial.println("Testing Digital Pins (2–12)");

  for (int i = 0; i < totalPins; i++) {
    int pin = testPins[i];

    Serial.print("Pin ");
    Serial.print(pin);
    Serial.println(" -> HIGH");

    digitalWrite(pin, HIGH);
    delay(duration);

    Serial.print("Pin ");
    Serial.print(pin);
    Serial.println(" -> LOW");

    digitalWrite(pin, LOW);
    delay(duration);
  }

  Serial.println("Digital pin test completed.\n");

  // 3. Loop delay
  Serial.println("Test cycle complete. Restarting in 5 seconds...\n");
  delay(5000);
}
