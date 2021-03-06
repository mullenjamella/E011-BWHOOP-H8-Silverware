#include "defines.h"
#include "hardware.h"

//Universal pids are already loaded for 6mm and 7mm whoops by default.  Adjust pids in pid.c file for any non whoop builds.  

//**********************************************************************************************************************
//***********************************************HARDWARE SELECTION*****************************************************

// *************DEFINE FLIGHT CONTROLLER HARDWARE
// *************SELECT ONLY ONE 
// *************uncomment BWHOOP define for bwhoop, bwhoop pro, E011C Santa Edition, and Beta FPV Lite Flight Controllers
// *************uncomment E011 define for E011 flight Controller
// *************uncomment H8mini_blue_board for the H8 mini flight controller with blue circuit board
#define BWHOOP
//#define E011
//#define H8mini_blue_board
//#define Alienwhoop_ZERO  // requires defining RX_SBUS radio protocol

//#define LIPO_HV

#define ACRO_EXPO_ADJUST_MULTIPLIER 0.10f
#define THROTTLE_EXPO_ADJUST_MULTIPLIER 0.10f

//#define ENABLE_THROTTLE_EXPO
#define THROTTLE_EXPO 1.0f

// *************Transmitter Type Selection
//#define USE_STOCK_TX
//#define USE_DEVO
#define USE_MULTI

//#define ENABLE_ARMING

//*************
//*************

//**********************************************************************************************************************
//***********************************************RECEIVER SETTINGS******************************************************

// *************rate in deg/sec
// *************for acro mode

#ifdef USE_STOCK_TX

#define MAX_RATE 720.0
#define MAX_RATEYAW 720.0

#endif

#ifndef USE_STOCK_TX

#define MAX_RATE 1400.0
#define MAX_RATEYAW 1400.0

#endif

// *************max angle for level mode
#define LEVEL_MAX_ANGLE 65.0f

// ************* low rates multiplier if rates are assigned to a channel
#define LOW_RATES_MULTI 0.5f

// *************EXPO from 0.00 to 1.00 , 0 = no exp
// *************positive = less sensitive near center 
#define ACRO_EXPO_ROLL 0.85
#define ACRO_EXPO_PITCH 0.85
#define ACRO_EXPO_YAW 0.60

#define ANGLE_EXPO_ROLL 0.4
#define ANGLE_EXPO_PITCH 0.2
#define ANGLE_EXPO_YAW 0.55

// *************transmitter stick adjustable deadband for roll/pitch/yaw
// *************.01f = 1% of stick range - comment out to disable
#define STICKS_DEADBAND .01f

// *************Radio protocol selection
// *************select only one
//#define RX_BAYANG_PROTOCOL
//#define RX_BAYANG_PROTOCOL_TELEMETRY
//#define RX_BAYANG_PROTOCOL_TELEMETRY_AUTOBIND
//#define RX_BAYANG_PROTOCOL_BLE_BEACON
#define RX_BAYANG_BLE_APP
//#define RX_NRF24_BAYANG_TELEMETRY
//#define RX_SBUS

// *******************************SWITCH SELECTION*****************************
// *************CHAN_ON - on always ( all protocols)
// *************CHAN_OFF - off always ( all protocols)
// *************Aux channels are selectable as CHAN_5 through CHAN_10 for DEVO and MULTIMODULE users
// *************Toy transmitter mapping is CHAN_5 (rates button), CHAN_6 (stick gestures RRD/LLD), 
//**************CHAN_7 (headfree button), CHAN_8 (roll trim buttons), CHAN_9 (pitch trim buttons)

//*************Arm switch and Idle Up switch (idle up will behave like betaflight airmode)
//*************comment out to disable arming or idle up features ONLY if not wanted.  Other features set to CHAN_OFF to disable

//*************Assign feature to auxiliary channel.  NOTE - Switching on LEVELMODE is required for any leveling modes to 
//*************be active.  With LEVELMODE active - MCU will apply RACEMODE if racemode channel is on, HORIZON if horizon 
//*************channel is on, or racemodeHORIZON if both channels are on - and will be standard LEVELMODE if neither 
//*************racemode or horizon are switched on.
#ifdef ENABLE_ARMING

#define ARMING CHAN_5
#define IDLE_UP CHAN_5
#define IDLE_THR 0.0009f

