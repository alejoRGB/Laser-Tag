#include <Servo.h>
//variables para alternar la lectura

//Varibles para la lectura del sensor luminico
int light;
int led = 11;

//varibles para los potenciometros que controla el servo
int potX;

//control de los servomotores
Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(9600);

  //ledmode - output
  pinMode(led, OUTPUT);

  //asignamos pin servo
  servoX.attach(A5);
  servoY.attach(A3);
}

void loop() {
  //chequea si el sensor esta recibiendo luz
  //del laser, se apaga. Si no esta recibiendo luz
  //del laser, se prende.

    light = analogRead(A0);

  if (light < 2) {
    analogWrite(led, 255);
  }
  else {
    analogWrite(led, 0);
  }
  delay(50);
  //imprime los valores del sensor a la consola
  //Serial.println(light);


  //lee los valores del potenciometro

    potX = analogRead(A1);
    




  //mover el servoX
  potX = map(potX, 0, 1023, 0, 180);
  servoX.write(potX);
  servoY.write(potX);
  delay(50);

}
