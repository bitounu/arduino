/*
  Star Wars przeróbka z dwóch innych szkiców
  * 8-ohm speaker on digital pin 8
  http://www.arduino.cc/en/Tutorial/Tone
  
*/
#include "pitches.h"

// nutki
int melody[] = {
    //  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 // oryginalna muzyczka
    // Star Wars anthem
    NOTE_A3, NOTE_A3, NOTE_A3, NOTE_F3, NOTE_C4,
    NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3,
    NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_C4,
    NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3,
    NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, NOTE_G4,
    NOTE_FS4, NOTE_E4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4,
    NOTE_C4, NOTE_B3, NOTE_C4, NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_A3,
    NOTE_C4, NOTE_A3, NOTE_C4, NOTE_E4,
    NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, NOTE_G4,
    NOTE_FS4, NOTE_E4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4,
    NOTE_C4, NOTE_B3, NOTE_C4, NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_C4,
    NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,  4,  4,  8,  16,
  4,  8,  16, 2,
  4,  4,  4,  8,  16,
  4,  8,  16, 2,
  4,  8,  16, 4,  8,  16,
  16, 16, 8,  8,  4,  8,  16,
  16, 16, 8, 8, 4, 8, 16,
  4, 8, 16, 2,
  4, 8, 16, 4, 8, 16,
  16, 16, 8, 8, 4, 8, 16,
  16, 16, 8, 8, 4, 8, 16,
  4, 8, 16, 2,
};

int myPin = 19;       // pin Analog 5 - tu podłączony jest bzykacz
int nPins = 68;       // melodia ma 68 nut
int pushButton = 18;  // pin Analog 4 startuje muzyczkę
  
void grajCyganie() {
  for (int thisNote = 0; thisNote < nPins; thisNote++) {
      // graj dopóki wciśnięty jest przycisk (Analog pin 4 ma stan HIGH)
      if (digitalRead(pushButton) == LOW) {
        break;
      } else {
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(myPin, melody[thisNote], noteDuration);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.50;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(myPin);
    }
  }
}

void nieGraj() {
    noTone(myPin);
}

void setup() {
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(pushButton) == HIGH) {
      grajCyganie();
   }
//  delay(1);        // delay in between reads for stability
}


