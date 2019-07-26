/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 9 May 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook		  : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : Demonstrates how to arrange led's intensity with potensio.
 */

#define led1 3
#define led2 6
#define potensio A0

int analogVoltage = 0;
int analogValue = 0;
int nilaiPWMLed1 = 0;
int nilaiPWMLed2 = 0;

void setup() {
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(potensio, INPUT);
	Serial.begin(9600);
}

void loop() {
	analogValue = analogRead(potensio);
	analogVoltage = map(analogValue, 0, 1023, 0, 5000);
	nilaiPWMLed1 = map(analogValue, 0, 1023, 0, 255);
	nilaiPWMLed2 = map(analogValue, 0, 1023, 255, 0);

	unsigned long count = millis();
	if (((count % 500) >= 0) && ((count % 500) <= 50)) {
		Serial.print("Value : ");
		Serial.println(analogValue);

		Serial.print("Voltage : ");
		Serial.print(analogVoltage / 1000);
		Serial.print(".");
		Serial.println(analogVoltage % 1000);
		Serial.println();
	}

	analogWrite(led1, nilaiPWMLed1);
	analogWrite(led2, nilaiPWMLed2);
}
