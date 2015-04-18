/**
*
*  @file abs_auto_center_pipe_acore.h
*
*  @brief
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_AUTO_CENTER_PIPE_SCORE_H
#define ABS_AUTO_CENTER_PIPE_SCORE_H

bool lift_done3 = false;
bool shoulder_done3 = false;

task abs_auto_center_pipe_score()
{
	while(true)
	{
		if(nMotorEncoder(lift1)<(g_tall_lift+2000))
		{
			motor[lift1] = g_lift_speed_up;
			motor[lift2] = g_lift_speed_up;
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
			lift_done3 = true;
		}
		if(nMotorEncoder(shoulder)<(g_shoulder_center)&&nMotorEncoder(lift1)>(g_mid_lift+1000)) motor[shoulder] = (((((g_shoulder_mid-700)-nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed);
		else
		{
			motor[shoulder] = 0;
			if(nMotorEncoder(shoulder)>=g_shoulder_center)shoulder_done3 = true;
		}

		if(lift_done3&&shoulder_done3)
		{
			servo[shutter] = g_shutter_open;
			wait1Msec(400);
			g_auto_lift_done = true;
			return;
		}
	}
}
#endif /*ABS_AUTO_CENTER_PIPE_SCORE_H*/
