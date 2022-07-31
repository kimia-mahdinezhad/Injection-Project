struct Button {
  const uint8_t PIN;
  unsigned long last_button_time;
};

Button button_right = {18, 0};
Button button_left = {17, 0};

void task1 (void * parameters) {
  for (;;) {
    if (!digitalRead(button_right.PIN)) {
      unsigned long button_time = millis();
      if (button_time - button_right.last_button_time > 250) {
        Serial.println("Right");
        button_right.last_button_time = button_time;
      }
    }

    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void task2 (void * parameters) {
  for (;;) {
    if (!digitalRead(button_left.PIN)) {
      unsigned long button_time = millis();
      if (button_time - button_left.last_button_time > 250) {
        Serial.println("Left");
        button_left.last_button_time = button_time;
      }
    }

    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(button_right.PIN, INPUT_PULLUP);
  pinMode(button_left.PIN, INPUT_PULLUP);

  xTaskCreate(
    task1,
    "Task 1",
    1000,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    task2,
    "Task 2",
    1000,
    NULL,
    1,
    NULL
  );
}

void loop() {
}
