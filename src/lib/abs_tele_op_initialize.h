/**
*
*  @file abs_tele_op_initialize.h
*
*  @brief  does some important stuff before we do the teleop program
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*/
#ifndef ABS_TELE_OP_INITIALIZE_H
#define ABS_TELE_OP_INITIALIZE_H

#include "abs_sensors.h"

void abs_tele_op_initialize()
{
	if(joystick.joy1_TopHat == -1) g_joy1_enabled = true;
	if(joystick.joy2_TopHat == -1) g_joy2_enabled = true;
	StartTask(abs_sensors);

	motor[brush] = 0;
	servo[impellar1] = 127;
	servo[impellar2] = 127;
	servo[intake_shutter] = g_intake_shutter_up;
	nMotorEncoder(lift1) = 0;
	nMotorEncoder(shoulder) = 0;

	getJoystickSettings(joystick);

	//disableDiagnosticsDisplay(); EVIL DONT USE THIS LINE OF CODE, IT BREAKS THE CODE, SOMEHOW
}
#endif /* ABS_TELE_OP_INITIALIZE_H */
