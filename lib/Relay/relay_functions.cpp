#include "relay_functions.h"

void setupRelays() {
  for (int i = 0; i < NUM_RELAYS; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH);
  }
}

void turnOffAllRelays() {
  for (int i = 0; i < NUM_RELAYS; i++) {
    digitalWrite(relayPins[i], HIGH);
    Serial.println("All Relay : OFF");
  }
}

void turnOnAllRelays() {
  for (int i = 0; i < NUM_RELAYS; i++) {
    digitalWrite(relayPins[i], LOW);
    Serial.println("All Relay : ON");
  }
}

void activateRelay(int relayIndex) {
  Serial.println("---------------------");
  turnOffAllRelays();  // Éteindre tous les relais avant d'activer le spécifique
  digitalWrite(relayPins[relayIndex], LOW);  // Activer le relais spécifié
  Serial.print("Relay ");
  Serial.print(relayIndex + 1);
  Serial.println(": ON");
  Serial.println("---------------------");
}

void activateTwoRelays(int relayIndex1, int relayIndex2) {
  Serial.println("---------------------");
  turnOffAllRelays();  // Éteindre tous les relais avant d'activer les spécifiés
  digitalWrite(relayPins[relayIndex1], LOW);
  digitalWrite(relayPins[relayIndex2], LOW);
  Serial.print("Relay ");
  Serial.print(relayIndex1 + 1);
  Serial.print(" and Relay ");
  Serial.print(relayIndex2 + 1);
  Serial.println(": ON");
  Serial.println("---------------------");
}

void activateSequentialRelays(int startRelayIndex) {
  Serial.println("---------------------");
  
  // Éteindre tous les relais
  turnOffAllRelays();
  
  int relayToActivate = startRelayIndex;
  int nextRelay = (relayToActivate + 1) % NUM_RELAYS;

  digitalWrite(relayPins[relayToActivate], LOW);
  digitalWrite(relayPins[nextRelay], LOW);

  Serial.print("Relay ");
  Serial.print(relayToActivate + 1);
  Serial.print(" and Relay ");
  Serial.print(nextRelay + 1);
  Serial.println(": ON");

  Serial.println("---------------------");
}

