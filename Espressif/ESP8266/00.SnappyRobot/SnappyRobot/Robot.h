#ifndef robot_h_
#define robot_h_

#include <math.h>

#include "AccelStepper.h"

#define STEPPER_MAX_SPEED 1000.0
#define STEPPER_ACCELERATION 150.0
#define WHEEL_SEPARATION_RADIUS 54
#define WHEEL_RADIUS 30
#define STEPS_FULL_TURN 4076
#define WHEEL_TURN_DISTANCE (2 * M_PI * WHEEL_RADIUS)
#define WHEEL_STEP_DISTANCE (WHEEL_TURN_DISTANCE / STEPS_FULL_TURN)
#define TURN_ACTION_DISTANCE (M_PI * WHEEL_SEPARATION_RADIUS / 4)
#define TURN_ACTION_STEPS (TURN_ACTION_DISTANCE / WHEEL_STEP_DISTANCE)

extern AccelStepper stepperLeft;
extern AccelStepper stepperRight;

void setupSteppers();

#endif
