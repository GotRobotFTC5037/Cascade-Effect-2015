#pragma systemFile // treat as system file to eliminate warnings for unused variables
/**
*
*  @file global_variables.h
*
*  @brief varaibles that are global
*
*  @param None n/a
*
*  @return
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
//
//============================================================
// Define sensor multiplexor connectivity and port allocations
//============================================================

#include "compile_flags.h"

#if ENCODER_SIDE_USED == 1
#define ENCODER_SIDE left_motor
#else
#define ENCODER_SIDE right_motor
#endif

//const tMUXSensor HTIRS2 = msensor_S3_1;    // HiTechnic Infrared sensor
const tMUXSensor HTAC = msensor_S2_1;
const tMUXSensor HTGYRO = msensor_S3_1;	     // HiTechnic GYRO sensor
const tMUXSensor LEGOUS2 = msensor_S2_4;     // sonar 2 right side sensor
const tMUXSensor HTIRS2 = msensor_S2_3;      // HiTechnic Infrared sensor 2
const tMUXSensor LEGOTOUCH = msensor_S3_4;   // touchsensor;
const tMUXSensor LEGOUS = msensor_S2_2;      // sonar 1 center goal detection sensor
const tMUXSensor angle_sensor = msensor_S4_1;      // angle sensor
const tMUXSensor LEGOUS3 = msensor_S4_2;     // sonar 3 left side sensor
const tMUXSensor LEGOUS4 = msensor_S4_3;     // sonar 4 rolling goal sensor
const tMUXSensor LEGOUS5 = msensor_S4_4;     // sonar 5 rolling goal sensor #2

//#if EOPD_ACTIVE == 1
//const tMUXSensor HTEOPD = msensor_S2_4;
//#else
//const tMUXSensor LEGOLS = msensor_S2_4;
//#endif

/**
* @var g_gyro_true
*		Tells the robot if it should use the gyro or not
*/
bool g_gyro_true = false;

//=========================================================
// Robot constants
//=========================================================

/**
*
*  @def INT_ANGLE_SENSOR_CIRCUMFERENCE
*     Tells the robot the circumference of the angle sensors wheel
*  @def FLOAT_ANGLE_SENSOR_CIRCUMFERENCE
*     Tells the robot the exact circumference of the angle sensors wheel
*  @def DRIVE_WHEELS_CIRCUMFERENCE
*     Tells the robot the cercumference of the drive wheels
*  @def GRABBER_LEFT_OPEN
*     tells the robot where the left block grabber needs to be to be open
*  @def GRABBER_RIGHT_OPEN
*     tells the robot where the right block grabber needs to be to be open
*  @def GRABBER_LEFT_MID
*     tells the robot where the left block grabber needs to be to be in the middle
*  @def GRABBER_RIGHT_MID
*     tells the robot where the right block grabber needs to be to be in the middle
*  @def GRABBER_LEFT_CLOSE
*     tells the robot where the left block grabber needs to be to be closed
*  @def GRABBER_RIGHT_CLOSE
*     tells the robot where the left block grabber needs to be to be closed
*/
#define INT_ANGLE_SENSOR_CIRCUMFERENCE_TU 13
#define INT_ANGLE_SENSOR_CIRCUMFERENCE_BPU 18
#define FLOAT_ANGLE_SENSOR_CIRCUMFERENCE_BPU 17.6
#define FLOAT_ANGLE_SENSOR_CIRCUMFERENCE_TU 13.3
#define DRIVE_WHEELS_CIRCUMFERENCE 26

#define GRABBER_LEFT_OPEN 3
#define GRABBER_RIGHT_OPEN 245
#define GRABBER_LEFT_MID 60
#define GRABBER_RIGHT_MID 180
#define GRABBER_LEFT_CLOSE 120
#define GRABBER_RIGHT_CLOSE 131

/**
* @var g_angle_sensor_val
*		Tells the robot the value of the raw angle sensor
* @var g_EOPD_sensor
*		Tells the robot the value of the raw angle sensor
* @var g_optical_sensor
*		Tells the robot the value of the raw angle sensor
*/

