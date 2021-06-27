#include <Servo.h>

Servo servoX;
Servo servoY;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoX.attach(A5);
  servoY.attach(A0);

  servoY.write(45);

}

void loop() {
  
  servoX.write(30);
 // servoY.write(30);
  Serial.write("uno");
  
  delay(3000);
  
  servoX.write(0);
 // servoY.write(0);

  Serial.write("dos");

  delay(3000);
}
