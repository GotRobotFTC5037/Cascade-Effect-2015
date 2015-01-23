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
	int beginning_val = abs_get_angle_sensor_val(RAW_TU);

	while(abs(abs_get_angle_sensor_val(RAW_TU)-beginning_val)<g_IR_center_goal_dist)
	{
		//HTIRS2readAllACStrength(HTIRS2, g_acs1[0], g_acs1[1], g_acs1[2], g_acs1[3], g_acs1[4]);

		//g_bearing_ac1 = HTIRS2readACDir(HTIRS2);				// Read the IR bearing from the sensor
		//g_curr_dir1 = (float) g_bearing_ac1;
	}

	switch(g_bearing_ac1)
	{
	case 5: g_center_goal_pos = 3; break;
	case 6: g_center_goal_pos = 2; break;
	case 7: g_center_goal_pos = 1; break;
	default: g_center_goal_pos = 0; break;
	}
	abs_dlog(__FILE__ ,"IR"," Pos", g_center_goal_pos);
}
#endif /*ABS_IR_CENTER_READ_H*/
