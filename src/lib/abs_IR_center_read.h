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
	int IR_center_goal_dist = 0;

	if(g_selected_IR == IR_CLASSIC)
	{
		while(abs(abs_get_angle_sensor_val(RAW_TU)-beginning_val)<g_IR_center_goal_dist_classic){}
		switch(g_bearing_ac1)
		{
		case 5: g_center_goal_pos = 3; break;
		case 6: g_center_goal_pos = 2; break;
		case 7: g_center_goal_pos = 1; break;
		default: g_center_goal_pos = 0; break;
		}
	}
	else //IR_180
	{
		while(abs(abs_get_angle_sensor_val(RAW_TU)-beginning_val)<g_IR_center_goal_dist_classic){}
		switch(g_bearing_ac1)
		{
		case 5:
		case 6: g_center_goal_pos = 3; break;
		case 7: g_center_goal_pos = 1; break;
		default: g_center_goal_pos = 0; break;
		}
		abs_dlog(__FILE__ , "13inch read", "Angle", g_angle_sensor_val, "IR", g_bearing_ac1, "center pos", g_center_goal_pos);

		if(g_center_goal_pos == 1)
		{
			while(abs(abs_get_angle_sensor_val(RAW_TU)-beginning_val)<g_sonar_center_goal_dist_180)
			{
				if(g_sonar2 < 240)
				{
					g_center_goal_pos = 1;
					break;
				}
				else g_center_goal_pos = 2;
			}
		}
		abs_dlog(__FILE__ , "bottom ramp", "Angle", abs_get_angle_sensor_val(RAW_TU), "IR ", g_bearing_ac1, "center pos", g_center_goal_pos);
	}
	//abs_dlog(__FILE__ ,"IR"," Pos", g_center_goal_pos);
}
#endif /*ABS_IR_CENTER_READ_H*/
