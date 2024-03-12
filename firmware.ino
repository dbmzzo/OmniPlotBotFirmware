#include <Wire.h>
#include "State.h"
#include "Utils.h"
#include "Handlers.h"
#include "BLE_Service.h"
#include "Motion_Service.h"
#include "Constants.h"

void setup()
{
  Serial.begin(115200);
  initBLEService();
  initMotionService();
}

void loop()
{
  BLE.poll();
  motionLoop();
  checkSleepLoop();
}