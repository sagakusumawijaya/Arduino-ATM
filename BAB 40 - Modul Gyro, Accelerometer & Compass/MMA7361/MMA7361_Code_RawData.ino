/**
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 16 July 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube      : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram    : https://www.instagram.com/emtronics.official/
 * Facebook     : https://web.facebook.com/emtronics.official/
 * Website      : https://sagakusumawijaya94.wordpress.com/tutorials/arduino-tutorial/
 * Github       : https://github.com/sagakusumawijaya/Arduino-ATM
 * Email        : emtronics.2018@gmail.com
 **/

#include <AcceleroMMA7361.h>

// Define your pin connection here
#define sleepPin    5
#define selfTestPin 2
#define zeroGPin    4
#define gSelectPin  3
#define xPin        A2
#define yPin        A1
#define zPin        A0

AcceleroMMA7361 accelero;
int xA;
int yA;
int zA;
int x;
int y;
int z;
int xV;
int yV;
int zV;

void setup(){
  Serial.begin(9600);
  accelero.begin(sleepPin, selfTestPin, zeroGPin, gSelectPin, xPin, yPin, zPin);
  accelero.setARefVoltage(5);    //sets the AREF voltage to 3.3V or 5V
  accelero.setSensitivity(LOW);  
  accelero.calibrate();
}

void loop(){
  xA = accelero.getXAccel();
  yA = accelero.getYAccel();
  zA = accelero.getZAccel();
  Serial.print("\nx: ");
  Serial.print(xA);
  Serial.print(" \ty: ");
  Serial.print(yA);
  Serial.print(" \tz: ");
  Serial.print(zA);
  Serial.print("\tG*10^-2");

  x = accelero.getXRaw();
  y = accelero.getYRaw();
  z = accelero.getZRaw();
  Serial.print("\nx: ");
  Serial.print(x);
  Serial.print("\ty: ");
  Serial.print(y);
  Serial.print("\tz: ");
  Serial.print(z);

  xV = accelero.getXVolt();
  yV = accelero.getYVolt();
  zV = accelero.getZVolt();
  Serial.print("\nx: ");
  Serial.print(xV);
  Serial.print("mV\ty: ");
  Serial.print(yV);
  Serial.print("mV\tz: ");
  Serial.print(zV);
  Serial.println("mV");
  delay(500);
}
