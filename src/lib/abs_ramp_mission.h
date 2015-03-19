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
		abs_drive(BACKWARD, E_ANGLE, 250, 20, true, GYRO, SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(250);
		servo[shutter] = g_shutter_closed;
		StartTask(abs_auto_pipe_score);
		g_gyro_inherit = true;
		abs_drive(BACKWARD, E_ANGLE, 190, 30, true, WALL_SONAR, DONT_SLOW_DOWN, DO_STALL_ACTION);

		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 3, 35, BACKWARD);
		servo[shutter] = g_shutter_closed;
		wait1Msec(700);

		servo[shutter] = 155;
		servo[goal_claw] = g_goal_claw_down;
		g_auto_lift_done = true;
		StopTask(abs_auto_pipe_score);

		wait1Msec(800);

		StartTask(abs_auto_pipe_lower);

		wait1Msec(500);
		abs_second_objective(ROLLGOAL1);
		break;
	case CENTER_GOAL:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(CENTER_GOAL);
		break;
	case ROLLGOAL2:

		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);

		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 50, 90, FORWARD);
		servo[goal_claw] = g_goal_claw_up;
		abs_drive(BACKWARD, E_ANGLE, 20, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(500);

		abs_drive(FORWARD, E_ANGLE, 26, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

		g_auto_pipe_score_hight = g_tall_lift;
		g_auto_pipe_score_angle = g_shoulder_tall+700;
		StartTask(abs_auto_pipe_score);

		abs_turn(CLOCKWISE, SWING, TURN, 53, 90, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 60, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);


		abs_drive(BACKWARD, E_ANGLE, 30, 25, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);


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
