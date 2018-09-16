/* Gra "Minutka"
   Pomysł: Antek Kaczor
   Realizacja: Paweł Kaczor

   Gra polega na wyliczeniu "w myślach" kiedy upłynie jedna minuta.
   Gracze naciskają swoje przyciski kiedy uważają, że nadszedł właściwy czas.
   Arduino zapamiętuje czas naciśnięcia i numer gracza.
   Gdy ostatni gracz przyciśnie swój przycisk, program wybiera czas najbliższy
   jednej minucie, sprawdza który gracz zwyciężył i zapala jego diodę.

   W program użyłem bibliotekę SevSeg, ułatwiającej zabawę z 7-segmentowym wyświetlaczem.
*/

#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
int pushButton = 18;         // pin Analog 4 - tu jest testowy przycisk
static int wynik1 = 0;       // wynik pierwszego gracza
#define interval 1000*60     // jedna minuta
unsigned long previousMillis=0;


void setup() {
  pinMode(pushButton, INPUT);
  byte numDigits = 4;   
  byte digitPins[] = {2, 3, 4, 5};
//  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  byte segmentPins[] = {13, 12, 11, 10, 9, 8, 7, 6};    // na mojej płytce odwróciłem kolejność pinów
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}


void loop() {
  unsigned long currentMillis = millis();
  static int deciSeconds = 0;
  
  if (digitalRead(pushButton) == 1) {
    if ((unsigned long)(currentMillis - previousMillis) >= interval) {
      
      sevseg.setNumber(wynik1, 1);
      previousMillis = currentMillis;
    }
   } else {
    
       sevseg.refreshDisplay(); // Must run repeatedly  
   }
}
/// END ///
