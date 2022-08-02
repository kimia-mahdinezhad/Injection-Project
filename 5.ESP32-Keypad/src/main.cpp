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
unsigned long last_button_time = 0;
unsigned long hold_time = 0;

int row_number, column_number;

void IRAM_ATTR row_1_press_interrupt()
{
  hold_time = millis();
  flag = true;

  row_number = 0;
  column_number = -1;

  for (int col = 0; col < COLS; col++)
  {
    digitalWrite(colPins[col], LOW);
  }

  for (int col = 0; col < COLS; col++)
  {
    digitalWrite(colPins[col], HIGH);
    if (digitalRead(rowPins[row_number]))
    {
      column_number = col;
    }
    digitalWrite(colPins[col], LOW);
  }

  for (int col = 0; col < COLS; col++)
  {
    digitalWrite(colPins[col], HIGH);
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(rowPins[0], INPUT);

  // for (int col = 0; col < COLS; col++)
  // {
  //   pinMode(colPins[col], OUTPUT);
  // }

  // for (int row = 0; row < ROWS; row++)
  // {
  //   pinMode(rowPins[row], INPUT_PULLUP);
  // }

  attachInterrupt(digitalPinToInterrupt(rowPins[0]), row_1_press_interrupt, CHANGE);
}

void loop()
{
  if (flag && digitalRead(rowPins[0]))
  {
    if (millis() - hold_time > 50)
    {
      key = keys[row_number][column_number];
      Serial.print(key);
      flag = false;
      hold_time = 0;
    }
  }

  // if (key != '\0')
  // {
  //   Serial.println(key);
  //   key = '\0';
  // }
}