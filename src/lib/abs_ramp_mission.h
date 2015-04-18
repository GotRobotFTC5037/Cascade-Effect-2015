/**
*
*  @file abs_ramp_mission.h
*
*  @brief all autonomous movements resulting from starting on the ramp
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2014, got robot? FTC Team 5037
*
*/

#ifndef ABS_RAMP_MISSION_H
#define ABS_RAMP_MISSION_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_ramp_roll1_roll3.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

#include "abs_ramp_roll1.h"
#include "abs_ramp_roll2.h"
#include "abs_ramp_center.h"

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case FIRST_STOP:
		wait1Msec(g_input_array[FIRST_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_STOP);
		break;
	case FIRST_ROLLGOAL1:
		abs_ramp_roll1();
		wait1Msec(g_input_array[FIRST_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_ROLLGOAL1);
		break;
	case FIRST_CENTER_GOAL:
		abs_ramp_center();
		wait1Msec(g_input_array[FIRST_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_CENTER_GOAL);
		break;
	case FIRST_ROLLGOAL2:
		abs_ramp_roll2();
		wait1Msec(g_input_array[FIRST_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_ROLLGOAL2);
		break;
	case FIRST_ROLL1_ROLL3:
		abs_ramp_roll1_roll3();
		wait1Msec(g_input_array[FIRST_OBJECTIVE_DELAY]*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(FIRST_ROLL1_ROLL3);
		break;
	default: break;
	}
}

#endif /* !ABS_RAMP_MISSION_H */
