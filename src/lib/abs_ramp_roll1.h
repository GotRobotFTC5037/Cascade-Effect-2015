/**
*
*  @file abs_ramp_roll1.h
*
*  @brief part of mission going from ramp to ROLLGOAL1
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_RAMP_ROLL1_H
#define ABS_RAMP_ROLL1_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

void abs_ramp_roll1()
{
	StartTask(abs_IR_center_read);
	abs_drive(BACKWARD, E_ANGLE, 265, 20, false, GYRO, SLOW_DOWN, NO_STALL_ACTION);
	wait1Msec(250);
	servo[shutter] = g_shutter_closed;
	StartTask(abs_auto_pipe_score);
	g_gyro_inherit = true;
	abs_drive(BACKWARD, E_ANGLE, 175, 16, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	if(g_sonar3>=26) {abs_turn(CLOCKWISE, SWING, TURN, 22, 40, BACKWARD);
		g_roll_to_parking_turn = 22;}
	else if(g_sonar3>=20){ abs_turn(CLOCKWISE, SWING, TURN, 16, 40, BACKWARD);
		g_roll_to_parking_turn = 16;}
	else if(g_sonar3>=17) { abs_turn(CLOCKWISE, SWING, TURN, 13, 40, BACKWARD);
		g_roll_to_parking_turn = 13;}
	else if(g_sonar3>=14) { abs_turn(CLOCKWISE, SWING, TURN, 8, 40, BACKWARD);
		g_roll_to_parking_turn = 8;}

	wait1Msec(200);
	servo[shutter] = g_shutter_closed;
	wait1Msec(2100);

	servo[shutter] = 155;
	servo[goal_claw] = g_goal_claw_down;
	g_auto_lift_done = true;
	StopTask(abs_auto_pipe_score);

	wait1Msec(800);

	StartTask(abs_auto_pipe_lower);

	wait1Msec(500);
}

#endif /* !ABS_RAMP_ROLL1_H */
