#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S3,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S4,     angle_sensor,   sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     right_motor,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     left_motor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     brush,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     shoulder,      tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    impellar1,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    impellar2,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    goal_claw,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    shutter,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
*
*  @file auto.c
*
*  @brief The automatic program for the robot.
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

/*Includes*/

//-----------------------
// sensor/mux/joystick includes
//-----------------------

#include "joystickdriver.c"
#include "lib/xander/hitechnic-sensormux.h"
#include "lib/xander/lego-light.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"
#include "lib/xander/hitechnic-accelerometer.h"
#include "lib/xander/lego-ultrasound.h"

//-----------------------
// Custom include
//-----------------------

#include "lib/global_variables.h"
#include "lib/compile_flags.h"
#include "lib/abs_IR_floor_read.h"
#include "lib/abs_initialize.h"
#include "lib/abs_dlog.h"
#include "lib/abs_stay_on_ramp.h"
#include "lib/abs_drive.h"
#include "lib/abs_turn.h"
#include "lib/abs_ramp_mission.h"
#include "lib/abs_floor_mission.h"
#include "lib/abs_auto_center_pipe_score.h"
#include "lib/abs_auto_pipe_lower_mid.h"
#include "lib/abs_IR_floor_read.h"

#define DRIVE_TYPE TANK

//========================================
// Main program
//========================================
task main()
{
	Delete(LogFileName, LogIoResult);
	OpenWrite(LogFileHandle, LogIoResult, LogFileName, LogFileSize);

	abs_dlog(__FILE__ ,"Program start"," Start time:", nPgmTime);

	abs_initialize();

	disableDiagnosticsDisplay();

	//wait1Msec(STARTING_DELAY*1000);

	switch(g_input_array[STARTING_POINT])
	{
	case START_RAMP: abs_ramp_mission(); break;
	case START_FLOOR:
		abs_IR_floor_read();
		abs_floor_mission();
		break;
	default:
		PlayTone(200,20);
		break;
	}

	abs_dlog(__FILE__ ,"end auto", "End time:", nPgmTime);
	Close(LogFileHandle, LogIoResult);
}
