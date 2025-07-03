# SMART AIR - Indoor Air Quality Monitoring System 🌱

**SMART AIR** is an IoT-based real-time indoor air quality monitoring system built using **ESP32**, **DHT11** (Temperature & Humidity), **MQ135** (Air Quality sensor), and an **OLED display**. The project also integrates with the **Blynk IoT platform** to allow remote monitoring of environmental data on a mobile device.

---

## 🚀 Features

- 📊 Real-time monitoring of:
  - **Air Quality Index (AQI)**
  - **Temperature**
  - **Humidity**
  - **AQI Category (Good, Moderate, Poor, etc.)**
- 📱 Live data displayed on:
  - **OLED screen on the device**
  - **Blynk IoT mobile dashboard**
- 🔗 Wi-Fi enabled using **ESP32**
- 🌐 Remote access to data from anywhere via Blynk app

---

## 🛠 Hardware Used

| Component | Details |
|-----------|---------|
| **ESP32** | Main microcontroller with Wi-Fi |
| **DHT11** | Temperature & Humidity sensor |
| **MQ135** | Air Quality sensor |
| **SSD1306 OLED** | 128x64 display |
| **LED** *(optional)* | Visual air quality indicator |

---

## 📲 Blynk IoT Integration

1. **Platform:** [Blynk IoT](https://blynk.cloud)
2. Create a **Template** and note down:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_TEMPLATE_NAME`
   - `BLYNK_AUTH_TOKEN`
3. Add widgets for:
   - **AQI** (V0)
   - **Temperature** (V1)
   - **Humidity** (V2)
   - **AQI Category** (V3)

---

## 🔧 How It Works

1. **Sensors** collect environmental data.
2. **ESP32** reads the sensor values and calculates AQI.
3. Data is shown locally on the **OLED screen** and sent to the **Blynk IoT dashboard** via Wi-Fi.
4. Users can monitor the room conditions in real-time using the **Blynk mobile app**.

---

## 📌 Future Enhancements

- 💨 **Smart Air Purifier System**: Add fan control based on AQI levels.
- ☁️ **Data Logging to Cloud**: Store historical environmental data.
- 🖥️ **Web Dashboard**: Access data via desktop browsers.

---

## 📷 Screenshots

#### **BlynkIoT web dashboard preview**: https://drive.google.com/file/d/1MVgZZL5Iw0zh-LKsikmQAHMPViJ_GD7_/view?usp=sharing
#### **Project Starting Window**: https://drive.google.com/file/d/1MUbsbcyA1h2feIOtM783kbrk_5oaiDjG/view?usp=sharing
#### **Project Working Preview**: https://drive.google.com/file/d/1M_3U7pZ8uDO2F8KU9MwZcXpOBIW87lV4/view?usp=drive_link

---

## 👨‍💻 Developed By

#### **Name**: Harsh Vardhan Saini
#### **Email**: hvardhnaharsh07@gmail.com 
#### **GitHub**: https://github.com/Cat-sauce
---

