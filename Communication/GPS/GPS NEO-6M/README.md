# 📡 Test the Module – GPS NEO-6M

Before integrating GPS into any robotics or IoT project,  
it is important to verify that the **GPS module is receiving and parsing satellite data correctly**.

This guide provides a basic working test for the NEO-6M GPS module using Arduino UNO.

---

## 🔍 About the NEO-6M GPS Module

The **NEO-6M** is a popular GPS receiver module based on the u-blox NEO-6M chipset.  
It receives signals from GPS satellites and calculates:

- Latitude  
- Longitude  
- Altitude  
- Speed  
- Number of satellites connected  

It communicates using **UART (Serial Communication)** and outputs data in **NMEA sentence format**.

---

## ⚙️ Basic Specifications

- Chipset: u-blox NEO-6M  
- Communication: UART (Serial)  
- Default Baud Rate: 9600  
- Operating Voltage: 3.3V (Most breakout boards support 5V input)  
- Output Format: NMEA sentences  
- Position Accuracy: ~2.5 meters (open sky)  

---

## 🧠 How It Works

1. The GPS module receives signals from multiple satellites.
2. It calculates its position using trilateration.
3. It sends NMEA data through the TX pin.
4. The microcontroller reads and parses this data.
5. Latitude, longitude, and other parameters are extracted.

---

## 🔌 Connections (Arduino UNO)

> ⚠️ Important: RX/TX connections are crossed.

| GPS NEO-6M Pin | Arduino UNO Pin | Connection Details |
|---------------|-----------------|-------------------|
| VCC           | 5V              | Power supply (most breakout boards accept 5V) |
| GND           | GND             | Common ground |
| TX            | D4              | GPS TX → Arduino RX (SoftwareSerial RX) |
| RX            | D3              | GPS RX → Arduino TX (SoftwareSerial TX) |

---

## 📦 Required Library

Install the following library in Arduino IDE:

Library Name: TinyGPSPlus  
Author: Mikal Hart  

Arduino IDE → Sketch → Manage Libraries → Search "TinyGPS++" → Install

---

## 🧪 What This Test Verifies

- UART communication
- NMEA data reception
- Satellite lock
- Latitude and longitude parsing
- Overall module health

---

## 🚀 How to Test

1. Connect the module as per the table above.
2. Install the TinyGPSPlus library.
3. Upload the provided test code.
4. Open Serial Monitor.
5. Set baud rate to **9600**.
6. Move to an open outdoor area or near a window.

> First GPS fix may take 30–90 seconds.

---

## 💡 LED Indicator on Module

- Fast blinking → Searching for satellites  
- Slow blinking (1 sec interval) → GPS fix acquired  

---

## ✅ Expected Output

Once satellite lock is achieved:

GPS Signal Detected!
Latitude: 11.258753
Longitude: 75.780410
Satellites: 7
Altitude (m): 23.40
Speed (km/h): 0.00


---

## ❌ Troubleshooting

| Problem | Possible Cause |
|----------|---------------|
| No output | Wrong RX/TX wiring |
| Garbage characters | Wrong baud rate |
| No satellite lock | Indoor testing |
| "No GPS detected" message | Wiring or power issue |
| Data not updating | Poor satellite visibility |

---

## 🌍 Common Use Cases

- Vehicle tracking systems  
- Accident alert systems  
- Location-based IoT devices  
- Drone navigation  
- Outdoor robotics  

---

## 📌 Why This Test Matters

Many IoT and tracking projects depend on accurate location data.

Testing the GPS module independently:
- Avoids false debugging
- Confirms satellite reception
- Ensures proper serial communication
- Validates hardware before integration

---

## 📚 Part of the Series

**Test the Module**  
A practical embedded systems testing series covering:

- Microcontrollers  
- Sensors  
- Communication modules  
- Drivers  
- Power modules  

All test codes, wiring references, and documentation are shared open-source and free.

---

## 🛠️ License

Open-source. Free to use, modify, and share.
