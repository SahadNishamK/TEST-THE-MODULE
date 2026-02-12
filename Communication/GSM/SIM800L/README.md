# Test the Module – SIM800L GSM Module

The **SIM800L** is a compact GSM/GPRS module that enables **SMS, voice calls, and data communication** using a standard SIM card.

This directory is part of the **Test the Module** series and focuses on **verifying the SIM800L module step-by-step** before using it in real projects.

---

## 📌 Why Test SIM800L First?

SIM800L is powerful but **very sensitive to power and wiring issues**.  
Most GSM failures are caused by:
- Insufficient current
- Wrong voltage
- Incorrect baud rate
- Improper initialization

These test codes help you:
- Confirm the module is alive
- Verify serial communication
- Test SMS sending
- Test voice calling with mic & speaker

---

## 📦 Module Overview – SIM800L

**Features:**
- GSM 850 / 900 / 1800 / 1900 MHz
- SMS (Send / Receive)
- Voice Calls
- GPRS (TCP/HTTP)
- AT command interface
- External microphone & speaker support

**Operating Voltage:**  
⚠️ **3.7V – 4.2V ONLY**

**Peak Current:**  
⚠️ Up to **2A during transmission**

---

## 🔌 Hardware Connections (Arduino UNO)

### Power (CRITICAL ⚠️)

| SIM800L Pin | Connection |
|------------|------------|
| VCC | 3.7–4.2V external supply (Li-ion / buck converter) |
| GND | Common ground with Arduino |

> ❌ Do NOT power SIM800L from Arduino 5V or 3.3V  
> ✅ Use a **1000µF capacitor** across VCC and GND  

---

### Serial Communication

| SIM800L Pin | Arduino UNO |
|------------|-------------|
| TXD | D8 |
| RXD | D7 |

*(SoftwareSerial is used in all test codes)*

---

### Audio (For Call Test)

| SIM800L Pin | Connection |
|------------|------------|
| MIC+ / MIC− | External microphone |
| SPK+ / SPK− | External 8Ω speaker |

---

## 📂 Test Codes Included

This directory contains **three independent test programs**.

---

## 1️⃣ SIM800L Basic AT Command Test

### 📄 File Purpose
Used to verify:
- Serial communication
- Correct baud rate
- Module responsiveness

### 🧠 What It Does
- Acts as a **serial bridge**
- Anything typed in Serial Monitor is sent to SIM800L
- SIM800L responses are printed back

### 🧪 How to Use
1. Upload **Code 1**
2. Open Serial Monitor  
   - Baud rate: `9600`
   - Line ending: `Both NL & CR`
3. Type:
# Test the Module – SIM800L GSM Module

The **SIM800L** is a compact GSM/GPRS module that enables **SMS, voice calls, and data communication** using a standard SIM card.

This directory is part of the **Test the Module** series and focuses on **verifying the SIM800L module step-by-step** before using it in real projects.

---

## 📌 Why Test SIM800L First?

SIM800L is powerful but **very sensitive to power and wiring issues**.  
Most GSM failures are caused by:
- Insufficient current
- Wrong voltage
- Incorrect baud rate
- Improper initialization

These test codes help you:
- Confirm the module is alive
- Verify serial communication
- Test SMS sending
- Test voice calling with mic & speaker

---

## 📦 Module Overview – SIM800L

**Features:**
- GSM 850 / 900 / 1800 / 1900 MHz
- SMS (Send / Receive)
- Voice Calls
- GPRS (TCP/HTTP)
- AT command interface
- External microphone & speaker support

**Operating Voltage:**  
⚠️ **3.7V – 4.2V ONLY**

**Peak Current:**  
⚠️ Up to **2A during transmission**

---

## 🔌 Hardware Connections (Arduino UNO)

### Power (CRITICAL ⚠️)

| SIM800L Pin | Connection |
|------------|------------|
| VCC | 3.7–4.2V external supply (Li-ion / buck converter) |
| GND | Common ground with Arduino |

> ❌ Do NOT power SIM800L from Arduino 5V or 3.3V  
> ✅ Use a **1000µF capacitor** across VCC and GND  

---

### Serial Communication

| SIM800L Pin | Arduino UNO |
|------------|-------------|
| TXD | D8 |
| RXD | D7 |

*(SoftwareSerial is used in all test codes)*

---

### Audio (For Call Test)

| SIM800L Pin | Connection |
|------------|------------|
| MIC+ / MIC− | External microphone |
| SPK+ / SPK− | External 8Ω speaker (0.25W to 1W) |

---

## 📂 Test Codes Included

This directory contains **three independent test programs**.

---

## 1️⃣ SIM800L Basic AT Command Test

### 📄 File Purpose
Used to verify:
- Serial communication
- Correct baud rate
- Module responsiveness

### 🧠 What It Does
- Acts as a **serial bridge**
- Anything typed in Serial Monitor is sent to SIM800L
- SIM800L responses are printed back

### 🧪 How to Use
1. Upload **Code 1**
2. Open Serial Monitor  
   - Baud rate: `9600`
   - Line ending: `Both NL & CR`
3. Type: AT


### ✅ Expected Output
OK

### ⭕ You can also test:
AT+CSQ → Signal strength
AT+CREG? → Network registration
AT+CPIN? → SIM status


---

## 2️⃣ SIM800L SMS Sending Test

### 📄 File Purpose
Used to test:
- SMS text mode
- SMS sending reliability
- GSM network availability

### 🧠 What It Does
- Automatically sends one SMS after upload
- Allows resending SMS by typing `SEND` in Serial Monitor

### 🧪 How to Use
1. Edit phone number in code:
   ```cpp
   const char receiverNumber[] = "+91XXXXXXXXXX";   
2. Upload Code 2
SMS is sent automatically once
3. Open Serial Monitor
4. Type: `SEND`

### ✅ Expected Output

• SMS received on target phone
• Serial Monitor shows: SMS sent successfully.

### 3️⃣ SIM800L Voice Call Test (Mic & Speaker)
**📄 File Purpose**

Used to test:
• Outgoing calls
• Speaker output
• Microphone input
• Audio clarity

**🧠 What It Does**

• Automatically makes a call once after upload
• Allows manual call control using Serial Monitor

### 🧪 How to Use

• Edit phone number in code:
• const char callNumber[] = "+91XXXXXXXXXX";
• Upload Code 3
• SIM800L will call automatically
• Open Serial Monitor and type to dial again: `CALL` 
• To end the call: `HANG`

### ✅ Expected Output

• Phone receives a call
• Two-way audio works through mic & speaker

### ⚠️ Common Issues & Fixes
**❌ Module resets / SMS fails / Call drops**
• Power supply insufficient
• Add large capacitor (≥1000µF)
• Use thick power wires

**❌ No network**
• Check: AT+CREG?
• Result should be:
  +CREG: 0,1

**❌ Garbage characters**
• Baud rate mismatch
• Try 9600 or test via Code 1

### 🧠 Recommended Test Order

1️⃣ Basic AT Test
2️⃣ SMS Test
3️⃣ Call Test

Never skip step 1.

**📚 Part of the Series**

Test the Module
A practical testing series for:

Microcontrollers

Sensors

Communication modules

Embedded hardware

### 🛠️ License

Open-source.
Free to use, modify, and share for learning and development.

Happy building 🚀
Test before you trust.
