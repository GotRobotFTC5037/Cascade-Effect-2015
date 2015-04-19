/**
*
*  @file abs_right_parkzone_kick.h
*
*  @brief part of mission going from floor right side to kickstand
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_RIGHT_PARKZONE_KICK_H
#define ABS_RIGHT_PARKZONE_KICK_H

#include "abs_drive.h"
#include "abs_turn.h"

void abs_right_parkzone_kick()
{
	switch (g_center_goal_pos)
	{
	case 1:
		wait1Msec(50);
		abs_turn(CLOCKWISE, POINT, TURN, 12, 30, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 170, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(CLOCKWISE, POINT, TURN, 82, 70, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 160, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;

	case 2:
		wait1Msec(50);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 7, 40, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 194, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(CLOCKWISE, POINT, TURN, 45, 50, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 100, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;

	case 3:
		wait1Msec(50);
		abs_drive(FORWARD, E_ANGLE, 40, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 170, 50, FORWARD);
		abs_drive(BACKWARD, E_ANGLE, 250, 50, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;

	default: break;
	}
}

#endif /* !ABS_RIGHT_PARKZONE_KICK_H */
