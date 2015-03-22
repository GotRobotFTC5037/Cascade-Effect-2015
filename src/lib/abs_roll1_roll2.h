/**
*
*  @file abs_roll1_roll2.h
*
*  @brief part of mission going from ROLLGOAL1 to ROLLGOAL2
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_ROLL1_ROLL2_H
#define ABS_ROLL1_ROLL2_H

#include "abs_turn.h"
#include "abs_drive.h"
#include "abs_auto_end.h"

void abs_roll1_roll2()
{
	abs_turn(CLOCKWISE, POINT, TURN, 155-g_roll_to_parking_turn, 45, FORWARD);
	servo(goal_claw) = g_goal_claw_up;
	abs_drive(FORWARD, E_ANGLE, 75, 30, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 112, 60, FORWARD);
	abs_drive(BACKWARD, E_ANGLE, 100, 16, true, GYRO, SLOW_DOWN, NO_STALL_ACTION);
	wait1Msec(200);
	servo(goal_claw) = g_goal_claw_down;
	wait1Msec(500);
}

#endif /* !ABS_ROLL1_ROLL2_H */
