#include <SimpleDHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TAMPIL_SERIAL true
#define PIN_DHT_11  2

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, Kolom, Baris
const byte KARAKTER_DERAJAT = 0;
byte derajat[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

SimpleDHT11 dht11(PIN_DHT_11);
byte temperature = 0, humidity = 0;
int err = SimpleDHTErrSuccess;

void setup() {
#if TAMPIL_SERIAL //////
  Serial.begin(9600);
#endif  ///////////////

  lcd.init();
  lcd.createChar(KARAKTER_DERAJAT, derajat);
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("SENSOR DHT11");
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.setCursor(0, 2);
  lcd.print("Humid: ");
}

void loop() {
#if TAMPIL_SERIAL //////////////////////////////////
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
#endif  ///////////////////////////////////////////
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
#if TAMPIL_SERIAL //////////////////////////
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err); 
#endif  ////////////////////////////////////

    lcd.setCursor(1, 3);
    lcd.print("Read DHT11 failed");
    
    delay(2000);
    lcd.setCursor(1, 3);
    lcd.print("                  ");
    return;
  }
  
#if TAMPIL_SERIAL ///////////////////////////////////////
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" H");
#endif  /////////////////////////////////////////////////

  lcd.setCursor(7, 1);
  lcd.print("          ");
  lcd.setCursor(7, 1);
  lcd.print((int)temperature);
  if((int)temperature < 10){
    lcd.setCursor(8, 1);
    lcd.write(KARAKTER_DERAJAT);
    lcd.setCursor(9, 1);
  }else{
    lcd.setCursor(9, 1);
    lcd.write(KARAKTER_DERAJAT);
    lcd.setCursor(10, 1);
  }
  lcd.print('C');

  lcd.setCursor(7, 2);
  lcd.print("          ");
  lcd.setCursor(7, 2);
  lcd.print((int)humidity);
  (int)temperature < 10 ? lcd.setCursor(8, 2) : lcd.setCursor(9, 2);
  lcd.print(" H");
  
  delay(2100);
}
