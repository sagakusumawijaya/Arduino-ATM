/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 8 May 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook	      : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : Demonstrates how to use LED as output digital with Arduino.
 */

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
