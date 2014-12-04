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
#include "lib/abs_smoke_test_view.h"

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
				abs_smoke_test_view(test_num,-80,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kLeftButton){}
			}
			else if(nNxtButtonPressed==kRightButton)
			{
				motor[right_motor] = 80;
				motor[left_motor] = 80;
				abs_smoke_test_view(test_num,80,0);
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed==kRightButton){}
			}
			abs_smoke_test_view(test_num,0,0);
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
			break;
		case 6:
			break;
		case 8:
			break;
		case 9:
			break;
		default: abs_cscreen("ERROR   ","Test 2 B","added   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed==kEnterButton){}
}

#endif /* !ABS_SMOKE_EXECUTE_H */
