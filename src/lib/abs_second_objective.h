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

e_scoring_options abs_second_objective(e_scoring_options previously_completed_obj, e_scoring_options current_obj)
{
	/** assume that the last successfully completed objective is the one that has already completed */
	e_scoring_options last_successful_obj = previously_completed_obj;

	if(current_obj == STOP)
	{
		last_successful_obj = previously_completed_obj;
	}
	else
	{
		switch(previously_completed_obj)
		{
		case CENTER_GOAL:
			switch(current_obj)
			{
			case ROLLGOAL1:
				switch(g_center_goal_pos)
				{
				case 1: break;
				case 2: break;
				case 3: break;
				default: break;
				}
				last_successful_obj = current_obj;
				break;
			case ROLLGOAL2:
				switch(g_center_goal_pos)
				{
				case 1: break;
				case 2: break;
				case 3: break;
				default: break;
				}
				last_successful_obj = current_obj;
				break;
			case KICK_STAND:

				StartTask(abs_auto_pipe_lower_mid);

				abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO, DONT_SLOW_DOWN);
				abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 40);
				abs_drive(FORWARD, E_ANGLE, 82, 60, true, GYRO, DONT_SLOW_DOWN);
				wait1Msec(300);
				abs_turn(CLOCKWISE, POINT, TURN, 90, 40);
				abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN);
				StopTask(abs_auto_pipe_lower_mid);

				wait1Msec(200);
				last_successful_obj = current_obj;
				break;

			default:
				break;
			}
			break;

		case ROLLGOAL1: //ROLLING GOAL 1
			switch(current_obj)
			{
			case PARKING_ZONE:
				StopTask(abs_auto_pipe_score);
				StartTask(abs_auto_pipe_lower);
				/*if(!force_done)*/
				abs_turn(CLOCKWISE, POINT, TURN, 29, 40);
				abs_drive(FORWARD, E_ANGLE, 425, 100, true, GYRO, DONT_SLOW_DOWN);

				abs_turn(CLOCKWISE, POINT, TURN, 147, 70);
				PlayTone(200, 20);
				servo[goal_claw] = g_goal_claw_up;
				abs_drive(BACKWARD, E_ANGLE, 65, 100, true, GYRO, DONT_SLOW_DOWN);

				last_successful_obj = current_obj;
				break;
			default:
				last_successful_obj = previously_completed_obj;
				break;
			}

		case ROLLGOAL2: //ROLLING GOAL 2

			last_successful_obj = previously_completed_obj;
			break;

		case KICK_STAND:

			last_successful_obj = previously_completed_obj;
			break;

		default:
			break;
		}
	}

	return last_successful_obj;
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
