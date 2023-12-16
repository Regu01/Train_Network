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
    if(states[i] == 0) {
      Serial.print("Canton ");
      Serial.print(i + 1);
      Serial.print(" state: ");
      Serial.println(states[i]);
    }
  }
}


int readStableCantonStateWithMemory(int cantonIndex, int* lastState, int stabilityTime) {
  int currentState = digitalRead(cantonPins[cantonIndex]);
  int stableCount = 0;

  // Utiliser la dernière position connue comme état initial
  currentState = lastState[cantonIndex];
  
  // Attendre que l'état reste inchangé pendant la période de stabilité
  while (stableCount < stabilityTime) {
    delay(1);  // Attente d'une milliseconde
    int newState = digitalRead(cantonPins[cantonIndex]);

    if (newState == currentState) {
      stableCount++;
    } else {
      currentState = newState;
      stableCount = 0;
    }
  }

  // Mettre à jour la dernière position connue
  lastState[cantonIndex] = currentState;

  return currentState;
}