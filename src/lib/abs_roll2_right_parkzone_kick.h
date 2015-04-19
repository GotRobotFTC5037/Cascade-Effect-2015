 /**
*
*  @file abs_roll2_right_parkzone_kick.h
*
*  @brief
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_ROLL2_RIGHT_PARKINGZONE_KICK_H
#define ABS_ROLL2_RIGHT_PARKINGZONE_KICK_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_roll2_right_parkzone.h"

void abs_roll2_right_parkzone_kick()
{
	abs_roll2_right_parkzone();

	switch(g_center_goal_pos)
	{
	case 1:
		abs_drive(FORWARD, E_ANGLE, 120, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 80, 60, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 100, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		break;
	case 2:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 8, 60, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 135, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		abs_turn(CLOCKWISE, POINT, TURN, 50, 60, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 100, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		break;
	case 3:
		abs_drive(FORWARD, E_ANGLE, 80, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 8, 60, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 150, 60, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
		break;
	default:
		for(int i = 0;i<5;i++)
		{
			PlayTone(50*i,20);
			wait1Msec(300);
		}
		break;
	}
}

#endif /* !ABS_ROLL2_RIGHT_PARKINGZONE_KICK_H */
