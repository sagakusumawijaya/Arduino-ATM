#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN A0
#define TAMPIL_SERIAL true

LiquidCrystal_I2C lcd(0x27, 20, 4);

int nilaiAnalog = 0;
float voltage = 0;
unsigned long waktuSekarang = 0;
unsigned long waktuSekarangLCD = 0;

const unsigned long INTERVAL_TAMPIL_SERIAL = 1000;  // dalam mili detik
const unsigned long INTERVAL_TAMPIL_LCD = 500;  // dalam mili detik
const uint8_t JUMLAH_PEMBACAAN = 10;

void setup() {
#if TAMPIL_SERIAL
  Serial.begin(9600);
#endif

  lcd.init();
  lcd.backlight();
  lcd.clear();

#if TAMPIL_SERIAL
  Serial.println("STARTED");
#endif

  lcd.setCursor(6, 0);
  lcd.print("STARTED");
  lcd.setCursor(0, 1);
  lcd.print("NILAI ANALOG :");
  lcd.setCursor(0, 2);
  lcd.print("VOLTAGE :");
  waktuSekarang = waktuSekarangLCD = millis();
}

void loop() {
  nilaiAnalog = 0;
  for (uint8_t i = 0; i < JUMLAH_PEMBACAAN; i++) {
    nilaiAnalog += analogRead(PIN);
    delay(10);
  }
  nilaiAnalog /= JUMLAH_PEMBACAAN;
  tampilLCD(nilaiAnalog);
}

void tampilLCD(int nilai) {
  if (millis() - waktuSekarangLCD > INTERVAL_TAMPIL_LCD) {
    // NILAI ANALOG
    lcd.setCursor(15, 1);
    lcd.print(nilai);

    // VOLTAGE
    voltage = nilai * 5 / 1024.0; // Kalkulasi nilai voltage
    lcd.setCursor(10, 2);
    lcd.print(voltage);
    lcd.setCursor(14, 2);
    lcd.print("V");
    waktuSekarangLCD = millis();
  }

#if TAMPIL_SERIAL
  if (millis() - waktuSekarang > INTERVAL_TAMPIL_SERIAL) {
    Serial.print("NILAI ANALOG : ");  Serial.println(nilai);
    Serial.print("VOLTAGE : "); Serial.print(voltage);  Serial.println(" V");
    Serial.println();
    waktuSekarang = millis();
  }
#endif
}
