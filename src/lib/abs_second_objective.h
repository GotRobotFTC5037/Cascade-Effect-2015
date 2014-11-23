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

void abs_second_objective()
{
	switch(g_input_array[SECOND_OBJECTIVE])
	{
		case 0: break; //STOP
		case 1: break; //ROLLING GOAL 1
		case 2: break; //CENTER GOAL
		case 3: break; //ROLLING GOAL 2
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
