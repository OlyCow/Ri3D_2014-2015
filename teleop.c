#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  HTServo,  HTServo,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor_LA,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motor_LB,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor_RA,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motor_RB,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motor_pickup,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motor_lift_A,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motor_lift_B,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motor_lift_C,  tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_1,    servo7,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C2_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C2_6,    servo12,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_1,    servo13,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_2,    servo14,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_3,    servo15,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_4,    servo16,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    servo17,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo18,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_1,    servo19,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_2,    servo20,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_3,    servo21,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_4,    servo22,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_5,    servo23,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_6,    servo24,              tServoNone)

#include "includes.h"

task main()
{
	initializeGlobalVariables();
	Joystick_WaitForStart();

	while (true) {
	}
}
