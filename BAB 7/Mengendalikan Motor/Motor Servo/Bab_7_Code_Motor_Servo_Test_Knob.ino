/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 20 July 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook		    : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : This is an example .ino file of Servo.h librarie
 */

 /*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
 */

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
	myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
	val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
	val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
	myservo.write(val);                  // sets the servo position according to the scaled value
	delay(15);                           // waits for the servo to get there
}
