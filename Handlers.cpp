#include "State.h"
#include "Handlers.h"
#include "Constants.h"

void blePeripheralConnectHandler(BLEDevice central)
{
  // central connected event handler
  if (Serial)
  {
    Serial.print("Connected event, central: ");
    Serial.println(central.address());
  }
}

void blePeripheralDisconnectHandler(BLEDevice central)
{
  // central disconnected event handler
  if (Serial)
  {
    Serial.print("Disconnected event, central: ");
    Serial.println(central.address());
  }
}

void characteristicWrittenHandler(BLEDevice central, BLECharacteristic characteristic)
{
  if (strcmp(characteristic.uuid(), DIR_UUID) == 0)
  {
    float floatValue;
    characteristic.readValue(&floatValue, 4);
    direction = floatValue;
  }
  else if (strcmp(characteristic.uuid(), SPEED_UUID) == 0)
  {
    float floatValue;
    characteristic.readValue(&floatValue, 4);
    speed = floatValue;
  }
  else if (strcmp(characteristic.uuid(), ROTATION_UUID) == 0)
  {
    float floatValue;
    characteristic.readValue(&floatValue, 4);
    rotation = floatValue;
  }
}
