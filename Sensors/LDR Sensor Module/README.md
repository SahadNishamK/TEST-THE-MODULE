# Test the Module – LDR Sensor (Light Dependent Resistor)

The **LDR Sensor Module** is used to detect **light intensity** and is commonly
found in **automatic lighting systems, robotics, IoT, and embedded projects**.

An LDR changes its resistance based on light:
- **Bright light → Low resistance**
- **Darkness → High resistance**

LDR modules convert this behavior into **digital and/or analog signals** that can
be read by a microcontroller.

---

## 📌 Why Test the LDR Module First?

LDR modules vary widely in:
- Pin configuration (3-pin or 4-pin)
- Output logic (Active HIGH or Active LOW)
- Sensitivity and threshold behavior

Testing the module separately helps you:
- Identify your module type
- Understand its output behavior
- Avoid incorrect assumptions in projects

---

## 📦 Module Overview – LDR Sensor

**Main Components:**
- LDR (Light Dependent Resistor)
- Fixed resistor (voltage divider)
- Comparator (LM393 or equivalent)
- Adjustable potentiometer (digital threshold)

**Operating Voltage:**
- Typically **3.3V – 5V**

---

## 🔍 LDR Module Types

### 1️⃣ 3-Pin LDR Module (Digital Only)

**Pins:**
- VCC
- GND
- DO (Digital Output)

**Features:**
- Simple ON/OFF output
- Triggered when light crosses a set threshold
- Threshold adjusted using potentiometer

---

### 2️⃣ 4-Pin LDR Module (Analog + Digital)

**Pins:**
- VCC
- GND
- AO (Analog Output)
- DO (Digital Output)

**Features:**
- Analog output gives real light intensity
- Digital output gives threshold-based trigger
- More flexible and informative

---

## ⚠️ Active HIGH vs Active LOW (IMPORTANT)

Different LDR modules use different logic.

### 🔹 Active HIGH Module
| Output | Meaning |
|------|--------|
| HIGH (1) | Light detected |
| LOW (0) | No light |

---

### 🔹 Active LOW Module
| Output | Meaning |
|------|--------|
| LOW (0) | Light detected |
| HIGH (1) | No light |

> Always test your module to determine whether it is **Active HIGH or Active LOW**
before using it in a project.

---

## 🔌 Connections (Arduino UNO)

### ✅ Digital Output (3-Pin & 4-Pin)

| LDR Pin | Arduino UNO | Description |
|-------|------------|-------------|
| VCC | 5V | Power supply |
| GND | GND | Common ground |
| DO  | D2 | Digital output |

---

### ✅ Analog Output (4-Pin Only)

| LDR Pin | Arduino UNO |
|-------|------------|
| AO | A0 |

> If your module has no AO pin, leave A0 unconnected.

---

## 📂 Files in This Folder

| File | Description |
|-----|-------------|
| `ldr_active_high_test.ino` | Active HIGH LDR test |
| `ldr_active_low_test.ino` | Active LOW LDR test |
| `README.md` | Documentation |

---

## 🧠 What the Test Codes Do

- Read digital output from the LDR module
- Read analog light intensity (if available)
- Indicate detection using built-in LED (Pin 13)
- Print readable results to Serial Monitor

---

## 🚀 How to Test the LDR Module

1. Connect the LDR module as per tables above  
2. Upload the appropriate test code:
   - **Active HIGH** or **Active LOW**
3. Open Serial Monitor  
   - Baud rate: **9600**
4. Shine light or cover the sensor

---

## ✅ Expected Output

### 🌑 Dark Environment
```Analog Value: 120```
```Light Level: DARK```
```Digital Output: 0```

### 🔦 Bright Light
``` Analog Value: 850``` 
``` Light Level: BRIGHT``` 
``` Digital Output: 1``` 
(Exact values vary based on module and environment)

**🔧 Adjusting Sensitivity**
• Use the onboard potentiometer
• Adjust until digital output changes correctly
• Analog output remains continuous regardless of threshold

**🧪 Test Results**
Test Case	Result
• Power ON	✅ Passed
• Analog reading	✅ Passed
• Digital output	✅ Passed
• Active logic identified	✅ Passed
• LED indication	✅ Passed


**⚠️ Common Issues & Troubleshooting**
## ❌ Digital Output Always HIGH or LOW

Cause:
• Incorrect potentiometer setting
• Wrong active logic assumed

Fix:
• Adjust potentiometer
• Switch between Active HIGH and Active LOW test code

## ❌ Analog Value Not Changing

Cause:
• AO pin not connected
• Damaged LDR

Fix:
• Verify AO connection
• Test in different light conditions

## ❌ Unstable Readings

Cause:
• Flickering light sources
• Electrical noise

Fix:
• Add small delay
• Test under steady lighting

**🧠 Typical Use Cases**
• Automatic street lights
• Smart room lighting
• Light-based alarms
• Solar tracking systems
• Line detection (with calibration)

📚 Part of the Series

**Test the Module**
A practical testing series for:
• Microcontrollers
• Sensors
• Communication modules
• Embedded hardware

**🛠️ License**

This project is open-source.
• You are free to:
• Use
• Modify
• Share
• Learn from this code
• Attribution is appreciated but not required.

Test before you trust.
Happy building 🚀
