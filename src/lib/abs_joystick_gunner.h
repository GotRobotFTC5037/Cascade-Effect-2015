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
		switch(joystick.joy2_TopHat)
		{
		case -1: break;
		case 0: servo[goal_claw] = g_goal_claw_up; break;
		case 2: break;
		case 6: break;
		case 4: servo[goal_claw] = g_goal_claw_down; break;
		}

		switch(joystick.joy1_TopHat)
		{
		case -1: break;
		case 0: servo[goal_claw] = g_goal_claw_up; break;
		case 2: break;
		case 6: break;
		case 4: servo[goal_claw] = g_goal_claw_down; break;
		}

		//-----------------------------
		// shoulder
		//-----------------------------

		if(abs(joystick.joy2_y2)>10) motor[shoulder] = (joystick.joy2_y2*100)/127;
		else motor[shoulder] = 0;

		//-----------------------------
		// ball lift buttons
		//-----------------------------

		if(joystick.joy2_y1>10)
		{
			if(joy2Btn(11)) int lift_speed = 100;
			else lift_speed = g_lift_speed_up;
			motor[lift1] = lift_speed;
			motor[lift2] = lift_speed;
		}
		else if(joystick.joy2_y1<-10)
		{
			if(joy2Btn(11)) int lift_speed = -100;
			else lift_speed = g_lift_speed_down;
			motor[lift1] = lift_speed;
			motor[lift2] = lift_speed;
		}/*
		else if(joy2Btn(6))
		{
		//CENTER GOAL SCORING POSISION
		}
		else if(joy2Btn(8))
		{
		//BALL LIFT AT FLOOR, INTAKE POSITION
		}
		else if(joy2Btn(4))//Y
		{
		//TALL ROLLING GOAL SCORING POSITION
		}
		else if(joy2Btn(3))//B
		{
		//MID ROLLING GOAL SCORING POSITION
		}
		else if(joy2Btn(2))//A
		{
		//LOW ROLLING GOAL SCORING POSITION
		}*/
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
		}

		//-----------------------------
		// intake
		//-----------------------------

		static bool last_intake_true = false;

		if(joy2Btn(5))
		{
			last_intake_true = true;
			motor[brush] = 60;
			servo[impellar1] = 0;
			servo[impellar2] = 255;
		}
		else if(joy2Btn(7))
		{
			last_intake_true = false;
			motor[brush] = 0;
			servo[impellar1] = 127;
			servo[impellar2] = 127;
		}
		else if(joy1Btn(2))
		{
			motor[brush] = -60;
			//servo[impellar1] = 255;
			//servo[impellar2] = 0;
		}
		else if(!joy2Btn(5)&&!joy2Btn(7))
		{
			if(last_intake_true) motor[brush] = 60;
			else motor[brush] = 0;
			//servo[impellar1] = 127;
			//servo[impellar2] = 127;
		}

		//-----------------------------
		// robot kill switch
		//-----------------------------
		if((joy1Btn(9))&&(joy2Btn(9))&&(joy1Btn(10))&&(joy2Btn(10))) g_program_done = true;

		//-----------------------------
		// shutter
		//-----------------------------
		static int shutter_state = g_shutter_closed;
		static bool shutter_button_pressed = false;

		if(!joy2Btn(1))shutter_button_pressed = false;
		else if(shutter_button_pressed == false)
		{
			if(shutter_state == g_shutter_closed) shutter_state = g_shutter_open;
			else shutter_state = g_shutter_closed;

			shutter_button_pressed = true;
		}
		servo[shutter] = shutter_state;
	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
