/**
*
*  @file abs_roll3_right_parkingzone.h
*
*  @brief part of mission going from ROLLGOAL1 to ROLLGOAL2
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_ROLL3_RIGHT_PARKINGZONE_H
#define ABS_ROLL3_RIGHT_PARKINGZONE_H

#include "abs_turn.h"
#include "abs_drive.h"
#include "abs_auto_end.h"

void abs_roll3_right_parkingzone()
{
	StopTask(abs_auto_pipe_score);
	StartTask(abs_auto_pipe_lower);

	abs_drive(FORWARD, E_ANGLE, 40, 20, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	abs_turn(CLOCKWISE, SWING, TURN, 59, 60, FORWARD);

	abs_drive(FORWARD, E_ANGLE, 95, 30, false, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_drive(FORWARD, E_ANGLE, 95, 65, false, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_drive(FORWARD, E_ANGLE, 300, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);

	abs_drive(BACKWARD, E_ANGLE, 40, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 180, 60, FORWARD);
	servo(goal_claw) = g_goal_claw_up;
	abs_drive(BACKWARD, E_ANGLE, 45, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
}

#endif /* !ABS_ROLL3_RIGHT_PARKINGZONE_H */
