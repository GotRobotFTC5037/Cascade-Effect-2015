/**
*
*  @file abs_roll1_left_parkingzone.h
*
*  @brief part of mission going from ROLLGOAL1 to ROLLGOAL2
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_ROLL1_LEFT_PARKINGZONE_H
#define ABS_ROLL1_LEFT_PARKINGZONE_H

#include "abs_turn.h"
#include "abs_drive.h"
#include "abs_auto_end.h"

void abs_roll1_left_parkingzone()
{
	StopTask(abs_auto_pipe_score);
	StartTask(abs_auto_pipe_lower);

	servo[goal_claw] = g_goal_claw_down;

	abs_turn(CLOCKWISE, POINT, TURN, 26-g_roll_to_parking_turn, 45, FORWARD);
	abs_drive(FORWARD, E_ANGLE, 320, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_turn(CLOCKWISE, POINT, TURN, 30, 60, FORWARD);
	abs_drive(FORWARD, E_ANGLE, 190, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	abs_turn(CLOCKWISE, POINT, TURN, 100, 60, FORWARD);
	PlayTone(200, 20);
	servo[goal_claw] = g_goal_claw_up;
	abs_drive(BACKWARD, E_ANGLE, 30, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
}

#endif /* !ABS_ROLL1_LEFT_PARKINGZONE_H */
