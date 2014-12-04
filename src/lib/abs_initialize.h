/**
*
*  @file abs_initialize.h
*
*  @brief A header file that handles the initialization when we start the game
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_INITIALIZE_H
#define ABS_INITIALIZE_H

#include "abs_gyro_wrapper.h"
#include "abs_gyro_cal.h"
#include "abs_sensors.h"
#include "abs_dlog.h"
#include "abs_reset_angle_sensor.h"
#include "abs_selection_program.h"

void abs_initialize()
{
	disableDiagnosticsDisplay();
	memset(g_input_array,0,INPUT_ARRAY_SIZE);
	abs_selection_program();
	PlaySoundFile("! Click.rso");
	abs_cscreen("Gyros   ","Calbrtng","  lol   ");
	HTGYROstartCal(HTGYRO);
	g_drift = 0;//abs_gyro_cal(2);

	if(!HTACreadAllAxes(HTAC, g_x_axis, g_y_axis, g_z_axis))
	{
		g_error = ERR_ACCELERMOETER;
		g_error_type = ERROR_NONLETHAL;
	}
	if(g_gyro_noise>10)
	{
		g_error = ERR_GYRO_CAL;
		g_error = ERROR_LETHAL;
	}
	if(false)//HTSMUXreadPowerStatus(SENSOR_MUX))
	{
		g_error = ERR_SENSOR_MUX;
		g_error_type = ERROR_NONLETHAL;
	}
	if(HTSMUXreadPowerStatus(GYRO_MUX))
	{
		g_error = ERR_GYRO_MUX;
		g_error = ERROR_LETHAL;
	}

	//if(g_error != 0)
	//{
	//	switch(g_error)
	//	{
	//	case ERR_ACCELERMOETER: abs_cscreen("ERROR N ","Accel   ","        "); break;
	//	case ERR_GYRO_CAL: abs_cscreen("ERROR L ","Gryo1   ","cal fail"); break;
	//	case ERR_SENSOR_MUX: abs_cscreen("ERROR L ","SensrMux","pwr fail"); break;
	//	case ERR_GYRO_MUX: abs_cscreen("ERROR L ","Gyro1Mux","pwr fail"); break;
	//	}
	//	while(true)
	//	{
	//		g_gyro_true = true;
	//		PlayTone (250,25);
	//		wait1Msec(500);
	//		if(nNxtButtonPressed == kEnterButton && g_error_type == ERROR_NONLETHAL)break;
	//	}
	//}
	LogData=true;

	abs_cscreen("Program ","Ready   ","        "); //set the screen to show the program feedback before the auto starts
	nxtDisplayBigTextLine(5, "%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d ",g_input_array[1],g_input_array[2],g_input_array[3],g_input_array[4],g_input_array[5],g_input_array[6],g_input_array[7]);

	wait1Msec(200);
	StartTask(abs_sensors);

	abs_reset_angle_sensor_val(HARD_RESET);

	PlayTone(700, 10);

#if WAIT == 0
	waitForStart();

#else
	while(nNxtButtonPressed == kEnterButton){}
	if(nNxtButtonPressed != kEnterButton) wait1Msec(3000);
#endif

	abs_dlog(__FILE__ ,"auto start","timestamp",nPgmTime);

	eraseDisplay();
	g_start_time = nPgmTime;

	wait1Msec(STARTING_DELAY * DELAY_MULTIPLICATION_FACTOR);

	eraseDisplay();
}

#endif /* !ABS_INITIALIZE_H */
