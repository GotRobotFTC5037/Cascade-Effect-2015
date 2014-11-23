/**
*
*  @file abs_wait_selection.h
*
*  @brief selection wait function for when ever we need a pause in autonomous
*
*  @param which_delay what autonomous delay this is being called for
*
*  @param max highest value that can be told for the robot to wait
*
*  @param min lowest value that can be told for the robot to wait
*
*  @param line1 first line requested to be displayed on the screen
*
*  @param line2 second line requested to be displayed on the screen
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_WAIT_SELECTION_H
#define ABS_WAIT_SELECTION_H

void abs_wait_selection(int which_delay, int max_val, int min_val, const char * line1, const char * line2)
{
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[which_delay]< max_val) g_input_array[which_delay]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[which_delay] > min_val) g_input_array[which_delay]--;
		}
		abs_cscreen(line1,line2,"%2d       ",g_input_array[which_delay]);
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_WAIT_SELECTION_H */
