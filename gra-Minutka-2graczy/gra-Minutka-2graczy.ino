/* Gra "Minutka"
   Pomysł: Antek Kaczor
   Realizacja: Paweł Kaczor

   Gra polega na wyliczeniu "w myślach" kiedy upłynie jedna minuta.
   Gracze naciskają swoje przyciski kiedy uważają, że nadszedł właściwy czas.
   Arduino zapamiętuje czas naciśnięcia i numer gracza.
   Gdy ostatni gracz przyciśnie swój przycisk, program wybiera czas najbliższy
   jednej minucie, sprawdza który gracz zwyciężył i zapala jego diodę.

   W program użyłem biblioteki SevSeg, ułatwiającej zabawę z 7-segmentowym wyświetlaczem.
*/

#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
int pushButton = 18;         // pin Analog 4 - tu jest testowy przycisk
static int wynik1 = 0;       // wynik pierwszego gracza
#define interval 6000        // jedna minuta
unsigned long previousMillis=0;
float diffMillis=0;  // różnica między zapamiętanymi a obecnymi millisami
float gracz1=0;
float gracz2=0;
int ileRazy=0;      // ile razy gramy?
float winner;

void saveTimer(unsigned long currentMillis){
    diffMillis = currentMillis - previousMillis;
    if (ileRazy == 0) {
      gracz1 = diffMillis;
      ileRazy++;
    } else if (ileRazy == 1) {
      gracz2 = diffMillis;
      ileRazy++;
    } else if (ileRazy == 2) {
      winner = max(gracz1, gracz2);
    }
      if (diffMillis > 5000) {  // nie sprawdzam poniżej 5 sek. od poprzedniego naciśnięcia (tyle też trwa wyświetlenie)
          Serial.print("Roznica wynosi: ");
          Serial.print(currentMillis);
          Serial.print(" - ");
          Serial.print(previousMillis);
          Serial.print(" = ");
          Serial.print(diffMillis);
          Serial.print(" czyli ");
          Serial.print(diffMillis / 1000);
          Serial.println(" sekund.");
          Serial.print("ileRazy: ");
          Serial.println(ileRazy);
          Serial.print("gracz1: ");
          Serial.println(gracz1);
          Serial.print("gracz2: ");
          Serial.println(gracz2);
          Serial.print("And the Winner is: ");
          Serial.println(winner);
          previousMillis = currentMillis;
          sevseg.setNumber(diffMillis/1000, 0);
      }
}


void setup() {
  pinMode(pushButton, INPUT_PULLUP);
  // Konsola debugowania ;)
  Serial.begin(9600);
  delay(1000);  // czekam 1s na zainicjowanie Seriala
  Serial.println("Startuję...");
  // Ustawienia 7-segmentowego wyświetlacza
  byte numDigits = 4;   
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {13, 12, 11, 10, 9, 8, 7, 6};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(pushButton) == HIGH) {
    saveTimer(currentMillis);
    sevseg.refreshDisplay(); // Must run repeatedly

   } else {

    // Serial.println(currentMillis);
    
   }
}

