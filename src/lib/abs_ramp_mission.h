/**
*
*  @file abs_ramp_mission.h
*
*  @brief all autonomous movements resulting from starting on the ramp
*
*  @param none N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2014, got robot? FTC Team 5037
*
*/

#ifndef ABS_RAMP_MISSION_H
#define ABS_RAMP_MISSION_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_second_objective.h"
#include "abs_IR_center_read.h"
#include "abs_auto_pipe_score.h"

//#include "global_variables.h"

void abs_ramp_mission()
{
	switch(g_input_array[FIRST_OBJECTIVE])
	{
	case STOP:
		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(STOP);
		break; //STOP
	case ROLLGOAL1:
		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 360, 30, true, GYRO, DONT_SLOW_DOWN);
		//abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 20, 60, BACKWARD);
		abs_drive(BACKWARD, E_ANGLE, 50, 30, true, GYRO, DONT_SLOW_DOWN);
		abs_turn(CLOCKWISE, SWING, TURN, 20, 60, BACKWARD);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 25, 60, FORWARD);
		motor[right_motor] = -20;
		motor[left_motor] = 20;
		wait1Msec(1000);
		while(g_sonar>g_center_detect_value&&abs(g_rel_heading)<100)
		{
			/*if(nMotorEncoder(shoulder)<g_shoulder_center-400)
			{
			motor[shoulder] = 40;
			}
			else
			{
			motor[shoulder] = 0;
			}*/
		}
		/*if(abs(g_rel_heading)>=25)
		{
		force_done = true;
		PlayTone(400,20);
		wait1Msec(250);
		PlayTone(300,20);
		}*/
		motor[right_motor] = 0;
		motor[left_motor] = 0;
		motor[shoulder] = 0;
		abs_dlog(__FILE__ ,"Sweep data","g_rel_heading", g_rel_heading);
		abs_dlog(__FILE__ ,"Sweep data","g_sonar", g_sonar);
		//broke out because we didnt see anything in the sweep

		if(!(abs(g_rel_heading)<100))
		{
			PlayTone(1500, 30);
			wait1Msec(200);
			PlayTone(1000, 30);
			wait1Msec(200);
			PlayTone(500, 30);
		}
		//Broke out because we saw nothing
		/*else if(g_sonar==255)
		{
		PlayTone(2000, 30);
		}
		//Saw the pipe*/
		else if(!(g_sonar>g_center_detect_value))
		{
			PlayTone(200,20);
			StartTask(abs_auto_pipe_score);
			wait1Msec(800);
			abs_turn(CLOCKWISE, SWING, TURN, 34, 35, BACKWARD);
			wait1Msec(400);
			abs_drive(BACKWARD, E_ANGLE, 12, 20, true, GYRO, DONT_SLOW_DOWN);
			wait1Msec(2500);
			servo[shutter] = g_shutter_open;
			g_auto_lift_done = true;
			wait1Msec(400);
			/*PlayTone(500, 30);
			wait1Msec(200);
			PlayTone(1000, 30);
			wait1Msec(200);
			PlayTone(1500, 30);*/
		}



		//abs_drive(BACKWARD, E_TIME, 800, 30, true, GYRO, DONT_SLOW_DOWN);

		/*motor[shoulder] = 40;
		while(nMotorEncoder(shoulder)<g_shoulder_mid-400) {  }
		motor[shoulder] = 0;*/

		//

		servo[shutter] = g_shutter_open;
		/**
		while(true)
		{
		nxtDisplayBigTextLine(2,"%2d %2d", g_bearing_ac1, g_center_goal_pos);
		}
		*/
		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);
		//while(!g_auto_lift_done){}
		//abs_turn(COUNTERCLOCKWISE, POINT, TURN, 20, 60, FORWARD);
		wait1Msec(1000);
		abs_second_objective(ROLLGOAL1);
		break;
	case CENTER_GOAL:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(CENTER_GOAL);
		break;
	case ROLLGOAL2:

		StartTask(abs_IR_center_read);
		abs_drive(BACKWARD, E_ANGLE, 430, 30, false, GYRO, DONT_SLOW_DOWN);
		abs_drive(BACKWARD, E_ANGLE, 45, 25, true, GYRO, DONT_SLOW_DOWN);

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);

		abs_turn(COUNTERCLOCKWISE, SWING, TURN, 50, 90);
		servo[goal_claw] = g_goal_claw_up;
		abs_drive(BACKWARD, E_ANGLE, 20, 25, true, GYRO, DONT_SLOW_DOWN);
		wait1Msec(500);

		abs_drive(FORWARD, E_ANGLE, 26, 25, true, GYRO, DONT_SLOW_DOWN);

		g_auto_pipe_score_hight = g_tall_lift;
		g_auto_pipe_score_angle = g_shoulder_tall+700;
		StartTask(abs_auto_pipe_score);

		abs_turn(CLOCKWISE, SWING, TURN, 53, 90);
		abs_drive(BACKWARD, E_ANGLE, 60, 25, true, GYRO, DONT_SLOW_DOWN);


		abs_drive(BACKWARD, E_ANGLE, 30, 25, true, GYRO, DONT_SLOW_DOWN);


		while(!g_auto_lift_done){}
		wait1Msec(1000);

		servo[goal_claw] = g_goal_claw_down;
		wait1Msec(500);

		abs_second_objective(ROLLGOAL2);
		break;
	case KICK_STAND:

		wait1Msec(STARTING_DELAY*DELAY_MULTIPLICATION_FACTOR);
		abs_second_objective(KICK_STAND);
		break;
	}
}

#endif /* !ABS_RAMP_MISSION_H */