long g_angle_sensor_val = 0;

int g_EOPD_sensor = 0;

int g_optical_sensor = 0;

/**
*
* @var g_block_speed_down
* 		Tells the robot how fast to move the lift
*
* @var g_block_speed_up
* 		 Tells the robot how fast to move the lift
*
* @var g_robot_lift_down
* 		 Tells the robot how fast to move the sky hook
*
* @var g_robot_lift_up
* 		Tells the robot how fast to move the sky hook
*
* @var g_flag_speed_down
* 		Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_right
* 		Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_up
* 		 Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_left
* 		Tells the robot how fast to move the flag lifter
*
* @var g_abdd_up
* 		 Tells the robot how fast to move the abdd
*
* @var g_abdd_down
* 		Tells the robot how fast to move the abdd
*
* @var g_gyro_adjust
* 		Multiplyer for gyro adjust
*
* @var g_block_speed_down
* 		Tells the robot how fast to move the block grabber down
*
* @var g_block_speed_up
* 		Tells the robot how fast to move the block grabber up
*
* @var g_robot_lift_down
* 		Tells the robot how fast to move the robot lft down
*
* @var g_robot_lift_up
* 		Tells the robot how fast to move the robot lift up
*
* @var g_flag_speed_down
* 		Tells the robot how fast to spin the flag lift to make the flag go down
*
* @var g_flag_speed_right
* 		Tells the robot how fast to spin the robot flag lift right
*
* @var g_flag_speed_up
* 		Tells the robot how fast to spin the robot flag to make the flag go up
*
* @var g_flag_speed_left
*			Tells the robot how fast to spin the robot flag lift left
*
* @var g_abdd_up
* 		Tells the robot what position to put the servo when puting it up
*
* @var g_abdd_down
* 		Tells the robot what position to put the servo when puting it down
*
* @var g_gyro_adjust
* 		The Multiplyer for gyro calabration
*
* @var g_ground_arm_up
* 		Tells the robot where to put the ground arm when going up
*
* @var g_ground_arm_down
* 		Tells the robot where to put the ground arm when going down
*
* @var g_original_gyro_val
*			Tells the robot what then orginal value of the gyro was
* @var g_optical_threshold
* 		Tells the robot what the optical threshhold is
*
* @var g_optical_move_min_dist
* 		Tells the robot how far it should move before it should be in optical detection distence
*
* @var g_IR_center_goal_dist
* 		The distance from the wall were the robot reads the center goal position
*
* @def NON_IR_DRIVE_SPEED
*			Tells the robot how fast to go when its not using IR
*
* @def IR_DRIVE_SPEED
*			Tells the robot how fast to go when its using IR
*
* @def TURN_SPEED
*			Tells the robot how fast to turn
*
*
*/
bool g_auto_lift_done = false;

const int g_lift_min_speed = 10;
const int g_max_lift = 10000;
const int g_low_lift = 0;
const int g_mid_lift = 2500;
const int g_tall_lift = 5850;
const int g_center_lift = 6800;
const int g_jog_lift = 200;

const int g_shoulder_max = 8000;
const int g_shoulder_tall = 7620;//was 7650
const int g_shoulder_low = 6209;
const int g_shoulder_mid = 6500;//6900;
const int g_shoulder_min_speed = 24;//was 18
const int g_shoulder_center = 4600;
const int g_shoulder_lower_min = 6500;

const int g_brush_out_speed = -100;
const int g_brush_in_speed = 60;

const int g_min_lift = 500;
const int g_low_min_lift = 500;
const int g_tall_min_lift =	600;
const int g_center_min_lift = 3000;

const int g_lift_speed_down = -60;
const int g_lift_speed_up = 100;

const int g_shutter_open = 255;
const int g_shutter_closed = 127;

const int g_intake_shutter_up = 240;
const int g_intake_shutter_down = 0;

const int g_goal_claw_up = 225;
const int g_goal_claw_down = 60;

