#include <Arduino.h>

/* 10000 step == 4mm */

#define step 22
#define dir 23
#define PI 3.14159265359

bool flag = false;

double height;

double calculate_height(double volume, double syringe_radius) {
  return volume / (PI * syringe_radius * syringe_radius) * 1000;
}

void setup()
{
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(9600);

  double volume = 1;                                    // ml
  double syringe_radius = 3;                            // mm
  height = calculate_height(volume, syringe_radius);    // mm
}

void loop()
{
  int time = 1;  // min

  if (!flag)
  {
    digitalWrite(dir, HIGH);

    int rounds = 10000 * height / 3.5; // 101,057.14285714285714285714285714
    int calculate_delay = time * 30000000 / rounds; // 296.86216689591022888073067674679

    Serial.println(rounds);
    Serial.println(calculate_delay);

    for (int Index = 0; Index < 101057; Index++)
    {
      digitalWrite(step, HIGH);

      delayMicroseconds(297);

      digitalWrite(step, LOW);

      delayMicroseconds(297);
    }
    flag = true;
  }
}