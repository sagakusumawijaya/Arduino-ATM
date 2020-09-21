#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, kolom, baris

#define KALIBRASI_PH false
#define NILAI_PH_KALIBRASI  4.01
#define SAMPLING_KALIBRASI  200

#define SensorPin A0
#define Offset    38.75929108
#define k         -16.88990526
#define LED       13
#define samplingInterval  20
#define printInterval     800
#define ArrayLenth        40    // times of collection
#define TAMPIL_SERIAL     true  // tampilkan hasil di serial monitor

int pHArray[ArrayLenth];   // Menyimpan nilai rata2 hasil pembacaan sensor
int pHArrayIndex = 0;

void setup(void) {
  pinMode(LED, OUTPUT);
#if TAMPIL_SERIAL
  Serial.begin(9600);
  Serial.println("STARTED");
#endif

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage= ");
  lcd.setCursor(0, 1);
  lcd.print("ph Val = ");
}

void loop(void) {
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static double pHValue, voltage;

#if KALIBRASI_PH  // MODE KALIBRASI
  double voltKalibrasi = 0;
  uint16_t samplingKalibrasi = SAMPLING_KALIBRASI;
#if TAMPIL_SERIAL
  Serial.print("KALIBRASI PH : ");
  Serial.println(NILAI_PH_KALIBRASI);
#endif
  lcd.setCursor(0, 0);
  lcd.print("KALIBRASI PH: ");
  lcd.setCursor(16, 0);
  lcd.print(NILAI_PH_KALIBRASI);
  for (uint16_t i = 0; i < samplingKalibrasi; i++) {
    voltage = analogRead(SensorPin) * 5.0 / 1024;
    voltKalibrasi += voltage;
    delay(samplingInterval);
#if TAMPIL_SERIAL
    Serial.print('.');
#endif
  }
#if TAMPIL_SERIAL
  Serial.println();
#endif
  voltKalibrasi /= samplingKalibrasi;
  delay(2000);
#if TAMPIL_SERIAL
  Serial.print("NILAI PH : ");
  Serial.print(NILAI_PH_KALIBRASI);
  Serial.print("\t\tVOLTAGE : ");
  Serial.println(voltKalibrasi, 4);
#endif
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nilai PH : ");
  lcd.setCursor(11, 0);
  lcd.print(NILAI_PH_KALIBRASI);
  lcd.setCursor(0, 1);
  lcd.print("Voltage : ");
  lcd.setCursor(10, 1);
  lcd.print(voltKalibrasi, 4);
  while (1) {};
#else // MODE EKSEKUSI
  if (millis() - samplingTime > samplingInterval) {
    pHArray[pHArrayIndex++] = analogRead(SensorPin);
    if (pHArrayIndex == ArrayLenth) pHArrayIndex = 0;

    voltage = avergearray(pHArray, ArrayLenth) * 5.0 / 1024;
    pHValue = k * voltage + Offset;
    samplingTime = millis();
  }

  // Setiap 800 mili detik, print a hasil pembacaan, ubah nyala kondisi LED
  if (millis() - printTime > printInterval) {
#if TAMPIL_SERIAL
    Serial.print("Voltage:");
    Serial.print(voltage, 4);
    Serial.print("    pH value: ");
    Serial.println(pHValue, 2);
#endif
    lcd.setCursor(9, 0);
    lcd.print("        ");
    lcd.setCursor(9, 1);
    lcd.print("        ");
    lcd.setCursor(9, 0);
    lcd.print(voltage, 4);
    lcd.setCursor(9, 1);
    lcd.print(pHValue);
    digitalWrite(LED, digitalRead(LED) ^ 1);
    printTime = millis();
  }
#endif
}

double avergearray(int* arr, int number) {
  int i;
  int max, min;
  double avg;
  long amount = 0;
  if (number <= 0) {
#if TAMPIL_SERIAL
    Serial.println("Error number for the array to avraging!/n");
#endif
    return 0;
  }

  if (number < 5) { //less than 5, calculated directly statistics
    for (i = 0; i < number; i++) {
      amount += arr[i];
    }
    avg = amount / number;
    return avg;
  } else {
    if (arr[0] < arr[1]) {
      min = arr[0]; max = arr[1];
    }
    else {
      min = arr[1]; max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount += min;      //arr<min
        min = arr[i];
      } else {
        if (arr[i] > max) {
          amount += max;  //arr>max
          max = arr[i];
        } else {
          amount += arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount / (number - 2);
  }//if
  return avg;
}
