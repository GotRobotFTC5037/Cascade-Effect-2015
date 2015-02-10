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

#ifndef ABS_RAMP_MISSION_1ST_OBJ_H
#define ABS_RAMP_MISSION_1ST_OBJ_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

//e_scoring_options abs_ramp_mission_1st_obj(e_scoring_options objective)
e_scoring_options abs_ramp_mission_1st_obj(user_input * usr_input)
{
	/** assume this will be successful */
	//e_scoring_options previously_completed_obj = objective;
	e_scoring_options previously_completed_obj = usr_input->first_obj;

	switch(usr_input->first_obj)
	{
	case STOP:
		break; //STOP

	case ROLLGOAL1:
		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN);
		StartTask(abs_auto_pipe_score);
		abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN);
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		while(!g_auto_lift_done){}
		wait1Msec(1000);
		break;

	case CENTER_GOAL:
		break;

	case ROLLGOAL2:
		break;

	case KICK_STAND:
		break;
	}

	return previously_completed_obj;
}

#endif /* !ABS_RAMP_MISSION_1ST_OBJ_H */
