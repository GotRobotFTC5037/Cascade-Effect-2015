/**
*
*  @file diagnostic_sounds.h
*
*  @brief a collection of diagnostic tones
*
*  @param None n/a
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef DIAGNOSTIC_SOUNDS_H
#define DIAGNOSTIC_SOUNDS_H

#define DTONE_SPACING  50
#define DTONE_DURATION 300

/**
* @def play_error_tone()
*      plays error tone
*/
void play_error_tone()
{
	PlayTone(1600, DTONE_DURATION);
	Wait1Msec(DTONE_SPACING);
	PlayTone(800, DTONE_DURATION);
	Wait1Msec(DTONE_SPACING);
	PlayTone(400, DTONE_DURATION * 2);
}

/**
* @def play_success_tone()
*      plays success tone
*/
void play_success_tone()
{
	PlayTone(400, DTONE_DURATION);
	Wait1Msec(DTONE_SPACING);
	PlayTone(800, DTONE_DURATION);
	Wait1Msec(DTONE_SPACING);
	PlayTone(1600, DTONE_DURATION * 2);
}

#endif /* !DIAGNOSTIC_SOUNDS_H */
