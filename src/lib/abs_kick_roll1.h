/**
*
*  @file abs_kick_roll1.h
*
*  @brief part of mission going from rollgoal2 to right side of parkingzone
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_KICK_ROLL1_H
#define ABS_KICK_ROLL1_H

#include "abs_drive.h"
#include "abs_turn.h"

void abs_kick_roll1()
{
	switch(g_center_goal_pos)
	{
	case 1: break;
	case 2: break;
	case 3:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 20, 80, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 60, 40, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(400);
		abs_turn(CLOCKWISE, POINT, TURN, 56, 38, FORWARD);

		abs_drive(BACKWARD, E_ANGLE, 253, 80, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
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

		abs_turn(CLOCKWISE, SWING, TURN, 52, 60, BACKWARD);
		wait1Msec(400);

		abs_drive(BACKWARD, E_TIME, 800, 30, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

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
}

#endif /* !ABS_KICK_ROLL1_H */
