/**
*
*  @file abs_auto_end.h
*
*  @brief all autonomous movements to end the program
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_AUTO_END_H
#define ABS_AUTO_END_H

#include "abs_drive.h"

void abs_auto_end(e_second_objective_pos second_start_pos)
{
	if(g_input_array[END_POINT]==0) return;

	switch(second_start_pos)
	{
	case SECOND_CENTER:
		switch(g_input_array[END_POINT])
		{
		case 1: break;								//LOW AREA
		}
		break;
	case SECOND_STOP:
		break;
	case SECOND_ROLLGOAL1:
		switch(g_input_array[END_POINT])
		{
		case 1: break;								//LOW AREA
		}
		break;
	case SECOND_ROLLGOAL2:
		switch(g_input_array[END_POINT])
		{
		case 1: break;								//LOW AREA
		}
		break;
	}
}

#endif /* !ABS_AUTO_END_H */