/**
*
*  @file abs_sonar_read.h
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_SONAR_READ_H
#define ABS_SONAR_READ_H

int sonar_non_detect4 = 0;
int sonar_non_detect5 = 0;
int sonar_detect4 = 0;
int sonar_detect5 = 0;
int buffer = 4;

task abs_sonar_read()
{
	while(true)
	{
		for(int i=0;i<buffer;i++)
		{
			g_sonar_reads4[buffer-i] = g_sonar_reads4[(buffer-1)-i];
			g_sonar_reads5[buffer-i] = g_sonar_reads5[(buffer-1)-i];
		}
		g_sonar_reads4[1]=g_sonar4;
		g_sonar_reads5[1]=g_sonar5;

		sonar_detect4 = 0;
		sonar_detect5 = 0;
		sonar_non_detect4 = 0;
		sonar_non_detect5 = 0;

		for(int i=0;i<buffer;i++)
		{
			if(g_sonar_reads4[i]>180) sonar_non_detect4++;
			else sonar_detect4+=g_sonar_reads4[i];
			if(g_sonar_reads5[i]>180) sonar_non_detect5++;
			else sonar_detect5+=g_sonar_reads5[i];
		}
		if(sonar_non_detect4>=1) g_sonar_average4 = 255;
		else g_sonar_average4 = sonar_detect4/(buffer-1);
		if(sonar_non_detect5>=1) g_sonar_average5 = 255;
		else g_sonar_average5 = sonar_detect5/(buffer-1);

		wait1Msec(70);
	}
}

#endif /* !ABS_SONAR_READ_H */
