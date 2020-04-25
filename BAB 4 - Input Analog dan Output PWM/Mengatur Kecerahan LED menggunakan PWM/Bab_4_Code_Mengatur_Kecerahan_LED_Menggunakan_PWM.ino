/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 9 May 2019
 * Project      : Tutorial Arduino ATM
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya/Arduino-ATM
 * Email        : emtronics.2018@gmail.com
 **/

#define pwmLED 6

void setup() {
	pinMode(pwmLED, OUTPUT);
}

void loop() {
	// for-loop digunakan untuk meningkatkan kecerahan led
	for (int i = 0; i <= 255; i += 5) {
		analogWrite(pwmLED, i);
		delay(50);
	}
	delay(1000);  // tunggu 1 detik ketika led berada di titik paling terang

	// for-loop digunakan untuk menurunkan kecerahan led
	for (int i = 255; i >= 0; i -= 5) {
		analogWrite(pwmLED, i);
		delay(50);
	}
	delay(1000);  // tunggu 1 detik ketika led berada di titik paling redup (led padam(
}
