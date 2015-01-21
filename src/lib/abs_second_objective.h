
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

void abs_second_objective(e_scoring_options second_start_pos)
{
	if(g_input_array[SECOND_OBJECTIVE]==STOP)
	{
		abs_auto_end(g_input_array[FIRST_OBJECTIVE]);
	}

	switch(second_start_pos)
	{
	case CENTER_GOAL:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case STOP:
			switch(g_input_array[FIRST_OBJECTIVE])
			{
			case ROLLGOAL1:
				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(ROLLGOAL1);
				break;
			case CENTER_GOAL:
				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(CENTER_GOAL);
				break;
			case ROLLGOAL2:
				wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(ROLLGOAL2);
				break;
			}
			break;
		case ROLLGOAL1: //ROLLING GOAL 1


			while(true){nxtDisplayBigTextLine(2,"%2d",g_center_goal_pos);}

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL1);
			break;
		case ROLLGOAL2: //ROLLING GOAL 2

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL2);
			break;
		}
		break;
	case STOP:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case ROLLGOAL1: //ROLLING GOAL 1

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL1);
			break;
		case CENTER_GOAL: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(CENTER_GOAL);
			break;
		case ROLLGOAL2:

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL2);
			break; //ROLLING GOAL 2
		}
		break;
	case ROLLGOAL1:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case CENTER_GOAL: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);



			abs_auto_end(CENTER_GOAL);
			break;
		case ROLLGOAL2: //ROLLING GOAL 2

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL2);
			break;
		}
		break;
	case ROLLGOAL2:
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case ROLLGOAL1: //ROLLING GOAL 1

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL1);
			break;
		case CENTER_GOAL: //CENTER GOAL

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(CENTER_GOAL);
			break;
		}
		break;
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
