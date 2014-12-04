/**
*
*  @file abs_second_objective.h
*
*  @brief all autonomous movements resulting after the first scoring movement
*
*  @param second_start_pos where on the field the robot is placed after
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SECOND_OBJECTIVE_H
#define ABS_SECOND_OBJECTIVE_H

#include "abs_drive.h"
#include "abs_auto_end.h"

void abs_second_objective(e_second_objective_pos second_start_pos)
{
	if(g_input_array[SECOND_OBJECTIVE]==0)
	{
		wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_auto_end(SECOND_ROLLGOAL1);
		return;
	}

	switch(second_start_pos)
	{
	case SECOND_CENTER:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 0: //STOP
			switch(g_input_array[FIRST_OBJECTIVE])
			{
			case 1:

				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_ROLLGOAL1);
				break;
			case 2:
				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_CENTER);
				break;
			case 3:
				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_ROLLGOAL2);
				break;
			}
			break;
		case 1: //ROLLING GOAL 1

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL1);
			break;
		case 3: //ROLLING GOAL 2

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL2);
			break;
		}
		break;
	case SECOND_STOP:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 1: //ROLLING GOAL 1

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL1);
			break;
		case 2: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_CENTER);
			break;
		case 3:

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL2);
			break; //ROLLING GOAL 2
		}
		break;
	case SECOND_ROLLGOAL1:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 2: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_CENTER);
			break;
		case 3: //ROLLING GOAL 2

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL2);
			break;
		}
		break;
	case SECOND_ROLLGOAL2:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 1: //ROLLING GOAL 1

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_ROLLGOAL1);
			break;
		case 2: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(SECOND_CENTER);
			break;
		}
		break;
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
