/**
*
*  @file abs_floor_center.h
*
*  @brief part of mission going from floor to center
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_FLOOR_CENTER_H
#define ABS_FLOOR_CENTER_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

void abs_floor_center()
{
	abs_drive(BACKWARD, E_ANGLE, 60, 60, true, GYRO, DONT_SLOW_DOWN, NO_STALL_ACTION);
	wait1Msec(150);
	abs_sonar_floor_read();

	switch(g_center_goal_pos)
	{
	case 1:
		abs_drive(BACKWARD, E_ANGLE, 76, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 30/*23*/, 40, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 202, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		g_auto_lift_done = false;
		StartTask(abs_auto_center_pipe_score);
		wait1Msec(200);
		abs_turn(CLOCKWISE, POINT, TURN, 126, 40, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 12, 40, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		while(!g_auto_lift_done){}
		StopTask(abs_auto_center_pipe_score);

		wait1Msec(400);

		servo[shutter] = g_shutter_closed;

		wait1Msec(500);

		break;
	case 2:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 31, 40, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 140, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		g_auto_lift_done = false;
		StartTask(abs_auto_center_pipe_score);
		wait1Msec(200);
		abs_turn(CLOCKWISE, POINT, TURN, 74, 40, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 44, 40, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		while(!g_auto_lift_done){}
		StopTask(abs_auto_center_pipe_score);

		wait1Msec(400);

		servo[shutter] = g_shutter_closed;

		wait1Msec(500);
		break;
	case 3:
		abs_turn(CLOCKWISE, POINT, TURN, 31, 40, FORWARD);

		g_auto_lift_done = false;
		StartTask(abs_auto_center_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 80, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 33, 40, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 14, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		servo[shutter] = 155;

		while(!g_auto_lift_done){}
		StopTask(abs_auto_center_pipe_score);

		wait1Msec(200);

		servo[shutter] = g_shutter_open;

		break;
	default:
		while(true)
		{
			PlayTone(200,20);
			wait1Msec(250);
			PlayTone(300,20);
			wait1Msec(250);
		}
		break;
	}
}

#endif /* !ABS_FLOOR_CENTER_H */
