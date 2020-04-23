/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 10 May 2019
 * Project      : Tutorial Arduino ATM
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya
 * Email        : emtronics.2018@gmail.com
 **/

#define buzzer 9

void setup() {
	pinMode(buzzer, OUTPUT);
}

void loop() {
	tone(buzzer, 500);
	delay(1000);
	noTone(buzzer);
	delay(500);
}
