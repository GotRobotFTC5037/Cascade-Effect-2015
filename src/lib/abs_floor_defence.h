/**
*
*  @file abs_floor_defence.h
*
*  @brief
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/


#ifndef ABS_FLOOR_DEFENCE_H
#define ABS_FLOOR_DEFENCE_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

void abs_floor_defence()
{
	abs_turn(COUNTERCLOCKWISE, SWING, TURN, 50, 100, BACKWARD);
	abs_drive(BACKWARD, E_ANGLE, 280, 100, true, GYRO, DONT_SLOW_DOWN, DO_STALL_ACTION);
}

#endif /* !ABS_FLOOR_DEFENCE_H */
