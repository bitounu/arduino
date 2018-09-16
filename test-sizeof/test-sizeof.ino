
int NOTE_C4 = 4;
int NOTE_G3 = 3;
int i;

int melody[] = {
  NOTE_C4, NOTE_G3
};


void setup() {
  Serial.begin(9600);
}

void loop() {

 for (i = 0; i < sizeof(melody) - 1; i++){
    Serial.print(i, DEC);
    Serial.print(" = ");
    Serial.write(melody[i]);
    Serial.println();
  }
  delay(5000); // slow down the program
}
