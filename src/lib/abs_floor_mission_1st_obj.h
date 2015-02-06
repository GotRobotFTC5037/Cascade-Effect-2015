/**
*
*  @file abs_floor_mission_1st_obj.h
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

#ifndef ABS_FLOOR_MISSION_1ST_OBJ_H
#define ABS_FLOOR_MISSION_1ST_OBJ_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_IR_floor_read.h"
#include "lib/abs_auto_center_pipe_score.h"
#include "lib/abs_auto_pipe_lower_mid.h"

void abs_floor_mission_1st_obj(e_scoring_options objective, int center_goal_pos)
{
	switch(objective)
	{

 	/** do nothing in these cases */
	case STOP:
	case ROLLGOAL2:
		break;


	case ROLLGOAL1:
		abs_drive(BACKWARD, E_ANGLE, 60, 50, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(CLOCKWISE, POINT, TURN, 37, 34);
		abs_drive(BACKWARD, E_ANGLE, 474, 50, true, GYRO, DONT_SLOW_DOWN);

		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 38, 38);

		StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 15, true, GYRO, DONT_SLOW_DOWN);
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);

		break; //ROLLING GOAL 1

	case CENTER_GOAL:
		switch(center_goal_pos)
		{
		case 1:
			abs_drive(BACKWARD, E_ANGLE, 100, 60, true, GYRO, DONT_SLOW_DOWN);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 23, 40);

			abs_drive(BACKWARD, E_ANGLE, 250, 60, true, GYRO, DONT_SLOW_DOWN);

			g_auto_lift_done = false;
			StartTask(abs_auto_center_pipe_score);
			wait1Msec(200);
			abs_turn(CLOCKWISE, POINT, TURN, 112, 40);

			abs_drive(BACKWARD, E_ANGLE, 8, 40, true, GYRO, DONT_SLOW_DOWN);

			while(!g_auto_lift_done){}
			StopTask(abs_auto_center_pipe_score);

			wait1Msec(400);

			servo[shutter] = g_shutter_closed;

			break;
		case 2:
			abs_drive(BACKWARD, E_ANGLE, 60, 60, true, GYRO, DONT_SLOW_DOWN);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 31, 40);

			abs_drive(BACKWARD, E_ANGLE, 130, 60, true, GYRO, DONT_SLOW_DOWN);

			g_auto_lift_done = false;
			StartTask(abs_auto_center_pipe_score);
			wait1Msec(200);
			abs_turn(CLOCKWISE, POINT, TURN, 74, 40);

			abs_drive(BACKWARD, E_ANGLE, 44, 40, true, GYRO, DONT_SLOW_DOWN);

			while(!g_auto_lift_done){}
			StopTask(abs_auto_center_pipe_score);

			wait1Msec(400);

			servo[shutter] = g_shutter_closed;

			break;
		case 3:
			abs_drive(BACKWARD, E_ANGLE, 60, 60, true, GYRO, DONT_SLOW_DOWN);
			abs_turn(CLOCKWISE, POINT, TURN, 31, 40);

			g_auto_lift_done = false;
			StartTask(abs_auto_center_pipe_score);
			abs_drive(BACKWARD, E_ANGLE, 78, 60, true, GYRO, DONT_SLOW_DOWN);

			wait1Msec(200);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 33, 40);

			abs_drive(BACKWARD, E_ANGLE, 16, 60, true, GYRO, DONT_SLOW_DOWN);

			servo[shutter] = 155;

			while(!g_auto_lift_done){}
			StopTask(abs_auto_center_pipe_score);

			wait1Msec(200);

			servo[shutter] = g_shutter_closed;

			break;

		/** unrecognized center goal position */
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
	default:
		break;
	}
}

#endif /* !ABS_FLOOR_MISSION_1ST_OBJ_H */
