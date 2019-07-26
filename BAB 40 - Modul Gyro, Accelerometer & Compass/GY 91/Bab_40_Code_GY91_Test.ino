/*
 * Author         : Saga Kusuma Wijaya
 * Date Created   : 20 July 2019
 * Project        : Tutorial Arduino ATM
 * Dedicated to   : emtronics
 * Youtube        : https://www.youtube.com/channel/UCW4GRacd319Ml2cv-B9-uxg
 * Instagram      : https://www.instagram.com/emtronics.official/
 * Website        : https://emtronicsofficial.com
 * Facebook		  : https://www.facebook.com/emtronics.official/
 * Email          : contact@emtronicsofficial.com
 *
 * Description    : This code is edited example from "MPU9250.h" library.
 */

#include "MPU9250.h"

MPU9250 mpu = MPU9250();

int gyro_X, gyro_Y, gyro_Z;

void setup(void) {
	Serial.begin(9600);
	uint8_t temp = mpu.begin();
}

void loop() {
	//Accel
	mpu.set_accel_range(RANGE_4G);
	mpu.get_accel();
	Serial.println(F("ACCELEROMETER"));
	Serial.print("X: ");  Serial.print(mpu.x);
	Serial.print("\tY: "); Serial.print(mpu.y);
	Serial.print("\t\tZ: "); Serial.print(mpu.z);


	mpu.get_accel_g();
	Serial.print("\t\tX_g: "); Serial.print(mpu.x_g, 2);
	Serial.print("\tY_g: "); Serial.print(mpu.y_g, 2);
	Serial.print("\tZ_g: "); Serial.print(mpu.z_g, 2);  Serial.println(" G");
	Serial.println('\n');

	//Gyro
	mpu.set_gyro_range(RANGE_GYRO_250);
	mpu.get_gyro();
	gyro_X = mpu.gx;
	gyro_Y = mpu.gy;
	gyro_Z = mpu.gz;
	Serial.println(F("GYROSCOPE"));
	Serial.print("GX: ");  Serial.print(gyro_X);
	Serial.print("\t\tGY: "); Serial.print(gyro_Y);
	Serial.print("\t\tGZ: "); Serial.print(gyro_Z);

	mpu.get_gyro_d();
	Serial.print("\t\tGX_g: "); Serial.print(mpu.gx_d, 2);
	Serial.print("\tGY_g: "); Serial.print(mpu.gy_d, 2);
	Serial.print("\tGZ_g: "); Serial.print(mpu.gz_d, 2); Serial.println(" º/s");
	Serial.println('\n');

	//Mag
	mpu.set_mag_scale(SCALE_14_BITS);
	mpu.set_mag_speed(MAG_8_Hz);
	if (!mpu.get_mag()) {
		Serial.println(F("MAGNETOMETER"));
		Serial.print("MX: ");  Serial.print(mpu.mx);
		Serial.print("\t\tMY: "); Serial.print(mpu.my);
		Serial.print("\t\tMZ: "); Serial.print(mpu.mz);

		mpu.get_mag_t();
		Serial.print("\tMX_t: "); Serial.print(mpu.mx_t, 2);
		Serial.print("\tMY_t: "); Serial.print(mpu.my_t, 2);
		Serial.print("\tMZ_t: "); Serial.print(mpu.mz_t, 2); Serial.println(" uT");
		Serial.println('\n');
	}
	else {
		// |X|+|Y|+|Z| must be < 4912μT to sensor measure correctly 
		Serial.println("Overflow no magnetometro.");
	}

	// Temp     
	Serial.print("Temperature is ");  Serial.print((((float)mpu.get_temp()) / 333.87 + 21.0), 1);  Serial.println(" degrees C");
	Serial.println();
	delay(500);
	Serial.println('\n');
	Serial.println('\n');
}
