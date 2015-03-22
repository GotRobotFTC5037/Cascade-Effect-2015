/**
*
*  @file abs_floor_roll1.h
*
*  @brief part of mission going from floor to ROLLGOAL1
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_FLOOR_ROLL1_H
#define ABS_FLOOR_ROLL1_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

void abs_floor_roll1()
{
	abs_drive(BACKWARD, E_ANGLE, 60, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(CLOCKWISE, POINT, TURN, 37, 34, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 474, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 38, 38, FORWARD);

		StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 15, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);
}

#endif /* !ABS_FLOOR_ROLL1_H */
