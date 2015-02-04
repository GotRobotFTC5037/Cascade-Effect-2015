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

void abs_floor_mission()
{
	e_scoring_options last_successful_objective;

	/** scan IR beacons to determine center goal position */
	int center_goal_pos = abs_IR_floor_read();
	
	// insert configurable wait here

	/** perform first objective */
	abs_floor_mission_1st_obj(g_input_array[FIRST_OBJECTIVE], center_goal_pos);

	wait1Msec(SECOND_OBJECTIVE_DELAY * DELAY_MULTIPLICATION_FACTOR);

	/** perform second objective */
	last_successful_objective = abs_second_objective(g_input_array[FIRST_OBJECTIVE],
					g_input_array[SECOND_OBJECTIVE], center_goal_pos);

	// insert configurable wait here

	/** perform final objective */
	abs_auto_end(last_successful_objective, g_input_array[END_POINT], center_goal_pos);

}

#endif /* !ABS_FLOOR_MISSION_H */
