/**
 *
 *  @file abs_sonar_drive.h
 *
 *  @brief handles the speed control for the motors based on the sonar
 *
 *  @param speed tells the robot how fast to go
 *
 *  @param dir Tells the robot what direction to go
 *
 *  @return Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */
#ifndef ABS_SONAR_DRIVE_H
#define ABS_SONAR_DRIVE_H

#include "abs_move_utils.h"

void abs_sonar_drive(int speed,e_drive_direction dir, int wall_distance, int sonar_value)
{
	int error = wall_distance - sonar_value;

	(error > 0) ? error = (speed/3) : error = -(speed/3);

	if(sonar_value > wall_distance + 30) error = 0;

	if(dir == FORWARD)
	{
		motor[left_motor] = speed - (error*g_sonar_adjust);
		motor[right_motor] = speed + (error*g_sonar_adjust);
	}
	else
	{
		motor[left_motor] = -(abs(speed) + (error*g_sonar_adjust));
		motor[right_motor] = -(abs(speed) - (error*g_sonar_adjust));
	}
}
#endif /* !ABS_SONAR_DRIVE_H */