const int g_gyro_adjust = 5;//10;
const float g_sonar_adjust = 1;
int g_original_gyro_val = 0;

const int g_ground_arm_up = 0;

const int g_ground_arm_down = 120;

//#if EOPD_ACTIVE == 1
const int g_optical_threshold = 100;//305;
//#else
//const int g_optical_threshold = 30;
//#endif

const int g_sonar_center_goal_dist_180 = 450;//324;
const int g_IR_center_goal_dist_classic = 125;
const int g_center_pos_sonar_dist = 100;

int g_auto_pipe_score_hight = g_mid_lift;
int g_auto_pipe_score_angle = g_shoulder_mid;

bool g_gyro_inherit = false;

const int g_optical_move_min_dist = 70;

const int g_center_detect_value = 30;

const int g_sonar_wall_dist = 11;

int g_roll_to_parking_turn = 0;

#define NON_IR_DRIVE_SPEED 70
#define IR_DRIVE_SPEED 40

#define TURN_SPEED 50

bool g_reset_stall_detect = true;

//=========================================================
// auto selection type options
//=========================================================
/**
*  @enum e_selection_types Lets the robot know how you want to imploment the auto program
*  @var e_auto_selection_points::SELECTION_TYPE_NUMBER
*     Select a program by id
*  @var e_auto_selection_points::SELECTION_TYPE_CUSTOM
*     Select one of the custom programs
*  @var e_auto_selection_points::SELECTION_TYPE_QUICK
*     Select one of the most commenly used progams
*  @var e_auto_selection_points::SELECTION_TYPE_ADVANCED
*     Select some of the more advanced fetures for auto
*  @var e_auto_selection_points::SELECTION_TYPE_OPTIONS
*     Chnage the settings for the robots auto
* @var selection_type
*		Tells the robot the selection type
*/
typedef enum
{
	SELECTION_TYPE_NUMBER,
	SELECTION_TYPE_CUSTOM,
	SELECTION_TYPE_QUICK,
	SELECTION_TYPE_ADVANCED,
	SELECTION_TYPE_OPTIONS
} e_selection_types;

e_selection_types selection_type = SELECTION_TYPE_CUSTOM;

/**
*  @enum e_selection_values Tells the robot what number you are editing
*  @var e_auto_selection_points::SELECTION_VALUE_EMPTY
*     Tells the robot what number you are editing nothing
*  @var e_auto_selection_points::STARTING_POINT
*     Tells the robot what number you are editing the starting point
*  @var e_auto_selection_points::STARTING_DELAY
*     Tells the robot what number you are editing the starting delay
*  @var e_auto_selection_points::SCOREING_POINT
*     Tells the robot what number you are editing the scoring point
*  @var e_auto_selection_points::END_DELAY
*     Tells the robot what number you are editing the delay at the end
*  @var e_auto_selection_points::END_POINT
*     Tells the robot what number you are editing where you end the program
*  @var e_auto_selection_points::CORNOR_DELAY
*     Tells the robot to do the corner delay
*  @var e_auto_selection_points::RAMP_DELAY
*     Tells the robot to do the ramp delay
*/

typedef enum
{
	START_STOP,
	START_RAMP,
	START_FLOOR_LEFT,
	START_FLOOR_RIGHT
} e_starting_points;
const int STARTING_OPTIONS = 3;

typedef enum
{
	FIRST_STOP,
	FIRST_ROLLGOAL1,
	FIRST_CENTER_GOAL,
	FIRST_ROLLGOAL2,
	FIRST_ROLL1_ROLL3,
	FIRST_DEFENCE
} e_first_objectives;
const int FIRST_OBJECTIVE_OPTIONS = 5;

typedef enum
{
	SECOND_STOP,
	SECOND_KICK_STAND,
	SECOND_ROLLGOAL1,
	SECOND_ROLLGOAL2,
	SECOND_PARKING_ZONE_RIGHT,
	SECOND_PARKING_ZONE_LEFT
} e_second_objectives;
const int SECOND_OBJECTIVE_OPTIONS = 5;

