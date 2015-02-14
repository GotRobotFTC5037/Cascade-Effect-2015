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
	// IR type
	//---------------------------------------
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			if(g_selected_IR == IR_180) g_selected_IR = IR_CLASSIC;
			else g_selected_IR = IR_180;
			while(nNxtButtonPressed == kRightButton){}
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			if(g_selected_IR == IR_180) g_selected_IR = IR_CLASSIC;
			else g_selected_IR = IR_180;
			while(nNxtButtonPressed == kLeftButton){}
		}
		switch(g_selected_IR)
		{
		case IR_180:    abs_cscreen("IR Type ","IR      "," 180    "); break;
		case IR_CLASSIC: abs_cscreen("IR Type ","IR      "," Classic"); break;
		default:        abs_cscreen("ERROR   ","        ","        "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_SELECTION_OPTIONS_H */
