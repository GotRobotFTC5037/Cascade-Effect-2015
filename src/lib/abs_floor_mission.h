/**
*
*  @file abs_floor_mission.h
*
*  @brief all autonomous movements resulting from starting from the floor
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_FLOOR_MISSION_H
#define ABS_FLOOR_MISSION_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_IR_floor_read.h"
#include "lib/abs_auto_center_pipe_score.h"
#include "lib/abs_auto_pipe_lower_mid.h"

void abs_floor_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP: break; //STOP
	case ROLLGOAL1:
		abs_drive(BACKWARD, E_ANGLE, 60, 50, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(CLOCKWISE, POINT, TURN, 37, 34, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 474, 50, true, GYRO, DONT_SLOW_DOWN);

		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 38, 38, FORWARD);

		StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 15, true, GYRO, DONT_SLOW_DOWN);
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);

		abs_second_objective(ROLLGOAL1);
		break; //ROLLING GOAL 1
	case CENTER_GOAL:
		switch(g_center_goal_pos)
		{
		case 1:
			abs_drive(BACKWARD, E_ANGLE, 100, 60, true, GYRO, DONT_SLOW_DOWN);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 23, 40, FORWARD);

			abs_drive(BACKWARD, E_ANGLE, 250, 60, true, GYRO, DONT_SLOW_DOWN);

			g_auto_lift_done = false;
			StartTask(abs_auto_center_pipe_score);
			wait1Msec(200);
			abs_turn(CLOCKWISE, POINT, TURN, 112, 40, FORWARD);

			abs_drive(BACKWARD, E_ANGLE, 8, 40, true, GYRO, DONT_SLOW_DOWN);

			while(!g_auto_lift_done){}
			StopTask(abs_auto_center_pipe_score);

			wait1Msec(400);

			servo[shutter] = g_shutter_closed;

			abs_second_objective(CENTER_GOAL);

			break;
		//case 2:
		//	abs_drive(BACKWARD, E_ANGLE, 60, 60, true, GYRO, DONT_SLOW_DOWN);
		//	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 31, 40);

		//	abs_drive(BACKWARD, E_ANGLE, 130, 60, true, GYRO, DONT_SLOW_DOWN);

		//	g_auto_lift_done = false;
		//	StartTask(abs_auto_center_pipe_score);
		//	wait1Msec(200);
		//	abs_turn(CLOCKWISE, POINT, TURN, 74, 40);

		//	abs_drive(BACKWARD, E_ANGLE, 44, 40, true, GYRO, DONT_SLOW_DOWN);

		//	while(!g_auto_lift_done){}
		//	StopTask(abs_auto_center_pipe_score);

		//	wait1Msec(400);

		//	servo[shutter] = g_shutter_closed;

		//	abs_second_objective(CENTER_GOAL);
		//	break;
		//case 3:
		//	abs_drive(BACKWARD, E_ANGLE, 60, 60, true, GYRO, DONT_SLOW_DOWN);
		//	abs_turn(CLOCKWISE, POINT, TURN, 31, 40);

		//	g_auto_lift_done = false;
		//	StartTask(abs_auto_center_pipe_score);
		//	abs_drive(BACKWARD, E_ANGLE, 78, 60, true, GYRO, DONT_SLOW_DOWN);

		//	wait1Msec(200);
		//	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 33, 40);

		//	abs_drive(BACKWARD, E_ANGLE, 16, 60, true, GYRO, DONT_SLOW_DOWN);

		//	servo[shutter] = 155;

		//	while(!g_auto_lift_done){}
		//	StopTask(abs_auto_center_pipe_score);

		//	wait1Msec(200);

		//	servo[shutter] = g_shutter_closed;

		//	abs_second_objective(CENTER_GOAL);
		//	break;
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

		break; //CENTER GOAL
	case ROLLGOAL2: break; //ROLLING GOAL 2
	default: break;
	}
}

#endif /* !ABS_FLOOR_MISSION_H */
