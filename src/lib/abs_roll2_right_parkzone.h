/**
*
*  @file abs_roll2_right_parkzone.h
*
*  @brief part of mission going from rollgoal2 to right side of parkingzone
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_ROLL2_RIGHT_PARKINGZONE_H
#define ABS_ROLL2_RIGHT_PARKINGZONE_H

#include "abs_drive.h"
#include "abs_turn.h"

void abs_roll2_right_parkzone()
{
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 12, 60, FORWARD);
	abs_drive(FORWARD, E_ANGLE, 590, 100, true, GYRO, DONT_SLOW_DOWN, NO_STALL_ACTION);
	abs_turn(CLOCKWISE, POINT, TURN, 150, 60, FORWARD);
	servo(goal_claw) = g_goal_claw_up;
	abs_drive(BACKWARD, E_ANGLE, 60, 100, true, GYRO, DONT_SLOW_DOWN, NO_STALL_ACTION);
}

#endif /* !ABS_ROLL2_RIGHT_PARKINGZONE_H */
