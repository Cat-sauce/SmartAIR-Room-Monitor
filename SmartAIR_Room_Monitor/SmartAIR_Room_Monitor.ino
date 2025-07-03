#define BLYNK_TEMPLATE_ID ""          
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


char ssid[] = "";
char pass[] = "";

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Sensor setup
#define DHTPIN 25
#define DHTTYPE DHT11
#define AQI_PIN 34
DHT dht(DHTPIN, DHTTYPE);

// LED pin for air filter simulation
//#define LED_PIN 27

// Scrolling text position
int scrollX = SCREEN_WIDTH;

// Get AQI category
String getAQICategory(int aqi) {
  if (aqi <= 50) return "Good";
  else if (aqi <= 100) return "Satisfactory";
  else if (aqi <= 200) return "Moderate";
  else if (aqi <= 300) return "Poor";
  else if (aqi <= 400) return "Very Poor";
  else return "Severe";
}

void setup() {
  Serial.begin(115200);
  //WiFi.mode(WIFI_OFF);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  //btStop();

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  // Welcome screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25, 24);
  display.println("Welcome to");
  display.setCursor(30, 35);
  display.println("SmartAIR");
  display.display();
  delay(4000);
}

void loop() {
  Blynk.run();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rawAQI = analogRead(AQI_PIN);
  int aqi = map(rawAQI, 0, 4095, 0, 500);
  aqi = constrain(aqi, 0, 500);
  String category = getAQICategory(aqi);

  //if (isnan(temperature) || isnan(humidity)) {
    //Serial.println("DHT11 failed!");
    //delay(2000);
    //return;
  //}

  int brightness = map(aqi, 0, 500, 0, 255);
  brightness = constrain(brightness, 0, 255);
  analogWrite(LED_PIN, brightness);

  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print(" C, Humidity: "); Serial.print(humidity);
  Serial.print(" %, AQI: "); Serial.print(aqi);
  Serial.print(" -> "); Serial.println(category);

  Blynk.virtualWrite(V0, aqi);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, category);


  display.clearDisplay();

  // Scroll "SmartAIR" text at the top
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(scrollX, 0);
  display.print("SmartAIR");
  scrollX -= 2;
  if (scrollX < -60) scrollX = SCREEN_WIDTH;

  // AQI & Category
  display.setCursor(0, 16);
  display.print("AQI: ");
  display.println(aqi);

  display.setCursor(0, 26);
  display.println(category);

  // Temperature
  display.setCursor(0, 38);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  // Humidity
  display.setCursor(0, 50);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.display();
  delay(500);

}