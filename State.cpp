#include "State.h"

BLEService controlService("66879f41-f094-44e2-8da7-2231d83bddd4");

AccelStepper w1(AccelStepper::DRIVER, W1_STEP, W1_DIR);
AccelStepper w2(AccelStepper::DRIVER, W2_STEP, W2_DIR);
AccelStepper w3(AccelStepper::DRIVER, W3_STEP, W3_DIR);
MultiStepper steppers;

float speed = 0.0; 
float direction = 0.0;
float rotation = 0.0;
int isSleeping = 0; 
long unsigned int wakeTimer = millis(); 
