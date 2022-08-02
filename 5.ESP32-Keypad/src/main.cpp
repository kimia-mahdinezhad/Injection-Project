#include <Arduino.h>

const byte ROWS = 4;
const byte COLS = 3;

byte rowPins[ROWS] = {23, 22, 16, 21};
byte colPins[COLS] = {19, 18, 5};

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {' ', '0', ' '}};

char key = '\0';
bool flag = false;

void IRAM_ATTR row_1_press_interrupt()
{
  flag = true;
  // int row_number = 0;
  // int column_number = -1;

  // for (int col = 0; col < COLS; col++)
  // {
  //   digitalWrite(colPins[col], LOW);
  // }

  // for (int col = 0; col < COLS; col++)
  // {
  //   digitalWrite(colPins[col], HIGH);
  //   if (digitalRead(rowPins[row_number]))
  //   {
  //     column_number = col;
  //   }
  //   digitalWrite(colPins[col], LOW);
  // }

  // for (int col = 0; col < COLS; col++)
  // {
  //   digitalWrite(colPins[col], HIGH);
  // }

  // key = keys[row_number][column_number];
}

void setup()
{
  Serial.begin(9600);

  pinMode(rowPins[0], INPUT_PULLUP);

  // for (int col = 0; col < COLS; col++)
  // {
  //   pinMode(colPins[col], OUTPUT);
  // }

  // for (int row = 0; row < ROWS; row++)
  // {
  //   pinMode(rowPins[row], INPUT_PULLUP);
  // }
  
  attachInterrupt(digitalPinToInterrupt(rowPins[0]), row_1_press_interrupt, FALLING);
}

void loop()
{
  if (flag) {
    Serial.print(" Pressed ");
    flag = false;
  }

  // if (key != '\0')
  // {
  //   Serial.println(key);
  //   key = '\0';
  // }
}