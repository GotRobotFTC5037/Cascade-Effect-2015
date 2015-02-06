/**
*
*  @file abs_IR_floor_read.h
*
*  @brief  detects center goal position from the parking zone starting area
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_IR_FLOOR_READ_H
#define ABS_IR_FLOOR_READ_H

int IR_tests[5];
int sonar_tests[5];
int sonar_average = 0;
int IR_average = 0;

void abs_IR_floor_read()
{
		memset(IR_tests,0,5);
		memset(sonar_tests,0,5);

		for(int i = 0;i<5;i++)
		{
			IR_tests[i] = g_bearing_ac1;
			sonar_tests[i] = g_sonar;
			IR_average += IR_tests[i];
			sonar_average += sonar_tests[i];
			wait1Msec(200);
			//PlayTone(200,10);
		}
		IR_average = IR_average/5;
		sonar_average = IR_average/5;

		if(sonar_average<140) g_center_goal_pos  = 1;
		else if(IR_average >= 4) g_center_goal_pos  = 2;
		else if(IR_average <= 3) g_center_goal_pos  = 3;
		else g_center_goal_pos  = 0;

		nxtDisplayBigTextLine(3,"%2d %2d",IR_average, sonar_average);

		//else if(g_bearing_ac1 == 8 || g_bearing_ac1 == 9) g_center_goal_pos  = 2;
		//else if(g_bearing_ac1 <= 7) g_center_goal_pos  = 3;
		//else g_center_goal_pos  = 0;
		wait1Msec(10);
}
#endif /*ABS_IR_FLOOR_READ_H*/
