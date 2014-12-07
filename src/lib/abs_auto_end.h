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

void abs_auto_end(e_scoring_options second_start_pos)
{
	if(g_input_array[END_POINT]==STOP) return;

	switch(second_start_pos)
	{
	case CENTER_GOAL:
		switch(g_input_array[END_POINT])
		{
		case 1:




		break;								//LOW AREA
		}
		break;
	case STOP:
		break;
	case ROLLGOAL1:
		switch(g_input_array[END_POINT])
		{
		case PARKING_ZONE:

			abs_turn(CLOCKWISE, POINT, TURN, 25, 50);
			abs_drive(FORWARD, E_ANGLE, 600, 100, true, NON_SENSOR);//GYRO);

			abs_turn(CLOCKWISE, POINT, TURN, 40, 60);
			abs_drive(FORWARD, E_ANGLE, 15, 50, true, NON_SENSOR);//GYRO);

			//abs_turn(COUNTERCLOCKWISE, POINT, TURN, 60, 60);
			//abs_drive(FORWARD, E_ANGLE, 61, 100, true, GYRO);

			break;								//LOW AREA
		}
		break;
	case ROLLGOAL2:
		switch(g_input_array[END_POINT])
		{
		case 1: break;								//LOW AREA
		}
		break;
	}
}

#endif /* !ABS_AUTO_END_H */