typedef enum
{
	END_STOP,
	END_KICK_STAND,
	END_ROLLGOAL1,
	END_ROLLGOAL2,
	END_PARKING_ZONE_RIGHT,
	END_PARKING_ZONE_LEFT,
	END_PARKING_ZONE_RIGHT_KICK
} e_end_objectives;
const int END_OBJECTIVE_OPTIONS = 6;

typedef enum
{
	SELECTION_VALUE_EMPTY,
	STARTING_POINT,
	STARTING_DELAY,
	FIRST_OBJECTIVE,
	FIRST_OBJECTIVE_DELAY,
	SECOND_OBJECTIVE,
	SECOND_OBJECTIVE_DELAY,
	END_POINT,
} e_selection_values;

//=========================================================
// auto sub selections
//=========================================================
/**
*  @enum e_gyro_val_type the type of gyro units to read
*  @var e_gyro_val_type::RAW
*     provides the raw gyro value
*   @var e_gyro_val_type::CALIBRATED
*     provides the calibrated gyro value
*/
typedef enum
{
	RAW,
	CALIBRATED
} e_gyro_val_type;

/**
*  @enum e_angle_val_type the type of angle sensor units to read
*  @var e_angle_val_type::RELATIVE_ASU
*     provides the angle sensor reading in relative angle sensor units
*   @var e_angle_val_type::RELATIVE_BPU
*     provides the angle sensor reading in relative Black Perl units
*   @var e_angle_val_type::RELATIVE_CENTIMETERS
*     provides the angle sensor reading in relative centimeters
*  @var e_angle_val_type::RAW_ASU
*     provides the angle sensor reading in raw angle sensor units
*   @var e_angle_val_type::RAW_BPU
*     provides the angle sensor reading in raw Black Perl units
*   @var e_angle_val_type::RAW_CENTIMETERS
*     provides the angle sensor reading in raw centimeters
*/
typedef enum
{
	RELATIVE_ASU,
	RELATIVE_BPU,
	RELATIVE_TU,
	RELATIVE_CENTIMETERS,
	RAW_ASU,
	RAW_BPU,
	RAW_TU,
	RAW_CENTIMETERS
} e_angle_val_type;

/**
*  @enum e_angle_reset_type the type of angle sensor reset to perform
*  @var e_angle_val_type::SOFT_RESET
*     resets the interpretation of the angle sensor without resetting the actual sensor
*   @var e_angle_val_type::HARD_RESET
*     resets the actual sensor
*/
typedef enum
{
	SOFT_RESET,
	HARD_RESET
} e_angle_reset_type;

typedef enum
{
	SLOW_DOWN,
	DONT_SLOW_DOWN
} e_slow_down_at_end;

e_slow_down_at_end slow_down_at_end = SLOW_DOWN;

//=========================================================
// auto movements
//=========================================================
/**
* @def MAX_DRIVE_DIST_TO_FIRST_RAMP_LINE
*		Tells the robot the maxamum drive dist  to first ramp
*
* @def MIN_DRIVE_DIST_TO_FIRST_RAMP_LINE
*		Tells the robot the maxamum drive dist tot the first ramp
*
* @def DRIVE_DIST_TO_OPP_RAMP_SIDE
*		Tells the robot the distence it need to drive in order to got to the opponents ramp
*
*	@def FORWARD_IR_THRESHOLD
*		Tells the robot what the IR values need to be in order to detect the IR
*
*	@def BACKWARD_IR_THRESHOLD
*		Tells the robot what the IR values need to be in order to detect the IR
*
* @var g_reset_angle_record
*		Tells the robot of it should keep the value of the angle sensor or not
*/
#define MAX_DRIVE_DIST_TO_FIRST_RAMP_LINE 110
#define MIN_DRIVE_DIST_TO_FIRST_RAMP_LINE 20

#define DRIVE_DIST_TO_OPP_RAMP_SIDE 142

