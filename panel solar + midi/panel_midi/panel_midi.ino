#include <MIDIUSB.h>


int value;
int value2;

bool sendingNoteA;
bool sendingNoteB;
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  value = 0;
  value2 = 0;

  //Inicializar los valores booleanos en falso
  sendingNoteA = false;
  sendingNoteB = false;
}

void loop() {
  /*
    Serial.println("Sending note on");
    noteOn(2, 48, 127);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
    Serial.println("Sending note off");
    noteOff(2, 48, 127);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(1500);
  */

  // Asigna a las variables el valor de la lectura analogica
  value = analogRead(A0);
  value2 = analogRead(A1);

  //Chequea si hay un laser apuntando
  if (value > 300) {
    sendingNoteA = true;

  }
  if (value < 300) {
    sendingNoteA = false;
  }

  if (value2 > 300) {
    sendingNoteB = true;
  }
  if (value2 < 300) {
    sendingNoteB = false;
    }
  
  //-------------------------------------------------------------------------------------------------------
  //Chequea los valores booleanos y manda las notas midi
  if (sendingNoteA == true) {
    noteOn(2, 48, 127);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    Serial.println("notaA");
  }
  else {
    noteOff(2, 48, 127);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
  }

  if (sendingNoteB == true) {
    noteOn(3, 55, 127);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    Serial.println("notaB");
  }
  else {
    noteOff(3,55, 127);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
  }



}