#endif

//*************Assign feature to auxiliary channel.  NOTE - Switching on LEVELMODE is required for any leveling modes to 
//*************be active.  With LEVELMODE active - MCU will apply RACEMODE if racemode channel is on, HORIZON if horizon 
//*************channel is on, or racemodeHORIZON if both channels are on - and will be standard LEVELMODE if neither 
//*************racemode or horizon are switched on.
//************* 
//************* CHANNEL GESTURE MAPPING
//************* 
//************* CH_GES_1 : on R R D, off L L D
//************* CH_GES_2 : on R D D, off L D D
//************* CH_GES_3 : on R U U, off L U U
//************* CH_GES_LOOP_1 : on/off R L L
//************* CH_GES_LOOP_2 : on/off L R R
//************* 
//************* CHAN_6 is speed button in E011 or H36 stock tx

#ifndef USE_STOCK_TX

#ifdef ENABLE_ARMING

#define LEVELMODE CHAN_6
#define RACEMODE  CH_GES_2
#define HORIZON   CH_GES_3
#define RATES CH_GES_LOOP_1
#define LEDS_ON CH_GES_LOOP_2

#endif

#ifndef ENABLE_ARMING

#define LEVELMODE CH_GES_1
#define RACEMODE  CH_GES_2
#define HORIZON   CH_GES_3
#define RATES CH_GES_LOOP_1
#define LEDS_ON CH_GES_LOOP_2

#endif
#endif

#ifdef USE_STOCK_TX

#ifdef ENABLE_ARMING

#define LEVELMODE CH_RLL_TRIM
#define RACEMODE  CH_GES_2
#define HORIZON   CH_GES_3
#define RATES CH_GES_LOOP_1
#define LEDS_ON CH_GES_LOOP_2

#endif

#ifndef ENABLE_ARMING

#define LEVELMODE CH_GES_1
#define RACEMODE  CH_GES_2
#define HORIZON   CH_GES_3
#define RATES CH_GES_LOOP_1
#define LEDS_ON CH_GES_LOOP_2

#endif
#endif

#define PIDPROFILE CHAN_9

// *************switch for fpv / other, requires fet
// *************comment out to disable
//#define FPV_ON CHAN_ON

// *************enable buzzer functionality
// *************external buzzer requires pin assignment in hardware.h before defining below
// *************change channel assignment from CHAN_OFF to a numbered aux switch if you want switch control
// *************if no channel is assigned but buzzer is set to CHAN_ON - buzzer will activate on LVC and FAILSAFE.
//#define BUZZER_ENABLE CHAN_OFF

// *************start in level mode for toy tx.
//#define AUX1_START_ON

// *************automatically remove center bias in toy tx ( needs throttle off for 1 second )
#define STOCK_TX_AUTOCENTER



//**********************************************************************************************************************
//***********************************************VOLTAGE SETTINGS*******************************************************

// ************* Raises pids automatically as battery voltage drops in flight.
#define PID_VOLTAGE_COMPENSATION
#define LEVELMODE_PID_ATTENUATION 0.90f  //used to prevent oscillations in angle modes with pid_voltage_compensation enabled due to high pids

// *************compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// *************calculate above factor automatically
#define AUTO_VDROP_FACTOR

// *************lower throttle when battery below threshold - forced landing low voltage cutoff
//#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0

// *************do not start software if battery is too low
// *************flashes 2 times repeatedly at startup
//#define STOP_LOWBATTERY

// *************voltage to start warning led blinking
#ifdef LIPO_HV
#define VBATTLOW 3.6
#endif
#ifndef LIPO_HV
#define VBATTLOW 3.5
#endif

// *************voltage hysteresis in volts
#define HYST 0.10

// *************automatic voltage telemetry correction/calibration factor - change the values below if voltage telemetry is inaccurate
#define ACTUAL_BATTERY_VOLTAGE 4.20
#define REPORTED_TELEMETRY_VOLTAGE 4.20



//**********************************************************************************************************************
//***********************************************FILTER SETTINGS********************************************************

// *************Select the appropriate filtering set for your craft's gyro, D-term, and motor output or select CUSTOM_FILTERING to pick your own values.  
// *************If your throttle does not want to drop crisply and quickly when you lower the throttle stick, then move to a stronger filter set

