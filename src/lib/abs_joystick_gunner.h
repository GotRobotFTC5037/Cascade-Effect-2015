/**
*
*  @file abs_joystick_gunner.h
*
*  @brief The header file that handles the joystick motor control
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_JOYSTICK_GUNNER_H
#define ABS_JOYSTICK_GUNNER_H

task abs_joystick_gunner()
{
	while(true)
	{
		//-----------------------------
		// flag motor control
		//-----------------------------
		//g_misc = joystick.joy2_TopHat;
		//switch(joystick.joy2_TopHat)
		//{
		//case -1:
		//	motor[jolly_roger]= 0;
		//	break;
		//case 0:
		//	motor[jolly_roger] = g_flag_speed_down;
		//	break;
		//case 2:
		//	motor[jolly_roger] = g_flag_speed_right;
		//	break;
		//case 6:
		//	motor[jolly_roger] = g_flag_speed_left;
		//	break;
		//case 4:
		//	motor[jolly_roger] = g_flag_speed_up;
		//	break;
		//}

		//-----------------------------
		// ball lift
		//-----------------------------

		if(joy1Btn(6))
		{
			motor[lift1] = g_lift_speed_up;
			motor[lift2] = g_lift_speed_up;
		}
		else if(joy1Btn(8))
		{
			motor[lift1] = g_lift_speed_down;
			motor[lift2] = g_lift_speed_down;
		}
		else if(joystick.joy2_y2>10)
		{
			motor[lift1] = g_lift_speed_up;
			motor[lift2] = g_lift_speed_up;
		}
		else if(joystick.joy2_y2<-10)
		{
			motor[lift1] = g_lift_speed_down;
			motor[lift2] = g_lift_speed_down;
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
		}

		//-----------------------------
		// robot kill switch
		//-----------------------------
		if((joy1Btn(9))&&(joy2Btn(9))&&(joy1Btn(10))&&(joy2Btn(10))) g_program_done = true;

		//-----------------------------
		// block grabber
		//-----------------------------

		if(joy1Btn(5)||joy2Btn(5)) servo[goal_claw] = g_goal_claw_up;
		else if(joy1Btn(7)||joy2Btn(7)) servo[goal_claw] = g_goal_claw_down;
	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
