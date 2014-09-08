#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor_L,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor_R,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor_pickup,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor_dump,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motor_lift_A,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motor_lift_B,  tmotorTetrix, openLoop)

#include "includes.h"

task main()
{
	const int DELAY_SETTLE_ROBOT	= 200;
	const int DELAY_ESCAPE_RAMP		= 1000;
	const int DELAY_FACE_CENTER		= 800;
	const int DELAY_APPROACH_CENTER	= 1400;
	const int DELAY_TANGENT_CENTER	= 1400;
	const int DELAY_CIRCLES			= 10 *1000;

	initializeGlobalVariables();
	Joystick_WaitForStart();

	// Drive forwards off of ramp
	Motor_SetPower(100, motor_L);
	Motor_SetPower(100, motor_R);
	Time_Wait(DELAY_ESCAPE_RAMP);
	Motor_SetPower(0, motor_L);
	Motor_SetPower(0, motor_R);
	Time_Wait(DELAY_SETTLE_ROBOT);
	
	// Turn towards center goal
	Motor_SetPower(100, motor_L);
	Motor_SetPower(20, motor_R);
	Time_Wait(DELAY_FACE_CENTER);
	Motor_SetPower(0, motor_L);
	Motor_SetPower(0, motor_R);
	Time_Wait(DELAY_SETTLE_ROBOT);
	
	// Drive towards center goal
	Motor_SetPower(100, motor_L);
	Motor_SetPower(100, motor_R);
	Time_Wait(DELAY_APPROACH_CENTER);
	Motor_SetPower(0, motor_L);
	Motor_SetPower(0, motor_R);
	Time_Wait(DELAY_SETTLE_ROBOT);
	
	// Turn to be tangent to circle center goal
	Motor_SetPower(-100, motor_L);
	Motor_SetPower(100, motor_R);
	Time_Wait(DELAY_TANGENT_CENTER);
	Motor_SetPower(0, motor_L);
	Motor_SetPower(0, motor_R);
	Time_Wait(DELAY_SETTLE_ROBOT);
	
	// Go in circles.
	Motor_SetPower(100, motor_L);
	Motor_SetPower(-60, motor_R);
	Time_Wait(DELAY_CIRCLES);
	Motor_SetPower(0, motor_L);
	Motor_SetPower(0, motor_R);
	Time_Wait(DELAY_SETTLE_ROBOT);
}
