#include "State.h"
#include "Motion_Service.h"
#include "Constants.h"
#include "Utils.h"
#include <AccelStepper.h>
#include <MultiStepper.h>

void sleepAll()
{
  isSleeping = 1;
  wakeTimer = millis();
  digitalWrite(SLEEP, LOW);
  delay(200);
}

void wakeAll()
{
  isSleeping = 0;
  wakeTimer = millis();
  digitalWrite(SLEEP, HIGH);
  delay(200);
}

void checkSleepLoop()
{
  if (!hasJoystickValues())
  {
    if (wakeTimer == 0.0)
    {
      wakeTimer = millis();
    }
    if (millis() - wakeTimer > SLEEP_DELAY && isSleeping == 0)
    {
      sleepAll();
    }
  }
  else if (isSleeping == 1)
  {
    wakeAll();
  }
}

void initMotionService()
{
  w1.setMaxSpeed(RUN_SPEED);
  w3.setMaxSpeed(RUN_SPEED);
  w2.setMaxSpeed(RUN_SPEED);
  w1.setAcceleration(ACCELERATION);
  w2.setAcceleration(ACCELERATION);
  w3.setAcceleration(ACCELERATION);
  steppers.addStepper(w1);
  steppers.addStepper(w2);
  steppers.addStepper(w3);
}

void motionLoop()
{
  if (hasJoystickValues())
  {
    float x = (speed * RUN_SPEED) * cos(direction);
    float y = (speed * RUN_SPEED) * sin(direction);

    float wheelRotation = rotation * RUN_SPEED;

    float w1Speed = x + wheelRotation;

    float w2Speed = (-0.5 * x - 0.86602540378 * y + wheelRotation);
    float w3Speed = (-0.5 * x + 0.86602540378  * y + wheelRotation);

    w1Speed = constrain(w1Speed, -RUN_SPEED, RUN_SPEED);
    w2Speed = constrain(w2Speed, -RUN_SPEED, RUN_SPEED);
    w3Speed = constrain(w3Speed, -RUN_SPEED, RUN_SPEED);

    w1.setSpeed(w1Speed);
    w2.setSpeed(w2Speed);
    w3.setSpeed(w3Speed);

    w1.runSpeed();
    w2.runSpeed();
    w3.runSpeed();
  }
}

