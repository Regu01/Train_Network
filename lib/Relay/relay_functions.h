#ifndef RELAY_FUNCTIONS_H
#define RELAY_FUNCTIONS_H

#include <Arduino.h>
#include "pin_config.h"

extern const int relayPins[];

// Initialise les broches des relais
void setupRelays();

// Éteint/Allume tous les relais
void turnOffAllRelays();
void turnOnAllRelays();

// Active un relais spécifique tout en éteignant les autres
void activateRelay(int relayIndex);
void activateTwoRelays(int relayIndex1, int relayIndex2);

void activateSequentialRelays(int startRelayIndex);

#endif
