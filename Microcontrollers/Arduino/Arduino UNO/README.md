# Test the Module – Arduino UNO

Before testing any electronic module, sensor, or peripheral,  
it is important to verify that the **microcontroller itself is working properly**.

This repository provides a **basic self-test code for Arduino UNO**, which checks
core functionalities required for most embedded and robotics projects.

---

## 🔧 What This Test Covers

- USB & Bootloader functionality
- Serial communication
- Built-in LED (Pin 13)
- Digital I/O pins (2 to 12)
- Basic power stability

---

## 🧰 Requirements

- Arduino UNO
- USB cable
- Arduino IDE
- LED + 220Ω resistor (optional)

---

## 📂 Files

| File | Description |
|----|------------|
| `arduino_uno_test.ino` | Arduino UNO self-test code |
| `README.md` | Documentation |

---

## 🚀 How to Use

1. Connect Arduino UNO to your computer
2. Open Arduino IDE
3. Select Board: **Arduino UNO**
4. Select correct COM Port
5. Upload `arduino_uno_test.ino`
6. Open Serial Monitor at **9600 baud**

---

## Connections

| LED   | Arduino Pin | Connection Details                     |
|-------|-------------|----------------------------------------|
| LED1  | D2          | Anode → D2, Cathode → 220Ω → GND        |
| LED2  | D3          | Anode → D3, Cathode → 220Ω → GND        |
| LED3  | D4          | Anode → D4, Cathode → 220Ω → GND        |
| LED4  | D5          | Anode → D5, Cathode → 220Ω → GND        |
| LED5  | D6          | Anode → D6, Cathode → 220Ω → GND        |
| LED6  | D7          | Anode → D7, Cathode → 220Ω → GND        |
| LED7  | D8          | Anode → D8, Cathode → 220Ω → GND        |
| LED8  | D9          | Anode → D9, Cathode → 220Ω → GND        |
| LED9  | D10         | Anode → D10, Cathode → 220Ω → GND       |
| LED10 | D11         | Anode → D11, Cathode → 220Ω → GND       |
| LED11 | D12         | Anode → D12, Cathode → 220Ω → GND       |
| LED12 | D13         | Anode → D13, Cathode → 220Ω → GND       |

---

## ✅ Expected Output

- Serial messages confirming test progress
- Built-in LED blinking
- External LED blinking when connected to pins 2–12

---

## 📌 Why This Matters

Most Arduino modules depend on:
- Digital I/O
- Stable power
- Reliable serial communication

Testing the Arduino UNO first avoids **false module failures**.

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
