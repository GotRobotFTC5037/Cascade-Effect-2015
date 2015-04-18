/**
*
*  @file abs_center_kick.h
*
*  @brief part of mission going from center goal to the KICK_STAND
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_CENTER_KICK_H
#define ABS_CENTER_KICK_H

#include "abs_turn.h"
#include "abs_drive.h"
#include "abs_auto_end.h"
#include "abs_auto_pipe_lower.h"
#include "abs_auto_pipe_score_tall.h"

void abs_center_kick()
{
	StartTask(abs_auto_pipe_lower);

	switch(g_center_goal_pos)
	{
	case 1:
		abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 89, 40, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 68, 45, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(300);
		abs_turn(CLOCKWISE, POINT, TURN, 88, 40, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 240, 90, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 300, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(CLOCKWISE, SWING, TURN, 90, 90, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 150, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 60, 90, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 40, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;

		case 2:
		abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 89, 40, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 81, 45, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(300);
		abs_turn(CLOCKWISE, POINT, TURN, 90, 40, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 205, 90, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 215, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 180, 70, BACKWARD);
		abs_drive(BACKWARD, E_ANGLE, 42, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;

		default:
		abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 89, 40, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 81, 45, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(300);
		abs_turn(CLOCKWISE, POINT, TURN, 90, 40, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 150, 90, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 170, 90, FORWARD);
		break;
	}
	StopTask(abs_auto_pipe_lower);

	wait1Msec(200);
}

#endif /* !ABS_CENTER_KICK_H */
