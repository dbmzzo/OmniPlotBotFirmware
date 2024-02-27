#include "State.h"
#include "Handlers.h"
#include "BLE_Service.h"
#include "Constants.h"

BLEFloatCharacteristic directionChar(DIR_UUID, BLEWriteWithoutResponse);
BLEDescriptor directionDesc(DESC_UUID, "Direction");
BLEDescriptor directionTypeDescriptor(DATA_TYPE_DESCRIPTOR_UUID, CHAR_DATA_TYPE_NAME[CharDataType::DATA_VELOCITY]);

BLEFloatCharacteristic rotationChar(ROTATION_UUID, BLEWriteWithoutResponse);
BLEDescriptor rotationDesc(DESC_UUID, "Rotation");
BLEDescriptor rotationTypeDescriptor(DATA_TYPE_DESCRIPTOR_UUID, CHAR_DATA_TYPE_NAME[CharDataType::DATA_ROTATION]);

BLEFloatCharacteristic speedChar(SPEED_UUID, BLEWriteWithoutResponse);
BLEDescriptor speedDesc(DESC_UUID, "Speed");
BLEDescriptor speedTypeDescriptor(DATA_TYPE_DESCRIPTOR_UUID, CHAR_DATA_TYPE_NAME[CharDataType::DATA_VELOCITY]);

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
  directionChar.addDescriptor(directionTypeDescriptor);
  directionChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  
  controlService.addCharacteristic(directionChar);
  directionChar.writeValue(0);

  rotationChar.addDescriptor(rotationDesc);
  rotationChar.addDescriptor(rotationTypeDescriptor);
  rotationChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  
  controlService.addCharacteristic(rotationChar);
  rotationChar.writeValue(0);

  speedChar.addDescriptor(speedDesc);
  speedChar.addDescriptor(speedTypeDescriptor);
  speedChar.setEventHandler(BLEWritten, characteristicWrittenHandler);
  controlService.addCharacteristic(speedChar);
  speedChar.writeValue(0);

  BLE.setAdvertisedService(controlService);
  BLE.addService(controlService);
  BLE.advertise();
}
