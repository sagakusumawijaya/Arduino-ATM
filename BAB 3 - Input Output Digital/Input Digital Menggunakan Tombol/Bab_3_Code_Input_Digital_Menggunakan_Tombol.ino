/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 8 May 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook	  : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : Demonstration how to use pushbutton with Arduino.
 */

#define tombol1 4
#define tombol2 6
#define tombol3 8

bool t1 = false;
bool t2 = false;
bool t3 = false;

void setup() {
	pinMode(tombol1, INPUT);        // eksternal pull-up resistor
	pinMode(tombol2, INPUT_PULLUP); // internal pull-up resistor
	pinMode(tombol3, INPUT);        // eksternal pull-down resistor
	Serial.begin(9600);
}

void loop() {
	t1 = !digitalRead(tombol1);
	t2 = !digitalRead(tombol2);
	t3 = digitalRead(tombol3);

	if (t1 || t2 || t3) {
		Serial.print("Tombol 1 : ");
		t1 ? Serial.println("Aktif") : Serial.println("Tidak Aktif");
		Serial.print("Tombol 2 : ");
		t2 ? Serial.println("Aktif") : Serial.println("Tidak Aktif");
		Serial.print("Tombol 3 : ");
		t3 ? Serial.println("Aktif") : Serial.println("Tidak Aktif");
		delay(1500);
	}
}
