#include <Servo.h>

Servo servoX;
Servo servoY;

float posX=0;
float posY=0;

float mult =40;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoX.attach(A3);
  servoY.attach(A5);

  servoX.write(70);
  servoY.write(100);

  
}
void loop(){


servoX.write ((((sin(posX)*4)+1) * mult)+20);
  posX +=0.0005;


servoY.write ((((sin(posY)*4)+1) * mult)+80);
  posY +=0.0005;



/*
servoY.write (((sin(posY)+1) * mult)+80);
  posY +=0.0002;
*/
  
}




  
