#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Konfigurasi
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Konfigurasi PIN
const int redLed = 19;    // GPIO pin for red LED
const int yellowLed = 18; // GPIO pin for yellow LED
const int greenLed = 5;   // GPIO pin for green LED
const int buzzer = 17;    // GPIO pin for buzzer

void setup() {
  // Initialize serial monitor
  Serial.begin(115200);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Pastikan alamat sesuai hasil I2C Scanner
    Serial.println("OLED initialization failed!");
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Initialize pins
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Initial OLED display
  displayMessage("Jalan Lancar", "Ready...");
}

void loop() {
  // Lampu merah
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(buzzer, HIGH); // Buzzer on
  displayMessage("STOP!", "Lampu Merah");
  delay(5000);
  digitalWrite(buzzer, LOW); // Buzzer off

  // Lampu kuning
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);
  displayMessage("Siap-siap", "Lampu Kuning");
  delay(2000);

  // Lampu hijau
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  displayMessage("GO!", "Lampu Hijau");
  delay(5000);
}

// Function to display message on OLED
void displayMessage(String status, String detail) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Info Lalin:");
  display.setCursor(0, 20);
  display.println(status);
  display.setCursor(0, 40);
  display.println(detail);
  display.display();
}
