#include <Arduino.h>

#define ROWS 4
#define COLS 3

struct Button
{
  byte pin;
  int column_number;
  bool pressed_flag;
  unsigned long hold_time;
};

struct Button keypad_rows[ROWS] = {{36, -1, false, 0}, {39, -1, false, 0}, {34, -1, false, 0}, {35, -1, false, 0}};
byte keypad_cols[COLS] = {23, 22, 21};

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

char key = '\0';

void init_keypad_press(int row_number)
{
  keypad_rows[row_number].column_number = -1;

  for (int col = 0; col < COLS; col++)
  {
    digitalWrite(keypad_cols[col], LOW);
  }

  for (int col = 0; col < COLS; col++)
  {
    pinMode(keypad_cols[col], OUTPUT);
    digitalWrite(keypad_cols[col], HIGH);

    if (digitalRead(keypad_rows[row_number].pin))
    {
      keypad_rows[row_number].column_number = col;
      break;
    }

    digitalWrite(keypad_cols[col], LOW);
    pinMode(keypad_cols[col], INPUT);
  }

  for (int col = 0; col < COLS; col++)
  {
    digitalWrite(keypad_cols[col], HIGH);
  }

  keypad_rows[row_number].pressed_flag = true;
  keypad_rows[row_number].hold_time = millis();
}

void IRAM_ATTR row_1_press_interrupt()
{
  init_keypad_press(0);
}

void IRAM_ATTR row_2_press_interrupt()
{
  init_keypad_press(1);
}

void IRAM_ATTR row_3_press_interrupt()
{
  init_keypad_press(2);
}

void IRAM_ATTR row_4_press_interrupt()
{
  init_keypad_press(3);
}

void setup()
{
  Serial.begin(9600);

  for (int col = 0; col < COLS; col++)
  {
    pinMode(keypad_cols[col], OUTPUT);
  }

  for (int row = 0; row < ROWS; row++)
  {
    pinMode(keypad_rows[row].pin, INPUT);
  }

  attachInterrupt(digitalPinToInterrupt(keypad_rows[0].pin), row_1_press_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(keypad_rows[1].pin), row_2_press_interrupt, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(keypad_rows[2].pin), row_3_press_interrupt, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(keypad_rows[3].pin), row_4_press_interrupt, CHANGE);
}

void loop()
{
  for (int row = 0; row < ROWS; row++)
  {
    if (keypad_rows[row].pressed_flag && digitalRead(keypad_rows[row].pin))
    {
      if (millis() - keypad_rows[row].hold_time > 150)
      {
        if (keypad_rows[row].column_number != -1)
        {
          key = keys[row][keypad_rows[row].column_number];
          Serial.printf("  %c  ", key);
        }

        keypad_rows[row].pressed_flag = false;
        keypad_rows[row].hold_time = 0;
        keypad_rows[row].column_number = -1;
      }
    }
  }
}