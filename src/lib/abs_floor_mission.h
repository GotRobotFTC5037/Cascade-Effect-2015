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
	motor(left_motor)=100;
	motor(right_motor)=100;
	wait10Msec(9999);
		//abs_drive(FORWARD, E_ANGLE, 335, 100, true, NON_SENSOR);
		servo[goal_claw] = g_goal_claw_down;
		break; //ROLLING GOAL 1
	case CENTER_GOAL: break; //CENTER GOAL
	case ROLLGOAL2: break; //ROLLING GOAL 2
	}
}

#endif /* !ABS_FLOOR_MISSION_H */
