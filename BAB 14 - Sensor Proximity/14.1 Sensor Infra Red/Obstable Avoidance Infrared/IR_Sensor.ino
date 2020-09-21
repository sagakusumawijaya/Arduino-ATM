#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL true
#define PIN_SENSOR 2

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, Kolom, Baris

bool condition = false;

void setup() {
  pinMode(PIN_SENSOR, INPUT_PULLUP);
#if TAMPIL_SERIAL //////
  Serial.begin(9600);
  Serial.println("STARTED");
#endif  ///////////////

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("SENSOR INFRA-RED");
  lcd.setCursor(0, 1);
  lcd.print("OBJEK : ");
}

void loop() {
  condition = digitalRead(PIN_SENSOR);

  if (!condition) { // JIKA ADA OBJEK TERDETEKSI
#if TAMPIL_SERIAL //////
    Serial.print("OBJEK : ");
    Serial.println("ADA");
#endif  ///////////////
    lcd.setCursor(8, 1);
    lcd.print("          ");
    lcd.setCursor(8, 1);
    lcd.print("ADA");
  } else {  // JIKA TIDAK ADA OBJEK TERDETEKSI
#if TAMPIL_SERIAL //////
    Serial.print("OBJEK : ");
    Serial.println("TIDAK ADA");
#endif  ///////////////
    lcd.setCursor(8, 1);
    lcd.print("          ");
    lcd.setCursor(8, 1);
    lcd.print("TIDAK ADA");
  }
  delay(250);
}
