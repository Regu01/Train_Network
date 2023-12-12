#include <Arduino.h>

#define NUM_RELAYS 4
const int relayPins[NUM_RELAYS] = {D0, D1, D2, D3};



void setup() {
  for (int i = 0; i < NUM_RELAYS; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH);
  }

  Serial.begin(9600);
  Serial.println("Hello, World!");
}

void activateRelay(int relayIndex) {
  Serial.print("---------------------");
  for (int i = 0; i < NUM_RELAYS; i++) {
    digitalWrite(relayPins[i], HIGH);
    Serial.print("Relay ");
    Serial.print(i + 1);
    Serial.println(": OFF");
  }

  digitalWrite(relayPins[relayIndex], LOW);
  Serial.print("Relay ");
  Serial.print(relayIndex + 1);
  Serial.println(": ON");
  Serial.print("---------------------");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 's') {
      for (int i = 0; i < NUM_RELAYS; i++) {
        activateRelay(i);
        delay(1000);
      }
    }
  }
}
