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
#include "abs_auto_pipe_lower_mid.h"
#include "abs_auto_pipe_score_tall.h"

#include "abs_center_kick.h"
#include "abs_roll1_roll2.h"
#include "abs_roll1_right_parkingzone.h"
#include "abs_roll1_left_parkingzone.h"

void abs_second_objective(e_first_objectives second_start_pos)
{
	if(g_input_array[SECOND_OBJECTIVE]==SECOND_STOP) abs_auto_end(g_input_array[FIRST_OBJECTIVE]);
	else
	{
		switch(second_start_pos)
		{
		case FIRST_CENTER_GOAL:
			switch(g_input_array[SECOND_OBJECTIVE])
			{
			case SECOND_KICK_STAND:
				abs_center_kick();
				wait1Msec(g_input_array[SECOND_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_KICK_STAND);
				break;
			default: break;
			}
			break;

		case FIRST_ROLLGOAL1:
			switch(g_input_array[SECOND_OBJECTIVE])
			{
			case SECOND_ROLLGOAL2:
				abs_roll1_roll2();
				wait1Msec(g_input_array[SECOND_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_ROLLGOAL2);
				break;
			case SECOND_PARKING_ZONE_RIGHT:
				abs_roll1_right_parkingzone();
				wait1Msec(g_input_array[SECOND_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_PARKING_ZONE_RIGHT);
				break;
			case SECOND_PARKING_ZONE_LEFT:
				abs_roll1_left_parkingzone();
				wait1Msec(g_input_array[SECOND_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
				abs_auto_end(SECOND_PARKING_ZONE_LEFT);
				break;
			}
		default: break;
		}
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
