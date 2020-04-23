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

#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
	Serial.begin(115200);
}

void loop() {
	// start working...
	Serial.println("=================================");
	Serial.println("Sample DHT11...");

	// read without samples.
	byte temperature = 0;
	byte humidity = 0;
	int err = SimpleDHTErrSuccess;
	if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
		Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
		return;
	}

	Serial.print("Sample OK: ");
	Serial.print((int)temperature); Serial.print(" *C, ");
	Serial.print((int)humidity); Serial.println(" H");

	// DHT11 sampling rate is 1HZ.
	delay(1500);
}
