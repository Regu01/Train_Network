#include <Arduino.h>
#include "relay_functions.h"
#include "canton_functions.h"

const int relayPins[] = {RELAY_PIN_1, RELAY_PIN_2, RELAY_PIN_3, RELAY_PIN_4};
const int cantonPins[] = {CANTON_PIN_1, CANTON_PIN_2};

void setup() {
  setupRelays();
  setupCantons();

  Serial.begin(9600);
  Serial.println("Hello, World!");
}

void loop() {

  int cantonStates[NUM_CANTONS];
  readAllCantonStates(cantonStates);
  delay(500);

  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case 'q':
        turnOnAllRelays();
        break;

      case 's':
        turnOffAllRelays();
        break;

      case 'a':
        activateSequentialRelays(0);
        break;

      case 'z':
        activateSequentialRelays(1);
        break;

      case 'e':
        activateSequentialRelays(2);
        break;

      case 'r':
        activateSequentialRelays(3);
        break;



      default:
        delay(1000);
        break;
    }
  }
}
