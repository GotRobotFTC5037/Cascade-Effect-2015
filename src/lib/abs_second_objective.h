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

void abs_second_objective(e_scoring_options second_start_pos)
{
	if(g_input_array[SECOND_OBJECTIVE]==STOP)
	{
		abs_auto_end(g_input_array[FIRST_OBJECTIVE]);
	}
	else
	{
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

				abs_drive(FORWARD, E_ANGLE, 4, 35, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
				abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 40, FORWARD);
				abs_drive(FORWARD, E_ANGLE, 82, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
				wait1Msec(300);
				abs_turn(CLOCKWISE, POINT, TURN, 90, 40, FORWARD);
				abs_drive(BACKWARD, E_ANGLE, 200, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
				StopTask(abs_auto_pipe_lower_mid);

				wait1Msec(200);
				abs_auto_end(KICK_STAND);
				break;

			default:
				break;
			}
			break;

		case ROLLGOAL1: //ROLLING GOAL 1
			switch(g_input_array[SECOND_OBJECTIVE])
			{
			case ROLLGOAL2:

				StartTask(abs_auto_pipe_lower_mid);
				abs_turn(CLOCKWISE, SWING, TURN, 40, 60, FORWARD);
				servo[goal_claw] = g_goal_claw_up;

				abs_drive(FORWARD, E_ANGLE, 45, 40, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
				abs_turn(COUNTERCLOCKWISE, POINT, TURN, 48+abs(g_roll1_sonar_turn), 50, FORWARD);

				abs_drive(BACKWARD, E_ANGLE, 90, 30, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

				g_rel_heading = 0;
				while(g_sonar>35&&abs(g_rel_heading)<100){ motor[left_motor] = 45; }
				motor[left_motor] = 0;
				g_roll1_sonar_turn = g_rel_heading;

				if(!(abs(g_rel_heading)<100))
				{
					PlayTone(1500, 30);
					wait1Msec(200);
					PlayTone(1000, 30);
					wait1Msec(200);
					PlayTone(500, 30);

					StopTask(abs_auto_pipe_score);
					StartTask(abs_auto_pipe_lower);

					while(true){}
				}

				abs_turn(CLOCKWISE, SWING, TURN, 25, 40, FORWARD);
				abs_drive(BACKWARD, E_ANGLE, 65, 30, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

				servo[goal_claw] = g_goal_claw_down;

				StopTask(abs_auto_pipe_lower_mid);
				StartTask(abs_auto_pipe_score_tall);

				while(nNxtButtonPressed!=kEnterButton){}

				servo[shutter] = g_shutter_open;

				while(nNxtButtonPressed==kEnterButton){}
				while(nNxtButtonPressed!=kEnterButton){}

				StopTask(abs_auto_pipe_score_tall);
				StopTask(abs_auto_pipe_lower_mid);
				StartTask(abs_auto_pipe_lower);

				while(true){}
				break;
			case PARKING_ZONE:

				StopTask(abs_auto_pipe_score);
				StartTask(abs_auto_pipe_lower);

				servo[goal_claw] = g_goal_claw_down;

				abs_turn(CLOCKWISE, POINT, TURN, 27, 60, FORWARD);
				abs_drive(FORWARD, E_ANGLE, 440, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

				abs_turn(CLOCKWISE, POINT, TURN, 134, 70, FORWARD);
				PlayTone(200, 20);
				servo[goal_claw] = g_goal_claw_up;
				abs_drive(BACKWARD, E_ANGLE, 65, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

				abs_auto_end(PARKING_ZONE);
				break;
			}

		case ROLLGOAL2: //ROLLING GOAL 2

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(ROLLGOAL2);
			break;

		case KICK_STAND:

			wait1Msec(SECOND_OBJECTIVE_DELAY*DELAY_MULTIPLICATION_FACTOR);
			abs_auto_end(KICK_STAND);
			break;

		default:
			break;
		}
	}
}

#endif /* !ABS_SECOND_OBJECTIVE_H */
