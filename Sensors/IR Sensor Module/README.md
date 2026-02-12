# Test the Module – IR Sensor (Obstacle / Proximity)

The **IR Sensor Module** is a simple and widely used sensor for **object detection**
and **proximity sensing**. It is commonly used in **robotics, automation, and embedded
systems projects** such as line follower robots, obstacle avoidance robots, and
object counters.

This test verifies that the IR sensor module is:
- Properly powered
- Producing correct digital output
- Responding reliably to nearby objects

---

## 📌 Why Test the IR Sensor First?

IR sensors are often misunderstood and misused due to:
- Active LOW output logic
- Incorrect potentiometer adjustment
- Ambient light interference
- Assuming the sensor works without verification

Testing the module first helps you:
- Confirm the sensor is functional
- Understand its detection logic
- Avoid false readings in actual projects

---

## 📦 Module Overview – IR Sensor

**Main Components:**
- IR LED (Infrared Transmitter)
- IR Receiver (Photodiode / Phototransistor)
- Comparator (LM393 or equivalent)
- Adjustable potentiometer

**Operating Voltage:**
- **3.3V – 5V**

**Output Type:**
- Digital (HIGH / LOW)

---

## ⚠️ Active LOW Sensor – Important Concept

This IR sensor module is an **Active LOW** device.

### What does *Active LOW* mean?

| Output State | Meaning |
|-------------|--------|
| **LOW (0)** | Object **DETECTED** |
| **HIGH (1)** | **NO object** detected |

Even though detection occurs, the output pin goes **LOW**.

> Always keep this logic in mind while writing conditions in code.

---

## 🔌 Connections (Arduino UNO)

| IR Sensor Pin | Arduino UNO | Description |
|--------------|------------|-------------|
| VCC | 5V | Power supply |
| GND | GND | Common ground |
| OUT | D2 | Digital output |

---

## 📂 Files in This Folder

| File | Description |
|-----|-------------|
| `ir_sensor_test.ino` | IR sensor testing code |
| `README.md` | Documentation |

---

## 🧠 What This Test Code Does

- Reads the digital output from the IR sensor
- Prints detection status to the Serial Monitor
- Turns ON the built-in LED (Pin 13) when an object is detected
- Turns OFF the LED when no object is present

---

## 🚀 How to Test

1. Make the connections as per the table above  
2. Upload `ir_sensor_test.ino` to Arduino UNO  
3. Open **Serial Monitor**
   - Baud rate: **9600**
4. Bring your hand or any object near the sensor  

---

## ✅ Expected Output

### When **NO object** is present:

```No Object Detected```
```Built-in LED → OFF```

When an object is detected:
```Object Detected!```
```Built-in LED → ON```

**🧪 Test Results**
Test Condition	Result
• Power ON	✅ Passed
• Serial output readable	✅ Passed
• Object detection	✅ Passed
• LED indication	✅ Passed
• Response time	Instant

**🔧 Adjusting Detection Range**
• Use the potentiometer on the IR module
• Rotate clockwise or counter-clockwise slowly
• Adjust until detection works reliably at the desired distance
• Test with both light and dark surfaces

### ⚠️ Common Issues & Troubleshooting

**❌ Always Detecting Object**
Possible Causes:
• Potentiometer set too sensitive
• Strong ambient IR light (sunlight)

## Fix:
• Reduce sensitivity using potentiometer
• Test indoors or shield from sunlight

**❌ Never Detecting Object**
 Possible Causes:
• Potentiometer not adjusted
• Object too far from sensor
• Loose or incorrect wiring

## Fix:
• Adjust potentiometer slowly
• Bring object closer
• Recheck VCC, GND, and OUT connections

**❌ Unstable / Flickering Output**
Possible Causes:
• Noisy power supply
• Reflective or uneven surfaces

## Fix:
• Ensure stable power
• Test with matte surfaces
• Add small delay in code if needed

🧠 Typical Use Cases
• Obstacle avoidance robots
• Line follower robots
• Object counting systems
• Automatic doors
• Edge and boundary detection

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

