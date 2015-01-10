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
#include "abs_auto_pipe_score.h"
#include "abs_auto_pipe_lower.h"

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

			StopTask(abs_auto_pipe_score);
			StartTask(abs_auto_pipe_lower);
			abs_turn(CLOCKWISE, POINT, TURN, 30, 40);
			abs_drive(FORWARD, E_ANGLE, 460, 100, true, GYRO);

			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 200, 60);
			abs_drive(BACKWARD, E_ANGLE, 30, 100, true, GYRO);


			//abs_turn(CLOCKWISE, POINT, TURN, 45, 60);
			//abs_drive(FORWARD, E_ANGLE, 85, 100, true, NON_SENSOR);//GYRO);

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
