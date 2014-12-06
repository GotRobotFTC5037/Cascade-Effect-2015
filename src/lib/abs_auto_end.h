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
		case 1:

			abs_turn(CLOCKWISE, POINT, TURN, 20, 60);
			abs_drive(FORWARD, E_ANGLE, 305, 100, true, CORRECTION_DRIVE_TYPE);
			abs_turn(CLOCKWISE, POINT, TURN, 40, 60);
			abs_drive(FORWARD, E_ANGLE, 15, 100, true, CORRECTION_DRIVE_TYPE);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 60, 60);
			abs_drive(FORWARD, E_ANGLE, 61, 100, true, CORRECTION_DRIVE_TYPE);

			break;								//LOW AREA
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
