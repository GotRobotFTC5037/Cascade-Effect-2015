/**
*
*  @file abs_IR_center_read.h
*
*  @brief  gyro read time handler
*
*  @param raw_gyro
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_IR_CENTER_READ_H
#define ABS_IR_CENTER_READ_H

task abs_IR_center_read()
{
	int beginning_val = abs_get_angle_sensor_val(RAW_BPU);

	while(abs(abs_get_angle_sensor_val(RAW_BPU)-beginning_val)<g_IR_center_goal_dist){}

	switch(g_bearing_ac1)
	{
	case 5: g_center_goal_pos = 3; break;
	case 6: g_center_goal_pos = 2; break;
	case 7: g_center_goal_pos = 1; break;
	}
}
#endif /*ABS_IR_CENTER_READ_H*/
