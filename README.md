# RemoteControlApp
A documentation on setting up cell phone app to remotely control Arduino chips. Mainly using RemoteXY. 

# 📘 RemoteXY: Getting Started Guide

## 📌 What is RemoteXY?

**RemoteXY** is a platform that allows you to create graphical user interfaces (GUIs) for mobile devices and connect them to microcontrollers such as **Arduino**, **ESP8266**, or **ESP32**. You can control LEDs, motors, sensors, and more—without writing any mobile app code.

You create the interface visually online, then copy the auto-generated code into your microcontroller project. It supports **Bluetooth**, **Wi-Fi**, **Ethernet**, and **USB** connections.

---

## 🧰 What You Need

- A **microcontroller** (e.g., Arduino UNO, ESP32, etc.)
- An optional **Bluetooth**, **Wi-Fi**, or **USB** module
- The **RemoteXY app** installed on your smartphone (Android/iOS)
- An internet connection for designing the UI
- **Arduino IDE** or compatible environment

---

## 🚀 Step-by-Step Setup

### 1. Go to RemoteXY Designer
- Visit: [https://remotexy.com/editor/](https://remotexy.com/editor/)
- Drag and drop buttons, sliders, text fields, etc., to build your custom GUI.

### 2. Select Connection Type
- At the top, click **"Connection"** and choose your method:
  - **Bluetooth (HC-05, HC-06)**
  - **Wi-Fi (ESP8266, ESP32)**
  - **USB**
  - **Ethernet**

### 3. Generate the Code
- Once your UI is ready, click **"Generate Source Code"**
- Choose your board and environment (e.g., Arduino + ESP32)
- The site generates code with everything wired up to your UI elements

### 4. Copy Code to Arduino IDE
- Paste the code into a new sketch in the Arduino IDE
- Make sure you install the **RemoteXY library**:
  - In Arduino IDE, go to **Sketch > Include Library > Manage Libraries**
  - Search for **RemoteXY** and install it

### 5. Upload to Your Microcontroller
- Plug in your board via USB
- Select the correct board and port under **Tools**
- Click **Upload**

### 6. Open the RemoteXY App
- Download **RemoteXY** from the App Store or Google Play
- Choose the connection type (Bluetooth, Wi-Fi, etc.)
- Scan or enter the device info
- Connect, and your custom GUI should appear!

---

## 🛠️ Example: Control an LED Over Wi-Fi (ESP32)

### UI:
One **toggle switch** to turn an LED on/off.

### Code Snippet:

```cpp
#define REMOTEXY_MODE__ESP32CORE_WIFI
#include <WiFi.h>
#include <RemoteXY.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";

RemoteXY_CONF = { ... }; // auto-generated config
unsigned char RemoteXY_CONF[] = { ... }; // from the RemoteXY site

RemoteXY_INFO = { ... }; // auto-generated info

#define LED_PIN 2

void setup() {
  RemoteXY_Init();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  RemoteXY_Handler();
  digitalWrite(LED_PIN, RemoteXY.switch_1);
}
