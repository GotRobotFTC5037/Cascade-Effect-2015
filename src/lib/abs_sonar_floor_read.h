/**
*
*  @file abs_sonar_floor_read.h
*
*  @brief  detects center goal position from the parking zone starting area
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_SONAR_FLOOR_READ_H
#define ABS_SONAR_FLOOR_READ_H

#define pos1_pos2 5
#define pos3 7

void abs_sonar_floor_read()
{
		if(g_sonar<85) g_center_goal_pos  = 3;
		else if(g_sonar < 110) g_center_goal_pos  = 1;
		else g_center_goal_pos  = 2;

		nxtDisplayBigTextLine(3,"%2d %2d",IR_average, sonar_average);

		//else if(g_bearing_ac1 == 8 || g_bearing_ac1 == 9) g_center_goal_pos  = 2;
		//else if(g_bearing_ac1 <= 7) g_center_goal_pos  = 3;
		//else g_center_goal_pos  = 0;
		wait1Msec(10);
}
#endif /*ABS_SONAR_FLOOR_READ_H*/
