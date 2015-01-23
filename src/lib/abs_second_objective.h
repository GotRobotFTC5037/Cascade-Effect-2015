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
		case ROLLGOAL1:
			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			switch(g_center_goal_pos)
			{
			case 1: break;
			case 2: break;
			case 3: break;
			default: break;
			}
			abs_auto_end(ROLLGOAL1);
			break;
		case ROLLGOAL2:
			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			switch(g_center_goal_pos)
			{
			case 1: break;
			case 2: break;
			case 3: break;
			default: break;
			}
			abs_auto_end(ROLLGOAL2);
			break;
		case KICK_STAND:

			StartTask(abs_auto_pipe_lower_mid);

			abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 40);
			abs_drive(FORWARD, E_ANGLE, 82, 60, true, GYRO);
			wait1Msec(300);
			abs_turn(CLOCKWISE, POINT, TURN, 90, 40);
			abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO);
			StopTask(abs_auto_pipe_lower_mid);

			wait1Msec(200);
			abs_auto_end(KICK_STAND);
			break;
		}
	case ROLLGOAL1: //ROLLING GOAL 1

		wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_auto_end(ROLLGOAL1);
		break;
	case ROLLGOAL2: //ROLLING GOAL 2

		wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_auto_end(ROLLGOAL2);
		break;

	case KICK_STAND:

		wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_auto_end(KICK_STAND);
		break;
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
