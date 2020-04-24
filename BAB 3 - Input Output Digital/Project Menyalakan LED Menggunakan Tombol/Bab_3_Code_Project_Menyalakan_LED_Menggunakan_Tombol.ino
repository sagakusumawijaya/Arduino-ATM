/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : .....
 * Project      : Tutorial Arduino ATM
 * Description  : BAB 3 - Input Output Digital
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya
 * Email        : emtronics.2018@gmail.com
 **/

#define pinLed 6
#define pinTombol 2

bool kondisiTombol = false;
bool kondisiTombolSebelumnya = false;
bool kondisiLed = false;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinTombol, INPUT_PULLUP);  // tombol diset dengan eksternal pull-up resistor
}

void loop() {
  kondisiTombol = digitalRead(pinTombol);
  if (kondisiTombol == false && kondisiTombolSebelumnya != kondisiTombol) {
    if (kondisiLed == false) {
      digitalWrite(pinLed, HIGH);
      kondisiLed = true;
      delay(5);
    } else {
      digitalWrite(pinLed, LOW);
      kondisiLed = false;
      delay(5);
    }
    kondisiTombolSebelumnya = kondisiTombol;
  } else {
    kondisiTombolSebelumnya = kondisiTombol;
  }
}
