#include "State.h"
#include "Handlers.h"
#include "BLE_Service.h"
#include "Constants.h"

BLEFloatCharacteristic directionChar(DIR_UUID, BLEWriteWithoutResponse);
BLEDescriptor directionDesc(DESC_UUID, "Direction");

BLEFloatCharacteristic rotationChar(ROTATION_UUID, BLEWriteWithoutResponse);
BLEDescriptor rotationDesc(DESC_UUID, "Rotation");

BLEFloatCharacteristic speedChar(SPEED_UUID, BLEWriteWithoutResponse);
BLEDescriptor speedDesc(DESC_UUID, "Speed");

void initBLEService() {
  if (!BLE.begin())
  {
    if (Serial)
    {
      Serial.println("starting Bluetooth® Low Energy failed!");
    }
    while (1)
      ;
  }
  BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
  BLE.setLocalName("OmniPlotBot");

  directionChar.addDescriptor(directionDesc);
  directionChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  controlService.addCharacteristic(directionChar);
  directionChar.writeValue(0);

  rotationChar.addDescriptor(rotationDesc);
  rotationChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  controlService.addCharacteristic(rotationChar);
  rotationChar.writeValue(0);

  speedChar.addDescriptor(speedDesc);
  speedChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  controlService.addCharacteristic(speedChar);
  speedChar.writeValue(0);

  BLE.setAdvertisedService(controlService);
  BLE.addService(controlService);
  BLE.advertise();
}
