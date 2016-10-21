#include "Robot.h"

AccelStepper stepperLeft(AccelStepper::FULL4WIRE, D7, D5, D6, D4);
AccelStepper stepperRight(AccelStepper::FULL4WIRE, D0, D2, D1, D3);

void setupSteppers()
{
    stepperLeft.setMaxSpeed(STEPPER_MAX_SPEED);
    stepperLeft.setAcceleration(STEPPER_ACCELERATION);
    
    stepperRight.setMaxSpeed(STEPPER_MAX_SPEED);
    stepperRight.setAcceleration(STEPPER_ACCELERATION);
}
