/**
*
*  @file abs_selection_custom.h
*
*  @brief handles the custom selection options for auto mission selection
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_CUSTOM_H
#define ABS_SELECTION_CUSTOM_H

#include "lib/abs_cscreen.h"
#include "lib/abs_wait_selection.h"

void abs_selection_custom()
{
	//---------------------------------------
	// Start point selection
	//---------------------------------------
	g_input_array[STARTING_POINT] = START_RAMP;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[STARTING_POINT] < STARTING_OPTIONS) g_input_array[STARTING_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[STARTING_POINT] > 0) g_input_array[STARTING_POINT]--;
		}
		switch(g_input_array[STARTING_POINT])
		{
			case START_STOP:				abs_cscreen("Starting","        ","STOP    "); break;
			case START_RAMP: 				abs_cscreen("Starting","        ","RAMP    "); break;
			case START_FLOOR_LEFT: 	abs_cscreen("Starting","FLOOR   ","LEFT    "); break;
			case START_FLOOR_RIGHT:	abs_cscreen("Starting","FLOOR   ","RIGHT   "); break;
			default:								abs_cscreen("Starting","        ","ERROR   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// start time selection
	//---------------------------------------
	g_input_array[STARTING_DELAY] = 0;
	abs_wait_selection(STARTING_DELAY, 30, 0, "Starting", "delay   ");

	//---------------------------------------
	// first objective selection
	//---------------------------------------
	g_input_array[FIRST_OBJECTIVE] = FIRST_ROLLGOAL1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[FIRST_OBJECTIVE] < FIRST_OBJECTIVE_OPTIONS) g_input_array[FIRST_OBJECTIVE]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[FIRST_OBJECTIVE] > 0) g_input_array[FIRST_OBJECTIVE]--;
		}
		switch(g_input_array[FIRST_OBJECTIVE])
		{
		case FIRST_STOP:				abs_cscreen("FirstObj","        ","STOP    "); break;
		case FIRST_ROLLGOAL1:		abs_cscreen("FirstObj","60cmROLL","GOAL    "); break;
		case FIRST_CENTER_GOAL:	abs_cscreen("FirstObj","CENTER  ","GOAL    "); break;
		case FIRST_ROLLGOAL2:		abs_cscreen("FirstObj","90cmROLL","GOAL    "); break;
		default:								abs_cscreen("FirstObj","        ","ERROR   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// first objective time selection
	//---------------------------------------
	g_input_array[FIRST_OBJECTIVE_DELAY] = 0;
	abs_wait_selection(FIRST_OBJECTIVE_DELAY, 30, 0, "1stObjec", "delay   ");

	//---------------------------------------
	// second objective selection
	//---------------------------------------
	g_input_array[SECOND_OBJECTIVE] = SECOND_KICK_STAND;

		while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[SECOND_OBJECTIVE] < SECOND_OBJECTIVE_OPTIONS) g_input_array[SECOND_OBJECTIVE]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[SECOND_OBJECTIVE] > 0) g_input_array[SECOND_OBJECTIVE]--;
		}
		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case SECOND_STOP:									abs_cscreen("SecndObj","        ","STOP    "); break;
		case SECOND_KICK_STAND:						abs_cscreen("SecndObj","KICK    ","STAND   "); break;
		case SECOND_ROLLGOAL1:						abs_cscreen("SecndObj","60cmROLL","GOAL    "); break;
		case SECOND_ROLLGOAL2:						abs_cscreen("SecndObj","90cmROLL","GOAL    "); break;
		case SECOND_PARKING_ZONE_RIGHT:		abs_cscreen("SecndObj","ParkZone","RIGHT   "); break;
		case SECOND_PARKING_ZONE_LEFT:		abs_cscreen("SecndObj","ParkZone","LEFT    "); break;
		default:													abs_cscreen("SecndObj","        ","ERROR   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// second objective time selection
	//---------------------------------------
	g_input_array[SECOND_OBJECTIVE_DELAY] = 0;
	abs_wait_selection(SECOND_OBJECTIVE_DELAY, 30, 0, "2ndObjec", "delay   ");

	//---------------------------------------
	// Start of end point selection 5
	//---------------------------------------
	g_input_array[END_POINT] = END_PARKING_ZONE_RIGHT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[END_POINT] < END_OBJECTIVE_OPTIONS) g_input_array[END_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[END_POINT] > 0) g_input_array[END_POINT]--;
		}
		switch(g_input_array[END_POINT])
		{
		case END_STOP: 								abs_cscreen("End pnt ","        ","STOP    "); break;
		case END_KICK_STAND:					abs_cscreen("End pnt ","KICK    ","STAND   "); break;
		case END_ROLLGOAL1: 					abs_cscreen("End pnt ","60cmROLL","GOAL    "); break;
		case END_ROLLGOAL2: 					abs_cscreen("End pnt ","90cmROLL","GOAL    "); break;
		case END_PARKING_ZONE_RIGHT:	abs_cscreen("End pnt ","ParkZone","RIGHT   "); break;
		case END_PARKING_ZONE_LEFT:		abs_cscreen("End pnt ","ParkZone","LEFT    "); break;
		default:											abs_cscreen("End pnt ","        ","ERROR   "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();
}

#endif /* !ABS_SELECTION_CUSTOM_H */
