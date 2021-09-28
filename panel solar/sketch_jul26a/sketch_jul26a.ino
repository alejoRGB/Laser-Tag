int value;
int value2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  value = 0;
  value2 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  value2 = analogRead(A1);
  if (value > 300) {
    Serial.println("panel 1");
    Serial.println(value);
  }
  if (value2 > 300) {
    Serial.println("panel 2");
    Serial.println(value2);
  }


}
