#ifndef BLE_Service_h
#define BLE_Service_h

#include <Arduino.h>
#include <ArduinoBLE.h>
#include <AccelStepper.h>

void characteristicWrittenHandler(BLEDevice central, BLECharacteristic characteristic);
void initBLEService();
void serviceLoop();
void sleepAll();
void wakeAll();

#endif
