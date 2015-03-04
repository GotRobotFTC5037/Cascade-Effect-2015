/**
*
*  @file abs_sensors.h
*
*  @brief A header file that handles the sensors
*
*  @param None n/a
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SENSOR_H
#define ABS_SENSOR_H

#include "math_utils.h"
#include "abs_get_gyro_sensor_val.h"
#include "abs_get_angle_sensor_val.h"
#include "abs_gyro_read.h"

task abs_sensors()
{
	g_prev_time = nPgmTime;

	short gyro_read;

	for(gyro_read = 0; true;)
	{
	(gyro_read % 10 == 0) ? gyro_read=0 : gyro_read++;

		nxtDisplayBigTextLine(1,"%2d %3d",g_sonar,g_sonar2);
		nxtDisplayBigTextLine(3,"%2d %2d",g_sonar3,g_sonar4);
		nxtDisplayBigTextLine(5,"%3d",g_angle_sensor);

		//------------------------
		// angle sensor
		//------------------------
		g_angle_sensor = HTANGreadAccumulatedAngle(angle_sensor);

		//------------------------
		// sonar
		//------------------------

		g_sonar = USreadDist(LEGOUS);
		g_sonar2 = USreadDist(LEGOUS2);
		g_sonar3 = USreadDist(LEGOUS3);
		g_sonar4 = USreadDist(LEGOUS4);
		//-------------------------
		// HiTechnic IR Sensor
		//-------------------------
		g_bearing_ac1 = HTIRS2readACDir(HTIRS2);				// Read the IR bearing from the sensor
		g_curr_dir1 = (float) g_bearing_ac1;

		HTIRS2readAllACStrength(HTIRS2, g_acs1[0], g_acs1[1], g_acs1[2], g_acs1[3], g_acs1[4]);
		//-----------------------------------
		// code for the peaks of IR sensor

		if (g_bearing_ac1!=0)								// we have a valid IR signal
		{
			int maximum = -1;
			int peak = 0, offset=0;
			for (int i=0;i<5;i++)	// scan array to find the peak entry
			{	if (g_acs1[i]>maximum)
				{
					peak = i;
					maximum = g_acs1[i];
				}
			}
			offset=0;
			if ((peak < 4) && (peak>0) && (g_acs1[peak] != 0))  // we are not working with extreme value
			{
				if (g_acs1[peak-1]!=g_acs1[peak+1]) // if the values either side of the peak are identical then peak is peak
				{
					if (g_acs1[peak-1]>g_acs1[peak+1])	// otherwise decide which side has higher signal
					{
						offset = -25*(1-(float)(g_acs1[peak]-g_acs1[peak-1])/		// calculate the bias away from the peak
						max(g_acs1[peak], g_acs1[peak-1]));
					}
					else
					{
						offset = 25*(1-(float)(g_acs1[peak]-g_acs1[peak+1])/
						max(g_acs1[peak], g_acs1[peak+1]));
					}
				}
			}
			g_ir_bearing1 = (float)((peak-2)*50) + offset;		// direction is the total of the peak bias plus the adjacent bias
		}
		//-------------------------
		// HiTechnic Gyro
		//-------------------------
		if(gyro_read==0)
		{
			g_curr_time=nPgmTime;
			g_raw_gyro = abs_get_gyro_sensor_val(RAW);
			g_sacred_const_heading += (g_raw_gyro - (g_drift)) * (float)(g_curr_time-g_prev_time)/1000;
			g_rel_heading += (g_raw_gyro - (g_drift)) * (float)(g_curr_time-g_prev_time)/1000;

			g_const_heading += (g_raw_gyro - (g_drift) * (float)(g_curr_time-g_prev_time)/1000);

			g_prev_time = g_curr_time;

			g_recont_heading = g_const_heading % 360;
			if(g_recont_heading<0) g_recont_heading += 360;
		}
		wait1Msec(20);
	}
}
#endif
