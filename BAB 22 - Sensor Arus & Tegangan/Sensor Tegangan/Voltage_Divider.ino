#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL false
#define TAMPIL_LCD  true
#define PIN_ANALOG  A0

#if TAMPIL_LCD ////////
LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, Kolom, Baris
#endif  ///////////////
float vIn = 0.0;
float v2 = 0.0;

/* UNTUK MODUL VOLTAGE SENSOR,  
 *  COMMENT BARIS 18 DAN 19,
 *  UNCOMMENT BARIS 20 DAN 21
 */
const float R1 = 9100.0; // ohm
const float R2 = 5000.0; // ohm
//const float R1 = 30000.0; // ohm
//const float R2 = 7500.0; // ohm
uint16_t analogValue = 0;
const uint8_t SAMPLE = 10;

void setup() {
#if TAMPIL_SERIAL //////
  Serial.begin(9600);
#endif  ///////////////

#if TAMPIL_LCD ////////
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("VOLTAGE DIVIDER");
  lcd.setCursor(0, 1);
  lcd.print("VOLT :");
#endif  ///////////////
}

void loop() {
  vIn = 0;
  for (uint8_t i = 0; i < SAMPLE; i++) {
    analogValue = analogRead(PIN_ANALOG);
    v2 = (analogValue * 5.0) / 1024.0;
    vIn += ((R1 + R2) / R2) * v2;
  }
  vIn /= SAMPLE;
#if TAMPIL_SERIAL //////
  Serial.print("TEGANGAN TERBACA : ");
  Serial.print(vIn);
  Serial.println(" volt");
#endif  ///////////////

#if TAMPIL_LCD ////////
  lcd.setCursor(7, 1);
  lcd.print("             ");
  lcd.setCursor(7, 1);
  lcd.print(vIn);
#endif  ///////////////

  delay(500);
}
