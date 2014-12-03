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
		case 0: break; //STOP
		case 1: break; //ROLLING GOAL 1
		case 2: break; //CENTER GOAL
		case 3: break; //ROLLING GOAL 2
	}
}

#endif /* !ABS_FLOOR_MISSION_H */