//#define WEAK_FILTERING
#define STRONG_FILTERING
//#define VERY_STRONG_FILTERING
//#define CUSTOM_FILTERING


#ifdef CUSTOM_FILTERING
// *************gyro low pass filter ( iir )
// *************set only one below - kalman, 1st order, or second order - and adjust frequency
//**************ABOVE 100 ADJUST IN INCRIMENTS OF 20, BELOW 100 ADJUST IN INCRIMENTS OF 10
#define SOFT_KALMAN_GYRO KAL1_HZ_90
//#define SOFT_LPF_1ST_HZ 80
//#define SOFT_LPF_2ND_HZ 80

// *************D term low pass filter type - set only one below and adjust frequency if adjustable filter is used
// *************1st order adjustable, second order adjustable, or 3rd order fixed (non adjustable)
//#define DTERM_LPF_1ST_HZ 100
#define  DTERM_LPF_2ND_HZ 100

// *************enable motor output filter - select and adjust frequency
//#define MOTOR_FILTER2_ALPHA MFILT1_HZ_90
#define MOTOR_KAL KAL1_HZ_70
#endif



//**********************************************************************************************************************
//***********************************************MOTOR OUTPUT SETTINGS**************************************************

// *************pwm frequency for motor control
// *************a higher frequency makes the motors more linear
// *************in Hz
#define PWMFREQ 32000

// *************motor curve to use - select one
// *************the pwm frequency has to be set independently
#define MOTOR_CURVE_NONE
//#define MOTOR_CURVE_6MM_490HZ
//#define MOTOR_CURVE_85MM_8KHZ
//#define MOTOR_CURVE_85MM_32KHZ
//#define BOLDCLASH_716MM_8K
//#define BOLDCLASH_716MM_24K

// *************clip feedforward attempts to resolve issues that occur near full throttle
//#define CLIP_FF

// *************torque boost is a highly eperimental feature.  it is a lpf D term on motor outputs that will accelerate the response
// *************of the motors when the command to the motors is changing by increasing or decreasing the voltage thats sent.  It differs
// *************from throttle transient compensation in that it acts on all motor commands - not just throttle changes.  this feature
// *************is very noise sensative so D term specifically has to be lowered and gyro/d filtering may need to be increased.
// *************reccomendation right now is to leave boost at or below 2, drop your p gains a few points, then cut your D in half and 
// *************retune it back up to where it feels good.  I'm finding about 60 to 65% of my previous D value seems to work.
//#define TORQUE_BOOST 0.5

// *************makes throttle feel more poppy - can intensify small throttle imbalances visible in FPV if factor is set too high
//#define THROTTLE_TRANSIENT_COMPENSATION 
#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 4.0 
 
// *************throttle angle compensation in level mode
//#define AUTO_THROTTLE

// *************mix lower throttle reduces thrust imbalances by reducing throttle proportionally to the adjustable reduction percent
// *************mix increase throttle increases the authority of the pid controller at lowest throttle values like airmode when combined with idle up
// *************mix3 has a stronger effect and works better with brushless
#define MIX_LOWER_THROTTLE
#define MIX_THROTTLE_REDUCTION_PERCENT 10
//#define MIX_INCREASE_THROTTLE

//#define MIX_LOWER_THROTTLE_3
#define MIX_INCREASE_THROTTLE_3
//Currently eperimenting with the value 1.0f below for whoop format.  Default was previously .2f and should remain .2f
//for anything other than a whoop.  The value 1.0f gives "airmode" 100% authority over throttle and is AWESOME on a whoop for locked in dives!!
#define MIX_THROTTLE_INCREASE_MAX 0.2f

// *************invert yaw pid for "PROPS OUT" configuration
//#define INVERT_YAW_PID

//**************joelucid's yaw fix
#define YAW_FIX

//**************joelucid's transient windup protection.  Removes roll and pitch bounce back after flips
#define TRANSIENT_WINDUP_PROTECTION



//**********************************************************************************************************************
//***********************************************ADDITIONAL FEATURES****************************************************

// *************lost quad beeps using motors (30 sec timeout) - pulses motors after timeout period to help find a lost model
//#define MOTOR_BEEPS

// *************0 - 7 - power for telemetry
#define TX_POWER 7

// *************Flash saving features
//#define DISABLE_GESTURES2

