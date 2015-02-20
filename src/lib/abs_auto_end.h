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

void abs_auto_end(e_scoring_options second_start_pos)
{
	if(g_input_array[END_POINT]==STOP)
	{
		if(g_input_array[STARTING_POINT] == START_FLOOR && g_input_array[FIRST_OBJECTIVE] == CENTER_GOAL && g_input_array[SECOND_OBJECTIVE] == KICK_STAND && g_center_goal_pos == 3)
		{
			abs_drive(BACKWARD, E_ANGLE, 120/*100*/, 60, true, GYRO, DONT_SLOW_DOWN);
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 50, FORWARD);
			abs_drive(BACKWARD, E_ANGLE, 180, 90, true, GYRO, DONT_SLOW_DOWN);
		}
	}
	else
	{
		switch(second_start_pos)
		{
		case PARKING_ZONE:
			switch (g_center_goal_pos)
			{
			case 1:
					wait1Msec(50);
					abs_drive(FORWARD, E_ANGLE, 185, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(CLOCKWISE, POINT, TURN, 82, 70, FORWARD);
					abs_drive(BACKWARD, E_ANGLE, 220, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

				case 2:
					abs_turn(COUNTERCLOCKWISE, POINT, TURN, 7, 30, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 194, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(CLOCKWISE, POINT, TURN, 40, 50, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 100, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

				case 3:
					wait1Msec(50);
					abs_drive(FORWARD, E_ANGLE, 40, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(COUNTERCLOCKWISE, POINT, TURN, 197, 50, FORWARD);
					abs_drive(BACKWARD, E_ANGLE, 250, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

			default:

				break;
			}

			break;
		case CENTER_GOAL:
			switch(g_input_array[END_POINT])
			{
			case PARKING_ZONE:

				break;								//LOW AREA
			}
			break;
		case STOP:
			break;
		case ROLLGOAL1:
			switch(g_input_array[END_POINT])
			{
			case PARKING_ZONE:
				StopTask(abs_auto_pipe_score);
				StartTask(abs_auto_pipe_lower);
				/*if(!force_done)*/
				abs_turn(CLOCKWISE, POINT, TURN, 29, 45, FORWARD);
				abs_drive(FORWARD, E_ANGLE, 425, 100, true, GYRO, DONT_SLOW_DOWN);

				abs_turn(CLOCKWISE, POINT, TURN, 147, 70, FORWARD);
				PlayTone(200, 20);
				servo[goal_claw] = g_goal_claw_up;
				abs_drive(BACKWARD, E_ANGLE, 65, 100, true, GYRO, DONT_SLOW_DOWN);

				switch (g_center_goal_pos)
				{
					case 1:
					wait1Msec(50);
					abs_drive(FORWARD, E_ANGLE, 185, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(CLOCKWISE, POINT, TURN, 82, 70, FORWARD);
					abs_drive(BACKWARD, E_ANGLE, 220, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

				case 2:
					abs_turn(COUNTERCLOCKWISE, POINT, TURN, 7, 30, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 194, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(CLOCKWISE, POINT, TURN, 40, 50, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 100, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

				case 3:
					wait1Msec(50);
					abs_drive(FORWARD, E_ANGLE, 25, 50, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(COUNTERCLOCKWISE, POINT, TURN, 97, 50, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 250, 50, true, GYRO, DONT_SLOW_DOWN);
					break;

				default:

					break;

				}
				break;
			default: break;
			}
			break;
		case ROLLGOAL2:
			switch(g_input_array[END_POINT])
			{
			case PARKING_ZONE:
				StopTask(abs_auto_pipe_score);
				StartTask(abs_auto_pipe_lower);
				abs_turn(CLOCKWISE, POINT, TURN, 21, 40, FORWARD);
				abs_drive(FORWARD, E_ANGLE, 470, 100, true, GYRO, DONT_SLOW_DOWN);

				abs_turn(CLOCKWISE, POINT, TURN, 160, 70, FORWARD);
				PlayTone(200, 20);
				servo[goal_claw] = g_goal_claw_up;
				abs_drive(BACKWARD, E_ANGLE, 100, 100, true, GYRO, DONT_SLOW_DOWN);
			break;								//LOW AREA
			}
			break;
		case KICK_STAND:
			switch(g_input_array[END_POINT])
			{
			case PARKING_ZONE: break;								//LOW AREA
			case ROLLGOAL1:

				switch(g_center_goal_pos)
				{
				case 1: break;
				case 2: break;
				case 3:
					abs_turn(COUNTERCLOCKWISE, SWING, TURN, 20, 80, FORWARD);
					abs_drive(FORWARD, E_ANGLE, 60, 40, true, GYRO, DONT_SLOW_DOWN);
					wait1Msec(400);
					abs_turn(CLOCKWISE, POINT, TURN, 56, 38, FORWARD);

					abs_drive(BACKWARD, E_ANGLE, 253, 80, true, GYRO, DONT_SLOW_DOWN);
					abs_turn(COUNTERCLOCKWISE, POINT, TURN, 16, 40, FORWARD);

					bool force_done = false;
					g_rel_heading = 0;
					motor[right_motor] = -40;
					while(g_sonar>30&&abs(g_rel_heading)<100)
					{
						if(nMotorEncoder(shoulder)<g_shoulder_center-400) motor[shoulder] = 40;
						else motor[shoulder] = 0;
					}
					if(abs(g_rel_heading)>=100)
					{
						force_done = true;
						PlayTone(400,20);
						wait1Msec(250);
						PlayTone(300,20);
					}
					motor[right_motor] = 0;
					motor[left_motor] = 0;
					motor[shoulder] = 0;

					wait1Msec(100);
					PlayTone(200,20);

					//abs_turn(CLOCKWISE, SWING, TURN, 24, 60);
					abs_turn(CLOCKWISE, SWING, TURN, 52, 60, BACKWARD);
					//abs_turn(CLOCKWISE, SWING, TURN, /*41*/30, 60, FORWARD);
					wait1Msec(400);

					abs_drive(BACKWARD, E_TIME, 800, 30, true, GYRO, DONT_SLOW_DOWN);

					motor[shoulder] = 40;
					while(nMotorEncoder(shoulder)<g_shoulder_mid-400) {  }
					motor[shoulder] = 0;

					PlayTone(200,20);

					servo[shutter] = g_shutter_open;

					wait1Msec(500);

					break;
				default:
					break;
				}
				break;  //KICK_STAND
			default:
				break;
			}
			break; //ROLLGOAL1
		default:
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
