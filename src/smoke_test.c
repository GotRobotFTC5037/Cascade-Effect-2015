#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S3,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S4,     SENSOR_MUX2,    sensorI2CCustom)
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
#pragma config(Servo,  srvo_S1_C4_5,    MattServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    intake_shutter,       tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
*
*  @file smoke_test.c
*
*  @brief The automatic program for the robot.
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

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
#include "lib/xander/hitechnic-eopd.h"
#include "lib/xander/lego-ultrasound.h"

//-----------------------
// custom functions includes
//-----------------------
#include "lib/compile_flags.h"
#include "lib/global_variables.h"
#include "lib/math_utils.h"
#include "lib/abs_sensors.h"
#include "lib/abs_smoke_execute.h"
#include "lib/abs_smoke_test_view.h"

int test_value1 = 0;
int test_value2 = 0;
int test_num = 1;
int total_tests_num = 11;

//==================================
// main program
//==================================
task main()
{
	disableDiagnosticsDisplay();

	nMotorEncoder(lift1) = 0;
	nMotorEncoder(shoulder) = 0;

	abs_cscreen("        ","        ","        ");
	nxtDisplayBigTextLine(7, "        ");
	abs_smoke_test_view(test_num,test_value1,test_value2);
	while(true)
	{
		while(nNxtButtonPressed!=kEnterButton)
		{
			if(nNxtButtonPressed==kLeftButton&&test_num>1)
			{
				test_num--;
				abs_smoke_test_view(test_num,test_value1,test_value2);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			if(nNxtButtonPressed==kRightButton&&test_num<total_tests_num)
			{
				test_num++;
				abs_smoke_test_view(test_num,test_value1,test_value2);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
		}
		PlaySoundFile("! Click.rso");
		while(nNxtButtonPressed==kEnterButton){}
		abs_smoke_execute(test_num);
		abs_smoke_test_view(test_num,test_value1,test_value2);
	}
}
