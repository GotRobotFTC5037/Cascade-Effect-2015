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

void abs_floor_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP: break; //STOP
	case ROLLGOAL1:
		abs_drive(BACKWARD, E_ANGLE, 60, 50, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(CLOCKWISE, POINT, TURN, 37, 34);
		abs_drive(BACKWARD, E_ANGLE, 474, 50, true, GYRO, SLOW_DOWN);

		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 38, 38);

		StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 15, true, GYRO, SLOW_DOWN);
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);

		abs_second_objective(ROLLGOAL1);
		break; //ROLLING GOAL 1
	case CENTER_GOAL: break; //CENTER GOAL
	case ROLLGOAL2: break; //ROLLING GOAL 2
	}
}

#endif /* !ABS_FLOOR_MISSION_H */
