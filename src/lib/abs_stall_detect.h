/**
*
*  @file abs_stall_detect.h
*
*  @brief  Detects if the robot is stalling and tells the program it was called from
*
*  @param
*
*  @return
*
*  @copyright Copyright 2015, Got Robot! FTC Team 5037
*/
#ifndef ABS_STALL_DETECT_H
#define ABS_STALL_DETECT_H
//nPgmTime
bool abs_stall_detect(int angle_sensor_value)
{

  //return true;
	static int last_angle_sensor_value;
	static int last_time_value;
	const int angle_sensor_buffer_size = 15;
bool ret_val = false;

	if(g_reset_stall_detect == true)
	{
		last_angle_sensor_value = angle_sensor_value;
		last_time_value = nPgmTime;
		g_reset_stall_detect = false;
		ret_val = false;
	}
	else
	{

		//if its been less then a second
		if(nPgmTime<last_time_value + 1000)
		{
			ret_val = false;
		}
		else
		{
			if(abs(angle_sensor_value) < (abs(last_angle_sensor_value) + angle_sensor_buffer_size))
			{
				ret_val = true;
			}
			else
			{
				last_angle_sensor_value = angle_sensor_value;
				last_time_value = nPgmTime;
				ret_val = false;
			}
		}
	}
		return ret_val;
}

#endif /* !ABS_STALL_DETECT_H */
