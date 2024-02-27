#include <Arduino.h>
#include "Utils.h"
#include "State.h"
#include "BLE_Service.h"

bool hasJoystickValues() {
  return speed != 0.0 || direction != 0.0 || rotation != 0.0;
}
