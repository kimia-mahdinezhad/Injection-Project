struct Button {
  const uint8_t PIN;
  bool pressed;
  unsigned long last_button_time;
};

Button button_right = {18, false, 0};
Button button_left = {17, false, 0};

void IRAM_ATTR button_right_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_right.last_button_time > 250) {
    Serial.println("right");
    button_right.pressed = true;
    button_right.last_button_time = button_time;
  }
}

void IRAM_ATTR button_left_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_left.last_button_time > 250) {
    Serial.println("left");
    button_left.pressed = true;
    button_left.last_button_time = button_time;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button_right.PIN, INPUT_PULLUP);
  pinMode(button_left.PIN, INPUT_PULLUP);
  attachInterrupt(button_left.PIN, button_left_press_interrupt, FALLING);
  attachInterrupt(button_right.PIN, button_right_press_interrupt, FALLING);
}

void loop() {
}
