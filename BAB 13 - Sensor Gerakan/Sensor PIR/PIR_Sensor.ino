#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL true
#define TAMPIL_LCD    true

#define PIR_SENSOR  2
#define PIN_LED     13

#if TAMPIL_SERIAL
const uint32_t INTERVAL_SERIAL  = 1000; // mili detik
uint32_t millisNow = 0;
#endif

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, Kolom, Baris

bool nilaiSensor = false;

void setup() {
  pinMode(PIR_SENSOR, INPUT);
  pinMode(PIN_LED, OUTPUT);

#if TAMPIL_SERIAL
  Serial.begin(9600);
  Serial.println("STARTED");
  millisNow = millis();
#endif
#if TAMPIL_LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("SENSOR PIR");
#endif
}

void loop() {
  nilaiSensor = digitalRead(PIR_SENSOR);
  digitalWrite(PIN_LED, nilaiSensor);
  if (nilaiSensor) {  // nilaiSensor is HIGH
#if TAMPIL_SERIAL
    if(millis() - millisNow > INTERVAL_SERIAL){
      Serial.println("OOOOO");
      millisNow = millis();
    }
#endif
#if TAMPIL_LCD
    lcd.setCursor(7, 1);
    lcd.print("OOOOO");
#endif
  } else {
#if TAMPIL_SERIAL
    if(millis() - millisNow > INTERVAL_SERIAL){
      Serial.println("XXXXX");
      millisNow = millis();
    }
#endif
#if TAMPIL_LCD
    lcd.setCursor(7, 1);
    lcd.print("XXXXX");
#endif
  }
}
