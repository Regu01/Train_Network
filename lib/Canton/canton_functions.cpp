#include "canton_functions.h"

void setupCantons() {
  // Configuration des broches pour les cantons
  for (int i = 0; i < NUM_CANTONS; i++) {
    pinMode(cantonPins[i], INPUT);
  }
}

int readCantonState(int cantonIndex) {
  return digitalRead(cantonPins[cantonIndex]);
}

void readAllCantonStates(int* states) {
  for (int i = 0; i < NUM_CANTONS; i++) {
    states[i] = readCantonState(i);
  }

    for (int i = 0; i < NUM_CANTONS; i++) {
    Serial.print("Canton ");
    Serial.print(i + 1);
    Serial.print(" state: ");
    Serial.println(states[i]);
  }
}