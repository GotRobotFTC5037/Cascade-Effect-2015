/**
*
*  @file abs_auto_opponent_side.h
*
*  @brief a collection of math operations
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_AUTO_OPPONENT_SIDE_H
#define ABS_AUTO_OPPONENT_SIDE_H

void abs_auto_opponent_side()
{
	switch(g_center_goal_pos)
	{
	case 1:
		abs_drive(FORWARD, E_ANGLE, 225, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	break;
	case 2:
		abs_drive(FORWARD, E_ANGLE, 220, 90, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		abs_turn(CLOCKWISE, POINT, TURN, 70, 60, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 220, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;
	case 3:
		abs_drive(BACKWARD, E_ANGLE, 155, 70, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		wait1Msec(400);
		abs_turn(CLOCKWISE, POINT, TURN, 70, 70, FORWARD);
		abs_drive(FORWARD, E_ANGLE, 70, 70, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
		break;
	}
}

#endif /* !ABS_AUTO_OPPONENT_SIDE_H*/\
