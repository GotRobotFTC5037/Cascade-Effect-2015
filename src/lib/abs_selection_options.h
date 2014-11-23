/**
*
*  @file abs_selection_options.h
*
*  @brief
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_OPTIONS_H
#define ABS_SELECTION_OPTIONS_H

#include "lib/abs_cscreen.h"

void abs_selection_options()
{
	//---------------------------------------
	// stand ground
	//---------------------------------------
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_stay_on_ramp == true) g_stay_on_ramp = false;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_stay_on_ramp == false) g_stay_on_ramp = true;
		}
		if(g_stay_on_ramp == true) abs_cscreen("Stay on ","ramp    ","true    ");
		else abs_cscreen("Stay on ","ramp    ","false   ");
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_SELECTION_OPTIONS_H */
