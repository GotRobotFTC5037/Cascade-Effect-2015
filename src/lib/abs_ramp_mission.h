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
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"
#include "abs_ramp_mission_1st_obj.h"

void abs_ramp_mission()
{

	e_scoring_options last_successful_objective;

        // insert configurable wait here

	last_successful_objective = abs_ramp_mission_1st_obj(g_input_array[FIRST_OBJECTIVE]);

	/** insert wait here */
        wait1Msec(SECOND_OBJECTIVE_DELAY * DELAY_MULTIPLICATION_FACTOR);

	last_successful_objective = abs_second_objective(last_successful_objective,
					g_input_array[SECOND_OBJECTIVE]);

        // insert configurable wait here

        /** perform final objective */
        abs_auto_end(last_successful_objective, g_input_array[END_POINT]);

}

#endif /* !ABS_RAMP_MISSION_H */
