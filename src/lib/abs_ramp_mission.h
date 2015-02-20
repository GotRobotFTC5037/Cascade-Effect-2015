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

//#include "global_variables.h"

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP:
		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(STOP);
		break; //STOP
	case ROLLGOAL1:
		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 310, 30, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 20, 80, BACKWARD);
		abs_drive(BACKWARD, E_ANGLE, 110, 60, true, GYRO, DONT_SLOW_DOWN);

		StartTask(abs_auto_pipe_score);

		g_rel_heading = 0;
		while(g_sonar>45&&abs(g_rel_heading)<100){ motor[right_motor] = -45; }
		motor[right_motor] = 0;
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

		abs_turn(CLOCKWISE, SWING, TURN, 52, 60, BACKWARD);
		abs_drive(BACKWARD, E_ANGLE, 8, 40, true, GYRO, DONT_SLOW_DOWN);

		wait1Msec(2000);
		servo[shutter] = 155;
		servo[goal_claw] = g_goal_claw_down;
		g_auto_lift_done = true;
		StopTask(abs_auto_pipe_score);

		wait1Msec(500);
		abs_second_objective(ROLLGOAL1);
		break;
	case CENTER_GOAL:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(CENTER_GOAL);
		break;
	case ROLLGOAL2:

		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN);
		abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN);

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);

		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 50, 90, FORWARD);
		servo[goal_claw] = g_goal_claw_up;
		abs_drive(BACKWARD, E_ANGLE, 20, 25, true, GYRO, DONT_SLOW_DOWN);
		wait1Msec(500);

		abs_drive(FORWARD, E_ANGLE, 26, 25, true, GYRO, DONT_SLOW_DOWN);

		g_auto_pipe_score_hight = g_tall_lift;
		g_auto_pipe_score_angle = g_shoulder_tall+700;
		StartTask(abs_auto_pipe_score);

		abs_turn(CLOCKWISE, SWING, TURN, 53, 90, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 60, 25, true, GYRO, DONT_SLOW_DOWN);


		abs_drive(BACKWARD, E_ANGLE, 30, 25, true, GYRO, DONT_SLOW_DOWN);


		while(!g_auto_lift_done){}
		wait1Msec(1000);

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);

		abs_second_objective(ROLLGOAL2);
		break;
	case KICK_STAND:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(KICK_STAND);
		break;
	}
}

#endif /* !ABS_RAMP_MISSION_H */
