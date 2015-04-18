/**
*
*  @file abs_auto_end.h
*
*  @brief all autonomous movements to end the program
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_AUTO_END_H
#define ABS_AUTO_END_H

#include "abs_drive.h"
#include "abs_auto_pipe_score.h"
#include "abs_auto_pipe_lower.h"

#include "abs_right_parkzone_kick.h"
#include "abs_roll2_right_parkzone.h"
#include "abs_roll2_right_parkzone_kick.h"
#include "abs_kick_roll1.h"
#include "abs_right_parkzone_roll2.h"

void abs_auto_end(e_second_objectives end_start_pos)
{
	if(g_input_array[END_POINT]==END_STOP)
	{
		if(false)//g_input_array[STARTING_POINT] == START_FLOOR && g_input_array[FIRST_OBJECTIVE] == CENTER_GOAL && g_input_array[SECOND_OBJECTIVE] == KICK_STAND && g_center_goal_pos == 3)
		{
			abs_drive(BACKWARD, E_ANGLE, 120/*100*/, 60, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 50, FORWARD);
			abs_drive(BACKWARD, E_ANGLE, 180, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		}
	}
	else
	{
		switch(end_start_pos)
		{
		case SECOND_PARKING_ZONE_RIGHT:
			switch(g_input_array[END_POINT])
			{
			case END_KICK_STAND:
				abs_right_parkzone_kick();
				break;
			case END_ROLLGOAL2:
				abs_right_parkzone_roll2();
				break;
			default:
				for(int i = 0;i<5;i++)
				{
					PlayTone(i*50,20);
					wait1Msec(300);
				}
				break;
			}
			break;
		case SECOND_ROLLGOAL2:
			switch(g_input_array[END_POINT])
			{
			case END_PARKING_ZONE_RIGHT:
				abs_roll2_right_parkzone();
				break;
			case END_PARKING_ZONE_RIGHT_KICK:
				abs_roll2_right_parkzone_kick();
				break;
			}
			break;
		case SECOND_KICK_STAND:
			switch(g_input_array[END_POINT])
			{
			case END_ROLLGOAL1:
				abs_kick_roll1();
				break;
			default: break;
			}
			break;
		}
	}

	while(nMotorEncoder(shoulder)>50)
	{
		motor[shoulder] = -((((nMotorEncoder(shoulder))*100)/g_shoulder_max)+10);
		if(nMotorEncoder(lift1) > g_min_lift)
		{
			motor[lift1] = -((((nMotorEncoder(lift1)-g_min_lift)*100)/g_max_lift)+g_lift_min_speed);
			motor[lift2] = -((((nMotorEncoder(lift1)-g_min_lift)*100)/g_max_lift)+g_lift_min_speed);
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
		}
	}

	motor[shoulder] = 0;

	while(nMotorEncoder(lift1) > 0)
	{
		motor[lift1] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
		motor[lift2] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
	}
	motor[lift1] = 0;
	motor[lift2] = 0;
}

#endif /* !ABS_AUTO_END_H */
