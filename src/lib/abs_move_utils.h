/**
*
*  @file abs_move_utils.h
*
*  @brief abunch of things that help move the robot
*
*  @param None n/a
*
*  @returns Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_MOVE_UTILS_H
#define ABS_MOVE_UTILS_H

#include "global_variables.h"
/**
*  @enum e_direction This enum is used to let the robot know to turn clockwise or counterclickwise
*  @var e_direction::CLOCKWISE
*     turn clockwise
*  @var e_direction::COUNTERCLOCKWISE
*     turn counterclockwise
*/
typedef enum
{
	CLOCKWISE,
	COUNTERCLOCKWISE
} e_direction;

/**
*  @enum e_drive_direction Tells the robot what direction to drive
*  @var e_drive_direction::FORWARD
*     Drive forward
*  @var e_drive_direction::BACKWARD
*     Drive Backward
*/
typedef enum
{
	FORWARD,
	BACKWARD
} e_drive_direction;

/**
*  @enum e_move_stopping_method Tells the robot what direction to drive
*  @var e_move_stopping_method::E_TIME
*     Drive for a set amount of time spesified in dist
*  @var e_move_stopping_method::E_DEGREES
*     Drive for a certain amount of degrees spesified in dist
*  @var e_move_stopping_method::E_TILT
*     Drive until the robot tilts a certen amount spesified in dist
*  @var e_move_stopping_method::E_DISTANCE
*     Drive a certain amount of centameters spesified in dist
*  @var e_move_stopping_method::E_IR_DETECT
*     Drive until the robot detects the IR becon using the first IR sensor spesified in dist
*  @var e_move_stopping_method::E_IR_DETECT2
*     Drive until the robot detects the IR becon using the second IR sensor spesified in dist
*  @var e_move_stopping_method::E_ANGLE
*     Drive for a certain amount of degrees spesified in dist
*  @var e_move_stopping_method::E_OPTICAL
*     Drive until the optical sensor detects the lighting condition specified in dist
*/
typedef enum
{
	E_TILT,
	E_TIME,
	E_DISTANCE,
	E_DEGREES,
	E_IR_DETECT,
	E_IR_DETECT2,
	E_ANGLE,
	E_OPTICAL} e_move_stopping_method; //will make a method with a tilt sensor(wheel in the middle of the robot

/**
*  @enum e_turn_method Tells the robot what type of turn it should do
*  @var e_turn_method::SWING
*     Perform a swing turn
*  @var e_turn_method::POINT
*     Perform a point turn
*/
typedef enum
{
	SWING,
	POINT
} e_turn_method;

/**
*  @enum e_turn_stopping_method Tells the robot if to should to a certen amount of degreese or just turn
*  @var e_turn_stopping_method::TURN
*     Turn a swing turn
*  @var e_turn_stopping_method::TURN_TO
*     Turn a point turn
*/
typedef enum
{
	TURN,
	TURN_TO
} e_turn_stopping_method;

/**
*  @enum e_drive_type Tells the robot its corection type
*  @var e_auto_sub_selection_ramp::ENCODER
*     Tells the robot to correct useing a encoder
*  @var e_auto_sub_selection_ramp::GYRO
*     Tells the robot to correct useing a gyro sensor
*  @var e_auto_sub_selection_ramp::NON_SENSOR
*     Tells the robot not to correct
*/
typedef enum
{
	ENCODER,
	GYRO,
	WALL_SONAR,
	NON_SENSOR
} e_drive_type;


#define CORRECTION_DRIVE_TYPE NON_SENSOR

/**
*  @def distance_to_angle_derees(X)
*  converts @a X to degrees
*/
#define distance_to_angle_derees(X) ((float)((X)*360/ANGLE_SENSOR_CIRCUMFERENCE))

/**
*  @def distance_to_encoder_derees(X)
*  converts @a X to degrees
*/


//define distance_to_encoder_derees(X) ((X)*360/DRIVE_WHEELS_CIRCUMFERENCE)
#define distance_to_encoder_derees(X) ((X)*1440/DRIVE_WHEELS_CIRCUMFERENCE)

//#define adjusted_speed(X, Y, Z, C, P) (max(MIN_DRIVE_SPEED,(min(((C)*sqrt((Y)-(Z))+(P))*X/100),(X)))))

//Tells the robot to turn and then slowdown when it approches its desination
int adjusted_speed(int speed, int max_move_dist, int current, int coefficient, int percentage)
{
	/*int reduced_speed;
	if (max_move_dist - current >= 50)
	{
	reduced_speed = (speed/100)*((max_move_dist - current)*2);
	}
	*/
	float percent_of_speed = coefficient * sqrt(abs(max_move_dist-current)) + percentage;
	int reduced_speed = (int)percent_of_speed * speed / 100;

	if(reduced_speed > speed) { reduced_speed = speed; }

	return max(reduced_speed, MIN_DRIVE_SPEED);
}
/**
* X = Speed
*
* Y = Max dist
*
* Z = Current dist
*/
#define adjusted_drive_speed(X, Y, Z) adjusted_speed((X),(Y),(Z), DRIVE_SPEED_COEFFICIENT, DRIVE_SPEED_PERCENTAGE_DROP)


/**
* X = Speed
*
* Y = Max degrees
*
* Z = Current degrees
*/
#define adjusted_turn_speed(X, Y, Z) adjusted_speed((X),(Y),(Z), TURN_SPEED_COEFFICIENT, TURN_SPEED_PERCENTAGE_DROP)

#define stall_detect(X,Y) if((X) == DO_STALL_ACTION) { if(abs_stall_detect(abs_get_angle_sensor_val((Y)))) { StopAllTasks(); } }
#endif /* !ABS_TURN_UTILS */
