/**
*
*  @file abs_auto_pipe_lower.h
*
*  @brief
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_AUTO_PIPE_LOWER_H
#define ABS_AUTO_PIPE_LOWER_H

task abs_auto_pipe_lower()
{
	while(nMotorEncoder(shoulder)>50) { motor[shoulder] = -((((nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed); }
	motor[shoulder] = 0;
	while(nMotorEncoder(lift1)>0)
	{
		motor[lift1] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
		motor[lift2] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
	}
	motor[lift1] = 0;
	motor[lift2] = 0;
}
#endif /*ABS_AUTO_PIPE_LOWER_H*/
