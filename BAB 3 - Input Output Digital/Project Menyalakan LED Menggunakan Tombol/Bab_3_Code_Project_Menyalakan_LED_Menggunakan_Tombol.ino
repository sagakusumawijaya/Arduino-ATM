/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 9 May 2019
 * Project      : Tutorial Arduino ATM
 * Description  : BAB 3 - Project Menyalakan LED Menggunakan Tombol
 * Dedicated to : emtronics
 * Youtube      : emtronics.official
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya/Arduino-ATM
 * Email        : emtronics.2018@gmail.com
 **/

#define led 6
#define tombol 2

bool kondisiTombol = false;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(tombol, INPUT_PULLUP);
}

void loop() {
  kondisiTombol = !digitalRead(tombol);
  digitalWrite(led, kondisiTombol);
}
