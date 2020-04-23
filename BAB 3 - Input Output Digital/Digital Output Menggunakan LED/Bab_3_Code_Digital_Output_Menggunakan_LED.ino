/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 8 May 2019
 * Project      : Tutorial Arduino ATM
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/2020/04/21/output-digital-menggunakan-led/
 * Github       : https://github.com/sagakusumawijaya
 * Email        : emtronics.2018@gmail.com
 **/

#define pinLED 5

void setup() {
	pinMode(pinLED, OUTPUT);
}

void loop() {
	digitalWrite(pinLED, HIGH);
	delay(250);
	digitalWrite(pinLED, LOW);
	delay(250);
}
