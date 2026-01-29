# Test the Module – Arduino Nano

Before testing any electronic module, sensor, or peripheral,  
it is important to verify that the **microcontroller itself is working properly**.

This repository provides a **basic self-test code for Arduino Nano**, which checks
core functionalities required for most embedded and robotics projects.

---

## 🔧 What This Test Covers

- USB & Bootloader functionality
- Serial communication
- Built-in LED (Pin 13)
- Digital I/O pins
- Basic power stability

---

## 🧰 Requirements

- Arduino Nano
- USB cable (Mini-USB / Micro-USB depending on board)
- Arduino IDE
- LED + 220Ω resistor (optional)

---

## 📂 Files

| File | Description |
|------|------------|
| `arduino_nano_test.ino` | Arduino Nano self-test code |
| `README.md` | Documentation |

---

## 🚀 How to Use

1. Connect Arduino Nano to your computer
2. Open Arduino IDE
3. Select Board: **Arduino Nano**
4. Select Processor: **ATmega328P**  
   *(or ATmega328P (Old Bootloader) if upload fails)*
5. Select correct COM Port
6. Upload `arduino_nano_test.ino`
7. Open Serial Monitor at **9600 baud**

---

## 🔌 Connections

| LED   | Arduino Nano Pin | Connection Details                     |
|-------|------------------|----------------------------------------|
| LED1  | D2               | Anode → D2, Cathode → 220Ω → GND        |
| LED2  | D3               | Anode → D3, Cathode → 220Ω → GND        |
| LED3  | D4               | Anode → D4, Cathode → 220Ω → GND        |
| LED4  | D5               | Anode → D5, Cathode → 220Ω → GND        |
| LED5  | D6               | Anode → D6, Cathode → 220Ω → GND        |
| LED6  | D7               | Anode → D7, Cathode → 220Ω → GND        |
| LED7  | D8               | Anode → D8, Cathode → 220Ω → GND        |
| LED8  | D9               | Anode → D9, Cathode → 220Ω → GND        |
| LED9  | D10              | Anode → D10, Cathode → 220Ω → GND       |
| LED10 | D11              | Anode → D11, Cathode → 220Ω → GND       |
| LED11 | D12              | Anode → D12, Cathode → 220Ω → GND       |
| LED12 | D13              | Anode → D13, Cathode → 220Ω → GND       |

> Tip: You can use **one LED** and move the anode wire across pins D2–D13.

---

## ✅ Expected Output

- Serial messages confirming test progress
- Built-in LED blinking on pin 13
- External LED blinking when connected to digital pins

---

## 🔍 Arduino Nano vs Arduino UNO (Key Differences)

| Feature | Arduino UNO | Arduino Nano |
|------|-------------|--------------|
| Form factor | Large | Compact |
| Breadboard friendly | ❌ | ✅ |
| USB Type | Type-B | Mini / Micro USB |
| I/O Voltage | 5V | 5V |
| MCU | ATmega328P | ATmega328P |
| Clock Speed | 16 MHz | 16 MHz |
| Best for | Prototyping | Embedded / compact builds |

Both boards run **the same code**, but Nano is preferred where **space is limited**.

---

## 📌 Common Use Cases for Arduino Nano

- Breadboard-based prototyping
- Compact robotics projects
- Embedded IoT systems
- Permanent installations
- Sensor-heavy applications with limited space

---

## 📌 Why This Matters

Most Arduino modules depend on:
- Digital I/O
- Stable power
- Reliable serial communication

Testing the Arduino Nano first avoids **false module failures** and
ensures your controller is ready for module integration.

---

## 📚 Part of the Series

**Test the Module**  
A practical testing series for:
- Microcontrollers
- Sensors
- Communication modules
- Embedded hardware

---

## 🛠️ License

Open-source. Free to use, modify, and share.
