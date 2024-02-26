#include <Arduino.h>
#include "Utils.h"
#include "State.h"
#include "BLE_Service.h"

void resetAllPositions() {
  w1.setCurrentPosition(0);
  w2.setCurrentPosition(0);
  w3.setCurrentPosition(0);
}

bool hasJoystickValues() {
  return speed != 0.0 || direction != 0.0 || rotation != 0.0;
}