// *************led brightness in-flight ( solid lights only)
// *************0- 15 range
#define LED_BRIGHTNESS 15

// *************Comment out to disable pid tuning gestures
#define PID_GESTURE_TUNING
#define COMBINE_PITCH_ROLL_PID_TUNING

// *************flash save method
// *************flash_save 1: pids + accel calibration
// *************flash_save 2: accel calibration to option bytes
#define FLASH_SAVE1
//#define FLASH_SAVE2

// *************enable inverted flight code ( brushless only )
//#define INVERTED_ENABLE
//#define FN_INVERTED CH_OFF //for brushless only

// *************SPECIAL TEST MODE TO CHECK TRANSMITTER STICK THROWS
// *************This define will allow you to check if your radio is reaching 100% throws entering <RIGHT-RIGHT-DOWN> gesture
// ************* will disable throttle and will rapid blink the led when sticks are moved to 100% throws
// *************entering <LEFT-LEFT-DOWN> will return the quad to normal operation.
//#define STICK_TRAVEL_CHECK





//#############################################################################################################################
//#############################################################################################################################
// debug / other things
// this should not be usually changed
//#############################################################################################################################
//#############################################################################################################################

//enables use of stick accelerator and stick transition for d term lpf 1 & 2
#define ADVANCED_PID_CONTROLLER

//Throttle must drop below this value if arming feature is enabled for arming to take place.  MIX_INCREASE_THROTTLE_3 if enabled
//will also not activate on the ground untill this threshold is passed during takeoff for safety and better staging behavior.
#define THROTTLE_SAFETY .10f

// level mode "manual" trims ( in degrees)
// pitch positive forward
// roll positive right
#define TRIM_PITCH 0.0
#define TRIM_ROLL 0.0

// max rate used by level pid ( limit )
#define LEVEL_MAX_RATE 230

// limit minimum motor output to a value (0.0 - 1.0)
#define MOTOR_MIN_ENABLE
#define MOTOR_MIN_VALUE 0.05


#ifdef WEAK_FILTERING
#define SOFT_KALMAN_GYRO KAL1_HZ_90
#define  DTERM_LPF_2ND_HZ 100
#define MOTOR_FILTER2_ALPHA MFILT1_HZ_90
#endif

#ifdef STRONG_FILTERING
#define SOFT_KALMAN_GYRO KAL1_HZ_80
#define  DTERM_LPF_2ND_HZ 90
#define MOTOR_FILTER2_ALPHA MFILT1_HZ_80
#endif

#ifdef VERY_STRONG_FILTERING
#define SOFT_KALMAN_GYRO KAL1_HZ_70
#define  DTERM_LPF_2ND_HZ 80
#define MOTOR_FILTER2_ALPHA MFILT1_HZ_70
#endif

#define GYRO_LOW_PASS_FILTER 0

#define DISABLE_FLIP_SEQUENCER
#define STARTFLIP CHAN_OFF

// disable motors for testing
//#define NOMOTORS

// throttle direct to motors for thrust measure
// #define MOTORS_TO_THROTTLE

// throttle direct to motors for thrust measure as a flight mode
//#define MOTORS_TO_THROTTLE_MODE MULTI_CHAN_8

// loop time in uS
// this affects soft gyro lpf frequency if used
#define LOOPTIME 1000

// failsafe time in uS
#define FAILSAFETIME 1000000  // one second

// debug things ( debug struct and other)
//#define DEBUG

// rxdebug structure
//#define RXDEBUG

// enable motors if pitch / roll controls off center (at zero throttle)
// possible values: 0 / 1
// use in acro build only
#define ENABLESTIX 0
#define ENABLESTIX_TRESHOLD 0.3
#define ENABLESTIX_TIMEOUT 1e6

// overclock to 64Mhz

//#define ENABLE_OVERCLOCK

#pragma diag_warning 1035 , 177 , 4017
#pragma diag_error 260

//--fpmode=fast

// define logic - do not change
///////////////

// used for pwm calculations
#ifdef ENABLE_OVERCLOCK
#define SYS_CLOCK_FREQ_HZ 64000000
#else
#define SYS_CLOCK_FREQ_HZ 48000000
#endif