#define FORWARD_IR_THRESHOLD 7
#define BACKWARD_IR_THRESHOLD 3

bool g_reset_angle_record = true;

//=========================================================
// auto number input variable
//=========================================================
/**
* @def INPUT_ARRAY_SIZE
* 		 Tells the robot the size of the number of selection types
*
* @var g_input_array
* 		 Tells the robot all of the different options for automus
*/

#define INPUT_ARRAY_SIZE 10

int g_input_array[INPUT_ARRAY_SIZE];

//=========================================================
// Datalogging variables
//=========================================================
/**
* @var LogFileName
*		The name of the data logging file
*
* @var LogIoResult
*		The success status of writing to the log file
*
* @var LogFileHandle
*		The file handle variable (represents the file)
*
* @var LogFileSize
*		The size of the log file
*
* @var CRLF
*		characters required to cause output to appear on a new line
*
* @var LogData
*		Tells the robot is if should log data or not
*
* @var sString
*		Tells the robot the string we are sending to the wright handler
*
* @var g_delta_drift
*		Tells the robot the delta of the drift
*/
const string LogFileName = "DATALOG.txt";
TFileIOResult LogIoResult;
TFileHandle LogFileHandle;
long LogFileSize = 36000;
string sString;
string CRLF = (char)13+(char)10;

bool LogData = false;
float g_delta_drift = 0;

//=========================================================
// Misc
//=========================================================

/**
* @var g_debug_time_1
*		degbug varales fir IR
* @var g_debug_time_2
*		degbug varales fir IR
*
* @var g_auto_ending_points
*		degbuging var for this
* @var g_travel_dist
*		degbuging var for this
* @var g_auto_starting_points
*		degbuging var for this
* @var g_auto_missions
*		degbuging var for this
* @var g_drive_heading
*		degbuging var for this
* @var g_ir_heading
*		degbuging var for this
* @var g_program_done
*		degbuging var for this
*
* @var g_center_goal_pos
*		var to keep track of center goal pos
*
* @var g_joy1_enabled
*		degbuging var for this
* @var g_joy2_enabled
*		degbuging var for this
*
* @var g_selection_value
*		degbuging var for this
*
* @var g_quick_mission
*		Tells the robot the namber for quick selection
*
* @var g_max_quick_missions
*		Tells the robot the maxamum amout of quick selection programs
*/

int g_debug_time_1 = 0;
int g_debug_time_2 = 0;


int g_quick_mission = 1;
int g_max_quick_missions = 6;
int g_travel_dist = 0;
int g_drive_heading = 0;
int g_ir_heading = 5;
bool g_program_done = false;
int g_center_goal_pos = 0;
int g_roll1_sonar_turn = 0;


bool g_joy1_enabled = false;
bool g_joy2_enabled = false;

int g_selection_value = 0;

/**
* @def MIN_DRIVE_SPEED
*		Tells the robot the min drive speed
* @def MIN_TURN_SPEED
*		Tells the robot the min turn speed
*	@def DRIVE_SPEED_PERCENTAGE_DROP
*		Tells the robot the percentage it should drop when slowing down the speed
* @def DRIVE_SPEED_COEFFICIENT
*		Tells the robot how fast it should drop the speed
*	@def TURN_SPEED_PERCENTAGE_DROP
*		Tells the robot the persentage it should drop the speed
* @def TURN_SPEED_COEFFICIENT
*		Tells the robot how fast it should drop the speed
*/

#define MIN_DRIVE_SPEED 20
#define MIN_TURN_SPEED 15
#define DRIVE_SPEED_PERCENTAGE_DROP 25
#define DRIVE_SPEED_COEFFICIENT 30
#define TURN_SPEED_PERCENTAGE_DROP 50
#define TURN_SPEED_COEFFICIENT 5
/**
*
* @var g_good_gyro
*	flag indicating that the gyro has not given a bad reading
* @def GYRO_VALUE_QUEUE_SIZE
*	the size of the queue used to store the gyro readings
* @var g_gyro_values
*	array used to store all the gyro readings for debug purposes
* @var g_gyro_ran
*	flag indicating that we have performed at least one gyro read
*/
//#if EOPD_ACTIVE == 1
const int g_optical_delta_value = 100;
//#else
//const int g_optical_delta_value = 2;
//#endif
int g_calibrated_optical_threshold_val = 0;
int g_end_ramp_lift_speed = 40;
bool g_shift_due_to_ir = false;
bool g_good_gyro = true;

