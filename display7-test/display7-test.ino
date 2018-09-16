int dil;  // delay 

// piny w zestawie:
// 6 - kropka
// 7 - kreska środkowa

//   -13-
//  |    |
//  8    12
//  |    |
//   -7-
//  |    |
//  9    11
//  |    |
//   -10-

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  // ustawiam wszystkie używane piny na WYJŚCIE
   for (int i=2; i <= 13; i++){
      pinMode(i, OUTPUT);
   }
  
  for (int j=60; j>=1; j=j-5) {
    animka(j);
  }
  for (int j=1; j<=10; j++) {
    animka(5);
  }
  for (int j=1; j<=60; j=j+5) {
    animka(j);
  }

}

void loop() {

}

void animka(int dil){
  for (int i=2; i<=5; i++){
    digitalWrite(i, HIGH);
    zgas();
    digitalWrite(10, LOW);
    delay(dil);
    digitalWrite(i-1, LOW);
  }

// zakręt prawy 
    digitalWrite(11, LOW);
    delay(dil);
    digitalWrite(10, HIGH);
    delay(dil);
    digitalWrite(12, LOW);
    delay(dil);
    digitalWrite(11, HIGH);
    delay(dil);
  
  for (int i=5; i>=2; i--){
    digitalWrite(i, HIGH);
    zgas();
    digitalWrite(13, LOW);
    delay(dil);
    digitalWrite(i+1, LOW);
  }

// zakręt lewy
    digitalWrite(8, LOW);
    delay(dil);
    digitalWrite(13, HIGH);
    delay(dil);
    digitalWrite(9, LOW);
    delay(dil);
    digitalWrite(8, HIGH);
    delay(dil);
    zgas();
}

void zgas(){
  for (int i=6; i <= 13; i++){
    digitalWrite(i, HIGH);
  }  
}

