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

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
	myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
	  // in steps of 1 degree
		myservo.write(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
}
