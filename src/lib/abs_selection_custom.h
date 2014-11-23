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
	g_input_array[STARTING_POINT] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[STARTING_POINT] < g_auto_starting_points) g_input_array[STARTING_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[STARTING_POINT] > 1/*0*/) g_input_array[STARTING_POINT]--;
		}
		if(g_input_array[STARTING_POINT]==1) abs_cscreen("Starting","point   ","RAMP    ");
		else abs_cscreen("Starting","point   ","FLOOR   ");
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
	g_input_array[FIRST_OBJECTIVE] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[FIRST_OBJECTIVE] < g_first_objectives) g_input_array[FIRST_OBJECTIVE]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[FIRST_OBJECTIVE] > -1) g_input_array[FIRST_OBJECTIVE]--;
		}
		switch(g_input_array[FIRST_OBJECTIVE])
		{
		case 0: abs_cscreen("First   ","Objectiv","STOP    "); break;
		case 1: abs_cscreen("First   ","Objectiv","ROLGOAL1"); break;
		case 2: abs_cscreen("First   ","Objectiv","CENTGOAL"); break;
		case 3: abs_cscreen("First   ","Objectiv","ROLGOAL2"); break;
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
	g_input_array[SECOND_OBJECTIVE] = 1;

	while(true)
	{
		if(nNxtButtonPressed == kEnterButton&&(g_input_array[FIRST_OBJECTIVE]==g_input_array[SECOND_OBJECTIVE]))
			while(nNxtButtonPressed == kEnterButton) abs_cscreen("INVALID ","OPTION  ","        ");
		else if(nNxtButtonPressed == kEnterButton) break;

		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[SECOND_OBJECTIVE] < g_second_objectives) g_input_array[SECOND_OBJECTIVE]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[SECOND_OBJECTIVE] > -1) g_input_array[SECOND_OBJECTIVE]--;
		}

		switch(g_input_array[SECOND_OBJECTIVE])
		{
		case 0: abs_cscreen("Second  ","Objectiv","STOP    "); break;
		case 1: if(g_input_array[FIRST_OBJECTIVE]==1) abs_cscreen("Second  ","Objectiv","N/A     ");
			else abs_cscreen("Second  ","Objectiv","ROLGOAL1"); break;
		case 2: if(g_input_array[FIRST_OBJECTIVE]==2) abs_cscreen("Second  ","Objectiv","N/A     ");
			else abs_cscreen("Second  ","Objectiv","CENTGOAL"); break;
		case 3: if(g_input_array[FIRST_OBJECTIVE]==3) abs_cscreen("Second  ","Objectiv","N/A     ");
			else abs_cscreen("Second  ","Objectiv","ROLGOAL2"); break;
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
	g_input_array[END_POINT] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[END_POINT] < g_auto_ending_points) g_input_array[END_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[END_POINT] > 0) g_input_array[END_POINT]--;
		}
		switch(g_input_array[END_POINT])
		{
		case 0: abs_cscreen("End pnt ","ERROR   ","        "); break;
		case 1: abs_cscreen("End pnt ","Low Area","        "); break;
		case 2: abs_cscreen("End pnt ","STOP    ","        "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();
}

#endif /* !ABS_SELECTION_CUSTOM_H */
