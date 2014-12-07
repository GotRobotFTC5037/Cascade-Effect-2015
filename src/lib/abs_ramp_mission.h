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

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(STOP);
		break; //STOP
	case ROLLGOAL1:

		if(g_start_heading_forward==true)
		{
			StartTask(abs_IR_center_read);
			abs_drive(FORWARD, E_ANGLE, 460, 35, true, NON_SENSOR);//GYRO);
			abs_turn(CLOCKWISE, POINT, TURN, 180, 60);
			abs_drive(BACKWARD, E_ANGLE, 100, 35, true, NON_SENSOR);//GYRO);
			servo[goal_claw] = g_goal_claw_down;
			wait1Msec(500);
			if(g_center_goal_pos==0) g_input_array[SECOND_OBJECTIVE] = STOP;

			while(true){nxtDisplayBigTextLine(2,"%2d",g_center_goal_pos);}
		}
		else
		{
			abs_drive(BACKWARD, E_ANGLE, 510, 30, true, NON_SENSOR);//GYRO);
			servo[goal_claw] = g_goal_claw_down;
			wait1Msec(500);
		}
		abs_second_objective(ROLLGOAL1);
		break;
	case CENTER_GOAL:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(CENTER_GOAL);
		break;
	case ROLLGOAL2:

		if(g_start_heading_forward==true)
		{
		}
		else
		{
		}
		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(ROLLGOAL2);
		break;
	}
}

#endif /* !ABS_RAMP_MISSION_H */
