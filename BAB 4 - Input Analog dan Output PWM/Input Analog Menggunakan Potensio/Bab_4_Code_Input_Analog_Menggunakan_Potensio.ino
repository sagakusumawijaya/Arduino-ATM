/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 9 May 2019
 * Project      : Tutorial Arduino ATM
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya
 * Email        : emtronics.2018@gmail.com
 **/

#define potensio A0

int analogVoltage = 0;
int analogValue = 0;

void setup() {
	pinMode(potensio, INPUT);
	Serial.begin(9600);
}

void loop() {
	analogValue = analogRead(potensio);
	analogVoltage = map(analogValue, 0, 1023, 0, 5000);

	Serial.print("Value : ");
	Serial.println(analogValue);

	Serial.print("Voltage : ");
	Serial.print(analogVoltage / 1000);
	Serial.print(".");
	Serial.println(analogVoltage % 1000);
	Serial.println();
	delay(500);
}
