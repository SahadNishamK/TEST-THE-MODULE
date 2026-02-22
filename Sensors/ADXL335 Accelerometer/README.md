# Test the Module – ADXL335 Accelerometer

The **ADXL335** is a **3-axis analog accelerometer** used to measure acceleration
along the **X, Y, and Z axes**. It is commonly used in **robotics, motion sensing,
tilt detection, vibration monitoring, and embedded systems projects**.

Unlike digital accelerometers, the ADXL335 provides **analog voltage outputs**
proportional to acceleration on each axis.

This test verifies that the ADXL335 is:
- Properly powered
- Producing valid analog outputs
- Responding correctly to tilt and motion

---

## 📌 Why Test the ADXL335 First?

Many issues occur due to:
- Supplying **5V instead of 3.3V**
- Incorrect analog pin connections
- Misinterpreting raw analog values
- Assuming digital-like behavior

Testing the module independently helps you:
- Confirm sensor health
- Understand axis orientation
- Validate analog signal behavior

---

## 📦 Module Overview – ADXL335

**Key Features:**
- 3-axis acceleration measurement (X, Y, Z)
- Analog voltage output
- Low power consumption
- Compact and lightweight

**Measurement Range:**
- ±3g

**Sensitivity:**
- ~300 mV per g

**Operating Voltage:**  
⚠️ **3.3V ONLY** (Not 5V tolerant)

---

## 🔌 Pin Description

| ADXL335 Pin | Description |
|------------|-------------|
| VCC | Power supply (3.3V) |
| X_OUT | X-axis analog output |
| Y_OUT | Y-axis analog output |
| Z_OUT | Z-axis analog output |
| GND | Ground |

---

## 🔌 Connections (Arduino UNO)

| ADXL335 Pin | Arduino UNO | Description |
|------------|-------------|-------------|
| VCC | 3.3V | Power (⚠️ Do NOT use 5V) |
| GND | GND | Common ground |
| X_OUT | A0 | X-axis analog input |
| Y_OUT | A1 | Y-axis analog input |
| Z_OUT | A2 | Z-axis analog input |

---

## 📂 Files in This Folder

| File | Description |
|-----|-------------|
| `adxl335_test.ino` | ADXL335 testing code |
| `README.md` | Documentation |

---

## 🧠 How the ADXL335 Works

- Each axis outputs an **analog voltage**
- At **0g**, output is approximately **VCC / 2** (~1.65V)
- Positive or negative acceleration shifts the voltage up or down
- Z-axis shows ~**1g** when the sensor is lying flat

---

## 🚀 How to Test

1. Connect the ADXL335 as per the table above  
2. Power the sensor using **3.3V only**  
3. Upload `adxl335_test.ino` to Arduino UNO  
4. Open **Serial Monitor**
   - Baud rate: **9600**
5. Tilt, rotate, or gently move the sensor  

---

## ✅ Expected Output

### Sensor lying flat (Z-axis facing up):
```
X: ~512 (1.65 V) | Y: ~512 (1.65 V) | Z: ~650 (2.1 V)
```
**When tilted:**

• One axis value increases
• Opposite axis decreases
• Z-axis changes based on orientation

**🧪 Test Results**
| Test Case              | Result   |
| ---------------------- | -------- |
| Power ON               | ✅ Passed |
| Analog reading (X/Y/Z) | ✅ Passed |
| Tilt response          | ✅ Passed |
| Serial output          | ✅ Passed |


***⚠️ Common Issues & Troubleshooting***

**❌ Readings Stuck at 0 or 1023**
*Cause:*
• Wrong supply voltage
• Sensor damaged due to 5V

*Fix:*
• Power with 3.3V only
• Replace damaged sensor

**❌ Noisy or Fluctuating Values**
*Cause:*
• Long wires
• Electrical noise

*Fix:*
```
Keep wires short
Add small delays
Use averaging if needed
```

**❌ Values Not Centered Around Midpoint**
*Cause:*
• Sensor offset (normal)
• Manufacturing tolerance

*Fix:*
``Apply software calibration offsets``

**🧠 Typical Use Cases**
• Tilt and orientation detection
• Motion sensing
• Vibration monitoring
• Gesture-based input
• Robotics balance systems

**📚 Part of the Series**

`TEST THE MODULE`
A practical testing series for:
• Microcontrollers
• Sensors
• Communication modules
• Embedded hardware

### 🛠️ License

Open-source.
Free to use, modify, and share for learning and development.

Happy building 🚀
Test before you trust.
