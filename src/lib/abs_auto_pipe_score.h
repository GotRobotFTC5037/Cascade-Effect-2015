/**
*
*  @file abs_auto_pipe_acore.h
*
*  @brief
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_AUTO_PIPE_SCORE_H
#define ABS_AUTO_PIPE_SCORE_H

bool lift_done = false;
bool shoulder_done = false;

task abs_auto_pipe_score()
{
	while(true)
	{
		if(nMotorEncoder(lift1)<g_auto_pipe_score_hight)
		{
			motor[lift1] = g_lift_speed_up;
			motor[lift2] = g_lift_speed_up;
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
			lift_done = true;
		}
		if(nMotorEncoder(shoulder)<g_auto_pipe_score_angle-700&&nMotorEncoder(lift1)>g_auto_pipe_score_hight-800) motor[shoulder] = (((((g_auto_pipe_score_angle-700)-nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed);
		else if(nMotorEncoder(shoulder)>=g_auto_pipe_score_angle-700)
		{
			motor[shoulder] = 0;
			shoulder_done = true;
		}
		else motor[shoulder] = 0;

		/*if(lift_done&&shoulder_done)
		{
			wait1Msec(200);
			servo[shutter] = g_shutter_open;
			g_auto_lift_done = true;
		}*/
	}
}
#endif /*ABS_AUTO_PIPE_SCORE_H*/
