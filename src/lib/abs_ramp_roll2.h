/**
*
*  @file abs_ramp_roll2.h
*
*  @brief part of mission going from ramp to ROLLGOAL2
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_RAMP_ROLL2_H
#define ABS_RAMP_ROLL2_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

void abs_ramp_roll2()
{
	StartTask(abs_IR_center_read);
	abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	servo[goal_claw] = g_goal_claw_down;
	wait1Msec(500);

	abs_turn(COUNTERCLOCKWISE, SWING, TURN, 50, 90, FORWARD);
	servo[goal_claw] = g_goal_claw_up;
	abs_drive(BACKWARD, E_ANGLE, 20, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	wait1Msec(500);

	abs_drive(FORWARD, E_ANGLE, 26, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	g_auto_pipe_score_hight = g_tall_lift;
	g_auto_pipe_score_angle = g_shoulder_tall+700;
	StartTask(abs_auto_pipe_score);

	abs_turn(CLOCKWISE, SWING, TURN, 53, 90, FORWARD);
	abs_drive(BACKWARD, E_ANGLE, 60, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	abs_drive(BACKWARD, E_ANGLE, 30, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	while(!g_auto_lift_done){}
	wait1Msec(1000);

	servo[goal_claw] = g_goal_claw_down;
	wait1Msec(500);
}

#endif /* !ABS_RAMP_ROLL2_H */
