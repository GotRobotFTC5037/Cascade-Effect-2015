/**
*
*  @file abs_gyro_read.h
*
*  @brief  gyro read time handler
*
*  @param raw_gyro
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/

#ifndef ABS_GYRO_READ_H
#define ABS_GYRO_READ_H

int const_gyro_array[5];
int rel_gyro_array[5];
int sacred_const_gyro_array[5];

task abs_gyro_read()
{
	memset(const_gyro_array,0,5);
	memset(rel_gyro_array,0,5);
	memset(sacred_const_gyro_array,0,5);

	while(true)
	{
		wait1Msec(100);

		//-------------------------
		// HiTechnic Gyro
		//-------------------------

		g_curr_time=nPgmTime;
		g_raw_gyro = abs_get_gyro_sensor_val(RAW);
		g_sacred_const_heading += (g_raw_gyro - (g_drift)) * (float)(g_curr_time-g_prev_time)/1000;
		g_rel_heading += (g_raw_gyro - (g_drift)) * (float)(g_curr_time-g_prev_time)/1000;

		g_const_heading += (g_raw_gyro - (g_drift) * (float)(g_curr_time-g_prev_time)/1000);

		g_prev_time = g_curr_time;

		g_recont_heading = g_const_heading % 360;
		if(g_recont_heading<0) g_recont_heading += 360;
	}
}
#endif /*ABS_GYRO_READ_H*/
