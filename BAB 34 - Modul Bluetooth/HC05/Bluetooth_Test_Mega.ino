#define BT_SERIAL   Serial3

char c = ' ';
const unsigned long baudRateBT = 9600;

void setup() {
  Serial.begin(9600);
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");

  BT_SERIAL.begin(baudRateBT);
  Serial.print("BTserial started at "); Serial.println(baudRateBT);
  Serial.println(" ");
}

void loop() {
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BT_SERIAL.available()) {
    c = BT_SERIAL.read();
    Serial.write(c);
  }

  // Read from the Serial Monitor and send to the Bluetooth module
  if (Serial.available()) {
    c = Serial.read();
    BT_SERIAL.write(c);
  }
}
