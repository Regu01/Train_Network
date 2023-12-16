#include <Arduino.h>
#include "relay_functions.h"
#include "canton_functions.h"

const int relayPins[] = {RELAY_PIN_1, RELAY_PIN_2, RELAY_PIN_3, RELAY_PIN_4};
const int cantonPins[] = {CANTON_PIN_1, CANTON_PIN_2, CANTON_PIN_3, CANTON_PIN_4};
int lastCantonStates[NUM_CANTONS] = {HIGH, HIGH, HIGH, HIGH};  // Initialiser à HIGH
// void AutoSenario();

void setup() {
  setupRelays();
  setupCantons();

  Serial.begin(9600);
  Serial.println("Hello, World!");

  turnOnAllRelays();
}

// void loop() {
//   // int cantonStates[NUM_CANTONS];
//   // readAllCantonStates(cantonStates);
//   // delay(500);

//   if (Serial.available() > 0) {

//     char command = Serial.read();

//     switch (command) {
//       case 'q':
//         turnOnAllRelays();
//         break;

//       case 's':
//         turnOffAllRelays();
//         break;

//       case 'a':
//         activateSequentialRelays(0);
//         break;

//       case 'z':
//         activateSequentialRelays(1);
//         break;

//       case 'e':
//         activateSequentialRelays(2);
//         break;

//       case 'r':
//         activateSequentialRelays(3);
//         break;

//       default:
//         AutoSenario();
//         break;
//     }
//   }
// }


// void loop() {
//   int cantonStates[NUM_CANTONS];
//   static int lastCantonStates[NUM_CANTONS] = {HIGH, HIGH, HIGH, HIGH};  // Initialiser à HIGH

//   // Vérifier que le train est stable sur chaque canton avant de passer au suivant
//   for (int i = 0; i < NUM_CANTONS; i++) {
//     cantonStates[i] = readStableCantonStateWithMemory(i, lastCantonStates, 300);  // Période de stabilité d'une seconde
//   }

//     for (int i = 0; i < NUM_CANTONS; i++) {
//     if(cantonStates[i] == 0) {
//       Serial.print("Canton ");
//       Serial.print(i + 1);
//       Serial.print(" state: ");
//       Serial.println(cantonStates[i]);
//     }
//   }

//   if (cantonStates[0] == 0) {
//     // Canton 1 = 0
//     activateTwoRelays(0, 1);
//   } else if (cantonStates[1] == 0) {
//     // Canton 2 = 0
//     activateTwoRelays(1, 2);
//   } else if (cantonStates[2] == 0) {
//     // Canton 3 = 0
//     activateTwoRelays(2, 3);
//   } else if (cantonStates[3] == 0) {
//     // Canton 4 = 0
//     activateTwoRelays(3, 0);
//   } else {
//     Serial.println("Nothing");
//   }
// }



void loop() {
  int cantonStates[NUM_CANTONS];
  static int lastCantonStates[NUM_CANTONS] = {HIGH, HIGH, HIGH, HIGH};  // Initialiser à HIGH

  // Vérifier que le train est stable sur chaque canton avant de passer au suivant
  for (int i = 0; i < NUM_CANTONS; i++) {
    cantonStates[i] = readStableCantonStateWithMemory(i, lastCantonStates, 100);  // Période de stabilité d'une seconde
  }

    for (int i = 0; i < NUM_CANTONS; i++) {
    if(cantonStates[i] == 0) {
      Serial.print("Canton ");
      Serial.print(i);
      Serial.print(" state: ");
      Serial.println(cantonStates[i]);
    }
  }

  if (cantonStates[0] == 0) {
    // Canton 1 = 0
    activateTwoRelays(0, 3);
  } else if (cantonStates[3] == 0) {
    // Canton 2 = 0
    activateTwoRelays(3, 2);
  } else if (cantonStates[2] == 0) {
    // Canton 3 = 0
    activateTwoRelays(2, 1);
  } else if (cantonStates[1] == 0) {
    // Canton 4 = 0
    activateTwoRelays(1, 0);
  } else {
    Serial.println("Nothing");
  }
}