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
	int shutter_state = g_shutter_closed;
	bool shutter_button_pressed = false;
	bool lift_move_dir_up = false;
	int lift_active = 1;
	int shoulder_state = 0;
	bool shoulder_active = false;
	int shoulder_min = 0;

	while(true)
	{
		nxtDisplayBigTextLine(1,"%3d",nMotorEncoder(lift1));
		nxtDisplayBigTextLine(3,"%3d",((((g_shoulder_mid-nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed));//nMotorEncoder(shoulder));
		nxtDisplayBigTextLine(5,"%3d",(((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);//(((nMotorEncoder(lift1)-0)*100)/g_max_lift));
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

		if(abs(joystick.joy2_y2)>10)
		{
			if(joy2Btn(12)) motor[shoulder] = (joystick.joy2_y2*100)/127;
			else motor[shoulder] = ((joystick.joy2_y2*100)/127)/2;
			shoulder_active = false;
		}
		if(joy2Btn(2))
		{
			shoulder_active = true;
			shoulder_state = g_shoulder_low;
			shoulder_min = g_min_lift;
		}
		else if(joy2Btn(3))
		{
			shoulder_active = true;
			shoulder_state = g_shoulder_mid;
			shoulder_min = g_min_lift;
		}
		else if(joy2Btn(4))
		{
			shoulder_active = true;
			shoulder_state = g_shoulder_tall;
			shoulder_min = g_tall_min_lift;
		}
		else if(joy2Btn(6))
		{
			shoulder_active = true;
			shoulder_state = g_shoulder_center;
			shoulder_min = g_tall_min_lift;
		}

		if(shoulder_active&&nMotorEncoder(lift1)>shoulder_min)
		{
			if(nMotorEncoder(shoulder)<shoulder_state) motor[shoulder] = ((((shoulder_state-nMotorEncoder(shoulder))*100)/g_shoulder_max)+g_shoulder_min_speed);
			else shoulder_active = false;
		}
		else if(abs(joystick.joy2_y2)<10)
		{
			motor[shoulder] = 0;
		}

		//-----------------------------
		// ball lift buttons
		//-----------------------------

		if(joystick.joy2_y1>10)
		{
			if(joy2Btn(11)) int lift_speed = 100;
			else
			{
				if(nMotorEncoder(lift1)<g_max_lift) lift_speed = g_lift_speed_up;
				else lift_speed = 0;
			}
			motor[lift1] = lift_speed;
			motor[lift2] = lift_speed;

			lift_active = 1;
		}
		else if(joystick.joy2_y1<-10)
		{
			if(joy2Btn(11)) int lift_speed = -100;
			else
			{
				if(nMotorEncoder(lift1)>0) lift_speed = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
				else lift_speed = 0;
			}
			motor[lift1] = lift_speed;
			motor[lift2] = lift_speed;

			lift_active = 1;
		}
		else if(joy2Btn(6))  //CENTER GOAL SCORING POSISION
		{
			lift_active = 6;
			if(nMotorEncoder(lift1)>g_center_lift) lift_move_dir_up = false;
			else lift_move_dir_up = true;
		}
		else if(lift_active == 6)
		{
			if(!lift_move_dir_up&&nMotorEncoder(lift1)>g_center_lift)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-g_center_lift)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-g_center_lift)*100)/g_max_lift)+g_lift_min_speed);
			}
			else if(lift_move_dir_up&&nMotorEncoder(lift1)<g_center_lift)
			{
				motor[lift1] = g_lift_speed_up;
				motor[lift2] = g_lift_speed_up;
			}
			else lift_active = 1;
		}
		else if(joy2Btn(8)) lift_active = 8; //BALL LIFT AT FLOOR, INTAKE POSITION
		else if(lift_active == 8)
		{
			if(nMotorEncoder(lift1)>0)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-0)*100)/g_max_lift)+g_lift_min_speed);
			}
			else lift_active = 1;
		}
		else if(joy2Btn(4)) //Y //TALL ROLLING GOAL SCORING POSITION
		{
			lift_active = 4;
			if(nMotorEncoder(lift1)>g_tall_lift) lift_move_dir_up = false;
			else lift_move_dir_up = true;
		}
		else if(lift_active == 4)
		{
			if(!lift_move_dir_up&&nMotorEncoder(lift1)>g_tall_lift)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-g_tall_lift)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-g_tall_lift)*100)/g_max_lift)+g_lift_min_speed);
			}
			else if(lift_move_dir_up&&nMotorEncoder(lift1)<g_tall_lift)
			{
				motor[lift1] = g_lift_speed_up;
				motor[lift2] = g_lift_speed_up;
			}
			else lift_active = 1;
		}
		else if(joy2Btn(3)) //B //MID ROLLING GOAL SCORING POSITION
		{
			lift_active = 3;
			if(nMotorEncoder(lift1)>g_mid_lift) lift_move_dir_up = false;
			else lift_move_dir_up = true;
		}
		else if(lift_active == 3)
		{
			if(!lift_move_dir_up&&nMotorEncoder(lift1)>g_mid_lift)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-g_mid_lift)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-g_mid_lift)*100)/g_max_lift)+g_lift_min_speed);
			}
			else if(lift_move_dir_up&&nMotorEncoder(lift1)<g_mid_lift)
			{
				motor[lift1] = g_lift_speed_up;
				motor[lift2] = g_lift_speed_up;
			}
			else lift_active = 1;
		}
		else if(joy2Btn(2)) //A //LOW ROLLING GOAL SCORING POSITION
		{
			lift_active = 2;
			if(nMotorEncoder(lift1)>g_low_lift) lift_move_dir_up = false;
			else lift_move_dir_up = true;
		}
		else if(lift_active == 2)
		{
			if(!lift_move_dir_up&&nMotorEncoder(lift1)>g_low_lift)
			{
				motor[lift1] = -((((nMotorEncoder(lift1)-g_low_lift)*100)/g_max_lift)+g_lift_min_speed);
				motor[lift2] = -((((nMotorEncoder(lift1)-g_low_lift)*100)/g_max_lift)+g_lift_min_speed);
			}
			else if(lift_move_dir_up&&nMotorEncoder(lift1)<g_low_lift)
			{
				motor[lift1] = g_lift_speed_up;
				motor[lift2] = g_lift_speed_up;
			}
			else lift_active = 1;
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;
		}
		//-----------------------------
		// intake
		//-----------------------------

		if(joy1Btn(2))
		{
			motor[brush] = -60;
		}
		else if(joy1Btn(4))
		{
			servo[impellar1] = 255;
			servo[impellar2] = 0;
		}
		else if(joy2Btn(5))
		{
			motor[brush] = 40;
			servo[impellar1] = 0;
			servo[impellar2] = 255;
		}
		else
		{
			motor[brush] = 0;
			servo[impellar1] = 127;
			servo[impellar2] = 127;
		}

		//-----------------------------
		// robot kill switch
		//-----------------------------
		if((joy1Btn(9))&&(joy2Btn(9))&&(joy1Btn(10))&&(joy2Btn(10))) g_program_done = true;

		//-----------------------------
		// shutter
		//-----------------------------

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
