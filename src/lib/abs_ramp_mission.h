/**
*
*  @file abs_ramp_mission.h
*
*  @brief all autonomous movements resulting from starting on the ramp
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2014, got robot? FTC Team 5037
*
*/

#ifndef ABS_RAMP_MISSION_H
#define ABS_RAMP_MISSION_H

#include "abs_drive.h"

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case 0: break; //STOP
	case 1:
	abs_drive(FORWARD, E_ANGLE, 335, 100, true, GYRO);
	servo[goal_claw] = g_goal_claw_down;
	break; //ROLLING GOAL 1
	case 2: break; //CENTER GOAL
	case 3: break; //ROLLING GOAL 2
	}
}

#endif /* !ABS_RAMP_MISSION_H */
