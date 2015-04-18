/**
*
*  @file abs_right_parkzone_roll2.h
*
*  @brief part of mission going from floor right side to kickstand
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_RIGHT_PARKZONE_ROLL2_H
#define ABS_RIGHT_PARKZONE_ROLL2_H

#include "abs_drive.h"
#include "abs_turn.h"

void abs_right_parkzone_roll2()
{
	abs_drive(FORWARD, E_ANGLE, 43, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 175, 100, FORWARD);
	abs_drive(BACKWARD, E_ANGLE, 420, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
}

#endif /* !ABS_RIGHT_PARKZONE_ROLL2_H */
