#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL true
#define PIN_SENSOR A0

LiquidCrystal_I2C lcd(0x27, 20, 4);

int sensorValue = 0;
float tdsValue = 0;
float voltage = 0;

void setup() {
#if TAMPIL_SERIAL
  Serial.begin(9600);
#endif
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  lcd.clear();
  sensorValue = analogRead(PIN_SENSOR);
  voltage = sensorValue * 5 / 1024.0; // Mengkonversi nilai analog ke voltage
  
  // Mengkonversi nilai voltage ke nilai TDS
  tdsValue = (133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage) * 0.5; 

#if TAMPIL_SERIAL
  Serial.print("TDS Value = ");
  Serial.print(tdsValue);
  Serial.println(" ppm");
#endif
  
  lcd.setCursor(0, 0);
  lcd.print("TDS VAL =");
  lcd.setCursor(10, 0);
  lcd.print(tdsValue);

  if (tdsValue < 10) {
    lcd.setCursor(15, 0);
  }
  else if (tdsValue >= 10 && tdsValue < 100) {
    lcd.setCursor(16, 0);
  }
  else {
    lcd.setCursor(17, 0);
  }
  lcd.print("PPM");

  delay(1000);
}
