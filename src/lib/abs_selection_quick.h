
/**
*
*  @file abs_selection_quick.h
*
*  @brief handles the quick selection options for auto mission selection
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_QUICK_H
#define ABS_SELECTION_QUICK_H

#include "lib/abs_cscreen.h"

void abs_selection_quick()
{
	//---------------------------------------
	// quick selection
	//---------------------------------------
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_quick_mission < g_max_quick_missions) g_quick_mission++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_quick_mission > 1) g_quick_mission--;
		}
		switch(g_quick_mission)
		{
		case 1:
			abs_cscreen("Mission ","Ramp Bsc","No Kick1");
			g_input_array[STARTING_POINT] = START_RAMP;	//RAMP
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_ROLLGOAL1;					//ROLLGOAL1
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_PARKING_ZONE_RIGHT;				//PARKING_ZONE
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_STOP;								//STOP
			break;
		case 2:
			abs_cscreen("Mission ","Ramp Bsc","Kick   2");
			g_input_array[STARTING_POINT] = START_RAMP;					//RAMP
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_ROLLGOAL1;					//ROLLING GOAL 1
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_PARKING_ZONE_RIGHT;					//LOW AREA
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_KICK_STAND;								//KICK STAND
			break;
		case 3:
			abs_cscreen("Mission ","Rmp60-90","prkRght3");
			g_input_array[STARTING_POINT] = START_RAMP;					//RAMP
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_ROLLGOAL1;					//ROLLING GOAL 1
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_ROLLGOAL2;				//ROLLING GOAL 2
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_PARKING_ZONE_RIGHT;								//LOW AREA
			break;
		case 4:
			abs_cscreen("Mission ","Rmp60-90","MltiPrk4");
			g_input_array[STARTING_POINT] = START_RAMP;					//RAMP
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_ROLL1_ROLL3;					//ROLLING GOAL 1 & 3
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_PARKING_ZONE_RIGHT;				//PARKING ZONE RIGHT SIDE
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_ROLLGOAL2;								//ROLLING GOAL 2
			break;
		case 5:
			abs_cscreen("Mission ","F Center","Kick   5");
			g_input_array[STARTING_POINT] = START_FLOOR_LEFT;					//FLOOR
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_CENTER_GOAL;					//CENTER GOAL
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_KICK_STAND;				//ROLLING GOAL 1
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_STOP;								//LOW AREA
			break;
		case 6:
			abs_cscreen("Mission ","Rmp60-90","prkKick6");
			g_input_array[STARTING_POINT] = START_RAMP;					//RAMP
			g_input_array[STARTING_DELAY] = 0;
			g_input_array[FIRST_OBJECTIVE] = FIRST_ROLLGOAL1;					//ROLLING GOAL 1
			g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
			g_input_array[SECOND_OBJECTIVE] = SECOND_ROLLGOAL2;				//ROLLING GOAL 2
			g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
			g_input_array[END_POINT] = END_PARKING_ZONE_RIGHT_KICK;								//LOW AREA / KICK
			break;
		}
	}
	while(nNxtButtonPressed == kEnterButton){}
	PlaySoundFile("! Click.rso");
}

#endif /* !ABS_SELECTION_NUMBER_H */
