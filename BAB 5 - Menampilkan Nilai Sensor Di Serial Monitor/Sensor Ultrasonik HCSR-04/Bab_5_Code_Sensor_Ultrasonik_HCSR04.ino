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
 * Description    : Displaying HCSR04 value in Serial Monitor.
 */

#define triggerPin	11	// pin trigger sensor ultrasonik
#define echoPin		  12  // pin echo sensor ultrasonik

long durasi = 0;
long inci = 0;
long cm = 0;

void setup() {
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	durasi = pulseIn(echoPin, HIGH);
	inci = durasi / 74 / 2;
	cm = durasi / 29 / 2;

	Serial.print("Objek terdeteksi :\t");
	Serial.print(inci); Serial.print(" inch\t");
	Serial.print(cm); Serial.println(" cm");
	Serial.println();
	delay(1000);
}
