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

bool lift_done2 = false;
bool shoulder_done2 = false;

task abs_auto_pipe_lower()
{
	while(!shoulder_done2||!lift_done2)
	{
		if(nMotorEncoder(lift1)>0)
		{
			if(nMotorEncoder(shoulder) < g_shoulder_lower_min)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
			}
			else
			{
				motor[lift1] = 0;
				motor[lift2] = 0;
			}
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
			shoulder_done2 = true;
		}

		if(nMotorEncoder(shoulder)>50) motor[shoulder] = -((((nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed);
		else
		{
			motor[shoulder] = 0;
			lift_done2 = true;
		}
	}
}
#endif /*ABS_AUTO_PIPE_LOWER_H*/
