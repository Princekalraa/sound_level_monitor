const int soundSensorPin = A0;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int numLeds = 10;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int soundLevel = analogRead(soundSensorPin);
  int ledLevel = map(soundLevel, 0, 1023, 0, numLeds);

  for (int i = 0; i < numLeds; i++) {
    if (i < ledLevel) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(50);
}
