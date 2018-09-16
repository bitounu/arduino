/*
  Kolejne naciśnięcie gra kolejny, co raz wyższy ton
  * 8-ohm speaker on digital pin 8
  http://www.arduino.cc/en/Tutorial/Tone
  
*/
#include "pitches.h"

int noteDuration = 2; // długość tonu, 2 = pół nuty

int myPin = 19;       // pin Analog 5 - tu podłączony jest bzykacz
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


