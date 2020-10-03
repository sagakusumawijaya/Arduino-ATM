#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL true
#define SDA A4
#define SCL A5

DS3231  rtc(SDA, SCL);

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, Kolom, Baris

Time  t;

const uint16_t INTERVAL = 998;

unsigned long timer = 0;

#if TAMPIL_SERIAL

void tampilSerial() {
  Serial.print("Today is the ");
  Serial.print(t.date, DEC);
  Serial.print(". day of ");
  Serial.print(rtc.getMonthStr());
  Serial.print(" in the year ");
  Serial.print(t.year, DEC);
  Serial.println(".");

  // Send Day-of-Week and time
  Serial.print("It is the ");
  Serial.print(t.dow, DEC);
  Serial.print(". day of the week (counting monday as the 1th), and it has passed ");
  Serial.print(t.hour, DEC);
  Serial.print(" hour(s), ");
  Serial.print(t.min, DEC);
  Serial.print(" minute(s) and ");
  Serial.print(t.sec, DEC);
  Serial.println(" second(s) since midnight.");

  // Send a divider for readability
  Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
}
#endif

void tampilLCD() {
  // =============== WAKTU =============== //
  // tampilkan hh:mm:ss
  // JAM
  if (t.hour < 10) {
    lcd.setCursor(0, 0);  lcd.print('0');
    lcd.setCursor(1, 0);  lcd.print(t.hour);
  }
  else {
    lcd.setCursor(0, 0);  lcd.print(t.hour);
  }

  lcd.setCursor(2, 0);  lcd.print(':');

  // MENIT
  if (t.min < 10) {
    lcd.setCursor(3, 0);  lcd.print('0');
    lcd.setCursor(4, 0);  lcd.print(t.min);
  }
  else {
    lcd.setCursor(3, 0);  lcd.print(t.min);
  }

  lcd.setCursor(5, 0);  lcd.print(':');

  // DETIK
  if (t.sec < 10) {
    lcd.setCursor(6, 0);  lcd.print('0');
    lcd.setCursor(7, 0);  lcd.print(t.sec);
  }
  else {
    lcd.setCursor(6, 0);  lcd.print(t.sec);
  }

  // tampilkan dd:mm:yy
  // TANGGAL
  if (t.date < 10) {
    lcd.setCursor(10, 0); lcd.print('0');
    lcd.setCursor(11, 0); lcd.print(t.date);
  }
  else {
    lcd.setCursor(10, 0); lcd.print(t.date);
  }

  lcd.setCursor(12, 0); lcd.print(':');

  // BULAN
  if (t.mon < 10) {
    lcd.setCursor(13, 0); lcd.print('0');
    lcd.setCursor(14, 0); lcd.print(t.mon);
  }
  else {
    lcd.setCursor(13, 0); lcd.print(t.mon);
  }

  lcd.setCursor(15, 0); lcd.print(':');

  // TAHUN
  lcd.setCursor(16, 0); lcd.print(t.year);

  // ===================================== //
}

void setupLCD() {

}

void setup() {
#if TAMPIL_SERIAL
  Serial.begin(9600);
#endif

  lcd.init();
  lcd.backlight();
  setupLCD();

  rtc.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(1, 49, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(4, 10, 2020);   // Set the date to January 1st, 2014

  timer = millis();
}


void loop() {
  t = rtc.getTime();  // Get data from the DS3231

  if (millis() - timer > INTERVAL) {
    tampilLCD();

#if TAMPIL_SERIAL
    tampilSerial();
#endif

    timer = millis();
  }
}
