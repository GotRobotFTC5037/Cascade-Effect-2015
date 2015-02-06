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
#define ABS_TELE_OP_INITIALI
#ifndef ABS_RAMP_MISSION_H
#define ABS_RAMP_MISSION_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

//#include "global_variables.h"

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP:
		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(STOP);
		break; //STOP
	case ROLLGOAL1:
		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN);
		//StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN);

		while(true){}

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);
		abs_second_objective(ROLLGOAL1);
		break;
	case CENTER_GOAL:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(CENTER_GOAL);
		break;
	case ROLLGOAL2:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(ROLLGOAL2);
		break;
	case KICK_STAND:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(KICK_STAND);ZE_H

#include "abs_sensors.h"

void abs_tele_op_initialize()
{
	if(joystick.joy1_TopHat == -1) g_joy1_enabled = true;
	if(joystick.joy2_TopHat == -1) g_joy2_enabled = true;
	StartTask(abs_sensors);

	motor[brush] = 0;
	servo[impellar1] = 127;
	servo[impellar2] = 127;
	nMotorEncoder(lift1) = 0;
	nMotorEncoder(shoulder) = 0;

	getJoystickSettings(joystick);

	//disableDiagnosticsDisplay(); EVIL DONT USE THIS LINE OF CODE, IT BREAKS THE CODE, SOMEHOW
}
#endif /* ABS_TELE_OP_INITIALIZE_H */
