     
/* 
Simple Interrupt example
by: Jordan McConnell
SparkFun Electronics
created on 10/29/11
license: Beerware- feel free to use this code and maintain
attribution. If we ever meet and you are overcome with gratitude,
feel free to express your feelings via beverage.
*/

int ledPin = 12;  // LED is attached to digital pin 13

void setup() {                
}

void loop() {
  digitalWrite(ledPin, LOW);
  delay(3000); //pretend to be doing something useful
  digitalWrite(ledPin, HIGH);
}

