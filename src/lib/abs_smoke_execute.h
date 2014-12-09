/**
*
*  @file abs_smoke_execute.h
*
*  @brief executes commands sent in smoke test
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SMOKE_EXECUTE_H
#define ABS_SMOKE_EXECUTE_H

#include "abs_get_angle_sensor_val.h"
#include "abs_smoke_test_view.h"
#include "abs_reset_angle_sensor.h"

void abs_smoke_execute(int test_num)
{
	while(nNxtButtonPressed!=kEnterButton)
	{
		switch(test_num)
		{
		case 1:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[lift1] = g_lift_speed_down;
				motor[lift2] = g_lift_speed_down;
				abs_smoke_test_view(test_num,g_lift_speed_down,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[lift1] = g_lift_speed_up;
				motor[lift2] = g_lift_speed_up;
				abs_smoke_test_view(test_num,g_lift_speed_up,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			abs_smoke_test_view(test_num,0,0);
			motor[lift1] = 0;
			motor[lift2] = 0;
			break;
		case 2:
			if(nNxtButtonPressed==kLeftButton)
			{
				servo[goal_claw] = g_goal_claw_up;
				abs_smoke_test_view(test_num,g_goal_claw_up,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				servo[goal_claw] = g_goal_claw_down;
				abs_smoke_test_view(test_num,g_goal_claw_down,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			break;
		case 3:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[right_motor] = -80;
				motor[left_motor] = -80;
				abs_smoke_test_view(test_num,-80,abs_get_angle_sensor_val(RELATIVE_TU));
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[right_motor] = 80;
				motor[left_motor] = 80;
				abs_smoke_test_view(test_num,80,abs_get_angle_sensor_val(RELATIVE_TU));
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			abs_smoke_test_view(test_num,0,abs_get_angle_sensor_val(RELATIVE_TU));
			motor[right_motor] = 0;
			motor[left_motor] = 0;
			break;
		case 4:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[brush] = 100;
				abs_smoke_test_view(test_num,100,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[brush] = -100;
				abs_smoke_test_view(test_num,-100,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			abs_smoke_test_view(test_num,0,0);
			motor[brush] = 0;
			break;
		case 5:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[right_motor] = -40;
				motor[left_motor] = 40;
				abs_smoke_test_view(test_num,60,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[right_motor] = 40;
				motor[left_motor] = -40;
				abs_smoke_test_view(test_num,-40,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			abs_smoke_test_view(test_num,0,0);
			motor[right_motor] = 0;
			motor[left_motor] = 0;
			break;
		case 6:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[shoulder] = 40;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){ abs_smoke_test_view(test_num,40,nMotorEncoder(shoulder)); }
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[shoulder] = -40;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){ abs_smoke_test_view(test_num,-40,nMotorEncoder(shoulder)); }
			}
			abs_smoke_test_view(test_num,0,nMotorEncoder(shoulder));
			motor[shoulder] = 0;
			break;
		case 7:
			if(nNxtButtonPressed==kLeftButton)
			{
				servo[impellar1] = 255;
				servo[impellar2] = 0;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){ abs_smoke_test_view(test_num,255,0); }
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				servo[impellar1] = 0;
				servo[impellar2] = 255;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){ abs_smoke_test_view(test_num,0,255); }
			}
			abs_smoke_test_view(test_num,127,127);
			servo[impellar1] = 127;
			servo[impellar2] = 127;
			break;
		case 8:
		if(nNxtButtonPressed==kLeftButton)
			{
				servo[shutter] = g_shutter_closed;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){ abs_smoke_test_view(test_num,g_shutter_closed,0); }
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				servo[shutter] = g_shutter_open;
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){ abs_smoke_test_view(test_num,g_shutter_open,0); }
			}
			break;
		case 9:
			break;
		default: abs_cscreen("ERROR   ","Test 2 B","added   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed==kEnterButton){}
	nMotorEncoder(shoulder) = 0;
}

#endif /* !ABS_SMOKE_EXECUTE_H */
