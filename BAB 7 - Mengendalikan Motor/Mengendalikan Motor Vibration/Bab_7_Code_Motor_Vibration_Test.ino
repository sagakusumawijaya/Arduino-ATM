/**
 * Author       : Saga Kusuma Wijaya
 * Date Created : 20 July 2019
 * Project      : Tutorial Arduino ATM
 * Dedicated to : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya
 * Email        : emtronics.2018@gmail.com
 **/

const int motorPin = 2;

void setup(){
	pinMode(motorPin, OUTPUT);	// set motorPin as output
}

void loop(){
	digitalWrite(motorPin, HIGH);	// set motorPin HIGH
	delay(1000);
	digitalWrite(motorPin, LOW);	// set motorPin LOW
	delay(500);
}
