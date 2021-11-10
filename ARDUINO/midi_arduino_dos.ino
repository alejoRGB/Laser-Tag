
//variables que leen los valores analogicos de los paneles
int panel_1;
int panel_2;
int panel_3;
int panel_4;
int panel_5;
int panel_6;
int panel_7;
int panel_8;
int panel_9;
int panel_10;
int panel_11;

int var_1;
int var_2;
int var_3;
int var_4;
int var_5;
int var_6;
int var_7;
int var_8;
int var_9;
int var_10;

//variable que controla el delay entre la lectura de los paneles
int delayentrepaneles = 25;
//variable que controla el threshold para detectar el laser y mandar la señal
int thr = 250;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  panel_1  = 0;
  panel_2  = 0;
  panel_3  = 0;
  panel_4  = 0;
  panel_5  = 0;
  panel_6  = 0;
  panel_7  = 0;
  panel_8  = 0;
  panel_9  = 0;
  panel_10 = 0;


  //  300 = 300;

}

void loop() {

  //lectura de los sensores
  panel_1 = analogRead(A11);
  delay(delayentrepaneles);

  panel_2 = analogRead(A10);
  delay(delayentrepaneles);

  panel_3 = analogRead(A9);
  delay(delayentrepaneles);

  panel_4 = analogRead(A8);
  delay(delayentrepaneles);

  panel_5 = analogRead(A7);
  delay(delayentrepaneles);

  panel_6 = analogRead(A6);
  delay(delayentrepaneles);

  panel_7 = analogRead(A5);
  delay(delayentrepaneles);

  panel_8 = analogRead(A4);
  delay(delayentrepaneles);

  panel_7 = analogRead(A3);
  delay(delayentrepaneles);

  panel_9 = analogRead(A2);
  delay(delayentrepaneles);

  panel_10 = analogRead(A1);
  delay(50);

  panel_11 = analogRead(A0);
  delay(delayentrepaneles);
  //-----------------------------------------------


    //Chekeo del panel 1
    //chanel 1 = 144
        if (panel_1 > thr && var_1 == 0) {
          var_1 = 1;

          Serial.write(144);
          Serial.write(60);
          Serial.write(100);
         // Serial.println(panel_1);

        }
        else if (panel_1 <= thr && var_1 == 1 ){

          var_1 = 2;
          Serial.write(144);
          Serial.write(60);
          Serial.write(0);

        }
        else if (panel_1 <= thr && var_1 == 2 ){
          var_1=0;
          }

    //Chekeo del panel 2
    //chanel 2 = 145
        if (panel_2 >= thr-1 && var_2 == 0) {
          var_2 = 1;
         // Serial.println(panel1);
          Serial.write(145);
          Serial.write(60);
          Serial.write(100);
          //Serial.println(panel1);

        }
        else if (panel_2 <= thr && var_2 == 1){
          var_2 = 2;
          Serial.write(145);
          Serial.write(60);
          Serial.write(0);

        }
        else if (panel_2 <= thr && var_2 == 2){
          var_2=0;
          }
  

  //Chekeo del panel 3
  //chanel 3 = 146
  if (panel_3 > thr && var_3 == 0) {
    var_3 = 1;
    
     Serial.write(146);
     Serial.write(60);
     Serial.write(100);
     //Serial.println(panel_3);

  }
  else if (panel_3 <= thr && var_3 == 1) {
    var_3 = 2;
   Serial.write(146);
   Serial.write(60);
   Serial.write(0);

  }
  else if (panel_3 <= thr && var_3 == 2){
    var_3 = 0;
  }

  /*
      //Chekeo del panel 4
          //chanel 4 = 147
          if (panel_4 > 300 && var_4 == 0) {
            var_4 = 1;
           // Serial.println(panel1);
            Serial.write(147);
            Serial.write(60);
            Serial.write(100);
            //Serial.println(panel1);

          }
          else if (panel_4 < 300 && var_4 == 1){
            var_4 = 2;
            Serial.write(147);
            Serial.write(60);
            Serial.write(0);

          }
          else{
            var_4=0;
            }
  */
}
