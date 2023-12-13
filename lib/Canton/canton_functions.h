#ifndef CANTON_FUNCTIONS_H
#define CANTON_FUNCTIONS_H

#include <Arduino.h>
#include "pin_config.h"

extern const int cantonPins[];

void setupCantons();
int readCantonState(int cantonIndex);
void readAllCantonStates(int* states);

#endif