#ifdef MOTOR_BEEPS
#ifdef USE_ESC_DRIVER
#warning "MOTOR BEEPS_WORKS WITH BRUSHED MOTORS ONLY"
#endif
#endif

// for the ble beacon to work after in-flight reset
#ifdef RX_BAYANG_PROTOCOL_BLE_BEACON
#undef STOP_LOWBATTERY
#endif

// gcc warnings in main.c

//Hardware target defines moved from hardware.h so that board selection of bwhoop or e011 can be performed in config.h file

#ifdef BWHOOP
//LEDS
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED2PIN GPIO_Pin_3
#define LED2PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_90_CW

// SPI PINS DEFINITONS & RADIO
#ifdef RX_SBUS
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOF
#define RADIO_XN297L
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.001364
#define ADC_REF 1.17857f

// MOTOR PINS
#define MOTOR0_PIN_PB1 // motor 0 back-left
#define MOTOR1_PIN_PA4 // motor 1 front-left
#define MOTOR2_PIN_PA6 // motor 2 back-right
#define MOTOR3_PIN_PA7 // motor 3 front-right
#endif

#ifdef E011
//LEDS
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED2PIN GPIO_Pin_3
#define LED2PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_90_CW
#define SOFTI2C_PUSHPULL_CLK

// SPI PINS DEFINITONS & RADIO
#ifdef RX_SBUS
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOF
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOA
#define RADIO_XN297L
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.001364
#define ADC_REF 1.17857f

// Assingment of pin to motor
#define MOTOR0_PIN_PA6 // motor 0 back-left
#define MOTOR1_PIN_PA4 // motor 1 front-left
#define MOTOR2_PIN_PB1 // motor 2 back-right
#define MOTOR3_PIN_PA7 // motor 3 front-right
#endif

#ifdef H8mini_blue_board
//LEDS
#define LED_NUMBER 1
#define LED1PIN GPIO_Pin_1
#define LED1PORT GPIOF
#define LED2PIN GPIO_Pin_3
#define LED2PORT GPIOA

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
#define SOFTI2C_PUSHPULL_CLK
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x78 // common h8 gyro
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_180

// SPI PINS DEFINITONS & RADIO
#ifdef RX_SBUS
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_1
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_2
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_3
#define SPI_SS_PORT GPIOA
#define RADIO_XN297L
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.001364
#define ADC_REF 1.17857f

// Assingment of pin to motor
#define MOTOR0_PIN_PA6 // motor 0 back-left
#define MOTOR1_PIN_PA4 // motor 1 front-left
#define MOTOR2_PIN_PB1 // motor 2 back-right
#define MOTOR3_PIN_PA7 // motor 3 front-right
#endif

#ifdef Alienwhoop_ZERO
//LEDS
#define LED_NUMBER 1
#define LED1PIN GPIO_Pin_0
#define LED1PORT GPIOF
#define LED2PIN GPIO_Pin_0
#define LED2PORT GPIOA

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
//#define SOFTI2C_GYRO_ADDRESS 0x69
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x78
#define GYRO_ID_4 0x72 
#define SENSOR_ROTATE_90_CCW

// SPI PINS DEFINITONS & RADIO
#ifdef RX_SBUS
#define SERIAL_RX_PIN GPIO_Pin_3
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource3
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_3
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_2
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_1
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#define RADIO_XN297L
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.002423
#define ADC_REF 1.0f


// MOTOR PINS
// MOTOR PINS
#define MOTOR0_PIN_PA7
//#define MOTOR1_PIN_PA4  //2nd Draft prototype patch
//#define MOTOR2_PIN_PB1  //2nd Draft prototype patch
#define MOTOR1_PIN_PB1
#define MOTOR2_PIN_PA4
#define MOTOR3_PIN_PA6
#endif


//**********************************************************************************************************************
//***********************************************BETA TESTING ON STICK GESTURE******************************************
// *************DEFINE ONLY ONE OPTION FROM THIS SECTION!!!
// *************This is a new section that will allow certain beta testing features to be activated by the stick gesture
// *************auxillary channel.  Even when defined - the quad will power up with these features off.  To activate -  
// *************use the following stick gesture on the pitch/roll stick RIGHT-RIGHT-DOWN (leds will blink). To deactivate - 
// *************stick gesture LEFT-LEFT-DOWN.  Please test the features you are interested in below and give feedback!!!

