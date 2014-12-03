/**
*
*  @file abs_second_objective.h
*
*  @brief all autonomous movements resulting after the first scoring movement
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SECOND_OBJECTIVE_H
#define ABS_SECOND_OBJECTIVE_H

#include "abs_drive.h"

void abs_second_objective(e_second_start_pos second_start_pos)
{
	if(g_input_array[SECOND_OBJECTIVE]==0) return;

	switch(second_start_pos)
	{
	case SECOND_CENTER:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 1: break; //ROLLING GOAL 1
		case 3: break; //ROLLING GOAL 2
		}
		break;
	case SECOND_STOP:
		break;
	case SECOND_ROLLGOAL1:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 2: break; //CENTER GOAL
		case 3: break; //ROLLING GOAL 2
		}
		break;
	case SECOND_ROLLGOAL2:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 1: break; //ROLLING GOAL 1
		case 2: break; //CENTER GOAL
		}
		break;
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
