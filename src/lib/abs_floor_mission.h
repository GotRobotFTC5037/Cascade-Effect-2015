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
#include "abs_turn.h"
#include "abs_IR_floor_read.h"
#include "lib/abs_auto_center_pipe_score.h"
#include "lib/abs_auto_pipe_lower_mid.h"
#include "lib/abs_sonar_floor_read.h"

#include "lib/abs_floor_roll1.h"
#include "lib/abs_floor_roll2.h"
#include "lib/abs_floor_center.h"

void abs_floor_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case FIRST_STOP:
		wait1Msec(g_input_array[STARTING_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_STOP);
		break;
	case FIRST_ROLLGOAL1:
		abs_floor_roll1();
		wait1Msec(g_input_array[STARTING_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_ROLLGOAL1);
		break;
	case FIRST_CENTER_GOAL:
		abs_floor_center();
		wait1Msec(g_input_array[STARTING_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_CENTER_GOAL);
		break;
	case FIRST_ROLLGOAL2: break;
		abs_floor_roll2();
		wait1Msec(g_input_array[STARTING_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_ROLLGOAL2);
	default: break;
	}
}

#endif /* !ABS_FLOOR_MISSION_H */
