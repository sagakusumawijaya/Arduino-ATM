/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 9 May 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook		    : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : Demonstrates how to use pushbutton to activate LED with Arduino
 */

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