#if DEBUG_MODE == 1
#define GYRO_VALUE_QUEUE_SIZE 3
int g_gyro_values[GYRO_VALUE_QUEUE_SIZE];
#endif

bool g_gyro_ran = false;
/**
* @def MAX_TURN_RATE
*		Tells the robot the max rate thats possable to happen so we can know if the gyro gliches
* @def STAY_ON_RAMP_WAIT_TIME
*		Tells the robot the wait time before it  gose on the ramp
* @def OPTICAL_SENSOR_CALIBRATION_TIME
*		Tells the robot the time it needs to calibrate
* @def OPTICAL_CALIBRATION_SAMPLE_RATE
*		Tells the robot the Calibration sample rate
* @def DEFAULT_CALIBRATED_OPTICAL_THRESHOLD
*		Tells the robot the default calibration of the optical to force it to fail if it gives us weid readings
* @def DELAY_MULTIPLICATION_FACTOR
*	the factor to multiply all delays by
*/
#define MAX_TURN_RATE 0.72
#define STAY_ON_RAMP_WAIT_TIME 100
#define OPTICAL_SENSOR_CALIBRATION_TIME 2000
#define OPTICAL_CALIBRATION_SAMPLE_RATE 100
#define DEFAULT_CALIBRATED_OPTICAL_THRESHOLD 9999
#define DELAY_MULTIPLICATION_FACTOR 1000

//=============================================================
// Define user configurable parameters
//=============================================================

/**
* @var g_gyro_cal_time
*		Tells the robot how long to calibrate
*
* @var g_dist_backwards
*		Tells the robot how far to go backwards
*
* @var START_POINT_MAX_VAL
*		Tells the robot the max numbers of starting points
* @var START_POINT_MIN_VAL
*		Tells the robot the min nuber of starting points
*
* @var g_number_min_limit
*		Tells the robot the maxenum amount of numbers
* @var g_number_max_limit
*		Tells the robot the minunum amount of numbers
*
*
*/

/**
*  @enum e_em_first_turn_types Tells the robot if it should do a relitive or constant turn as its first one
*  @var e_em_first_turn_types::RELATIVE_TURN
*     Do a relitive turn
*   @var e_em_first_turn_types::CONSTANT_TURN
*     Do a consant turn
*/
typedef enum
{
	RELATIVE_TURN,
	CONSTANT_TURN
} e_turn_types;

int g_gyro_cal_time = 5;

int g_dist_backwards = 0;

//=============================================================
// Gyro variables
//=============================================================

/**
* @var g_gyro_noise
*		Tells the robot how much gyro noise there is
* @var g_start_time
*		Tells the robot the start time
* @var g_drift
*		Tells the robot the gyro drift
* @var g_const_heading
*		Tells the robot the const heading
* @var g_rel_heading
*		Tells the robot the relitive heading
* @var g_curr_time
*		Tells the robot the current time
* @var g_prev_time
*		Tells the robot the current time
* @var g_raw_gyro
*		Tells the robt the raw gyro value
* @var g_recont_heading
*		This is the recalculated const gyro heading
* @var g_sacred_const_heading
*		This is the recalculated value of the gyrp baced on a calculation
*/
int g_gyro_noise = 0;
long g_start_time = 0;
int g_drift = 0;
float g_sacred_const_heading = 0;
float g_const_heading = 0;
float g_rel_heading = 0;
long g_curr_time = 0;
long g_prev_time = 0;
int g_raw_gyro = 0;
int g_sonar = 0;
int g_sonar2 = 0;
int g_sonar3 = 0;
int g_sonar4 = 0;
int g_sonar5 = 0;
int g_sonar_average4 = 0;
int g_sonar_average5 = 0;
int g_sonar_reads4 [11];
int g_sonar_reads5 [11];
int g_recont_heading = 0; //this is the recalculated const gyro heading

