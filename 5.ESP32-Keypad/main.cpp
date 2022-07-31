#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

byte rowPins[ROWS] = {23, 22, 16, 21}; 
byte colPins[COLS] = {19, 18, 5};

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {' ', '0', ' '}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
}