bool force_done = false;
/**
* Sensor variables
*
* @var g_light_sensor
*		holds the value of the light sensor
*
* @var g_bearing_ac1
*		the raw value from the first IR sensor
*
* @var g_bearing_ac2
*		the raw value from the second IR sensor
*
* @var g_ir_bearing1
*		 the calibrated value from the first IR sensor
*
* @var g_ir_bearing2
*		the calibrated value from the second IR sensor
*
* @var g_curr_dir1
*		The value of the direction to deplay on the screen
*
* @var g_curr_dir2
*		The value of the direction to deplay on the screen
*
* @var g_misc
*		Tells the robot something to desply on the screen
*
* @var g_reset_angle
*		a varable that tells the robot to reset the angle sensor value
*
* @var dist_record
*		Tells the robot if it should calcuate the distence it needs to go instead of a raw value
*/

bool dist_record = true;
int g_angle_sensor = 0;
int g_light_sensor;
int g_bearing_ac1 = 0;
int g_bearing_ac2 = 0;
float g_ir_bearing1 = 0.0;
float g_ir_bearing2 = 0.0;
int g_acs1[5];
int g_acs2[5];
float g_curr_dir1 = 0.0;
float g_curr_dir2 = 0.0;
int g_misc = 0;
bool g_reset_angle = false;

/**
* @var g_sensor_reference_drive
*		Tells the robot if it should use sensors to help it drive
*/

bool g_sensor_reference_drive = false;

typedef enum
{
	IR_CLASSIC,
	IR_180
} e_IR_types;

e_IR_types g_selected_IR = IR_180;

/**
*  @enum e_light_sensor_status Tells the robot if it should turn on the light sensor
*  @var e_light_sensor_status::ACTIVE
*     Turn it on
*   @var e_light_sensor_status::INACTIVE
*     turn it off
*/
typedef enum
{
	ACTIVE,
	INACTIVE
} e_light_sensor_status;

typedef enum
{
	DO_STALL_ACTION,
	NO_STALL_ACTION
} E_STALL_ACTION;
//==============================================================
// Define graph selection variables
//==============================================================
/**
* @var g_graph_selection_tab
*		 Tells the user what number you are selecting
*/
int g_graph_selection_tab = 0;

//==============================================================
// Define error numbers
//==============================================================
/**
*
*  @def ERR_NONE
*     Tells the robot that theres no error
*   @def ERR_GYRO_CAL
*     Tells the robot that theres a error with the gyro calibrate
*  @def ERR_GYRO_MUX
*     Tells the robot that theres a error with the gyro mux
*  @def ERR_SENSOR_MUX
*     Tells the robot that theres a error with the sensor mux
*  @def ERR_JOYSTICKS
*     Tells the robot that theres a error with the joysticks
*  @var g_error
*			Tells the robot the number for an error
*/
#define ERR_NONE 0
#define ERR_GYRO_CAL 1
#define ERR_GYRO_MUX 2
#define ERR_SENSOR_MUX 3
#define ERR_JOYSTICKS 4

int g_error = 0;

/**
*  @enum e_error_types Tells the robot if a error is leathal or not
*  @var e_auto_sub_selection_ramp::ERROR_NONLETHAL
*     Tells the robot that the error is not leathal
*  @var e_auto_sub_selection_ramp::ERROR_LETHAL
*     Tells the robot that thbe error ios leathal
*
*  @var g_error_type
*		Tells the robot is an error is lethal or not
*/

typedef enum
{
	ERROR_NONLETHAL,
	ERROR_LETHAL
} e_error_types;

e_error_types g_error_type = ERROR_LETHAL;
