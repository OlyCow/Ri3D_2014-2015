#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor_L,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor_R,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor_pickup,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor_dump,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motor_lift,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motor_spare,   tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo_dump,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

#include "includes.h"

task main()
{
	initializeGlobalVariables();

	int power_L = 0;
	int power_R = 0;
	int power_lift = 0;
	int power_pickup = 0;
	int power_dump = 0;
	const int dump_motor_power = 100;

	const int servo_dump_open = 0;
	const int servo_dump_closed = 255;
	int servo_dump_pos = servo_dump_open;

	bool isPickupOn = false;

	Joystick_WaitForStart();

	while (true) {
		Joystick_UpdateData();

		power_L = Joystick_GenericInput(JOYSTICK_L, AXIS_Y, CONTROLLER_1);
		power_R = Joystick_GenericInput(JOYSTICK_R, AXIS_Y, CONTROLLER_1);
		power_lift = Joystick_GenericInput(JOYSTICK_L, AXIS_Y, CONTROLLER_2);
		if (Joystick_ButtonReleased(BUTTON_A, CONTROLLER_1)) {
			isPickupOn = !isPickupOn;
		}
		if (isPickupOn) {
			power_pickup = 100;
		} else {
			power_pickup = 0;
		}
		if (Joystick_Direction(DIRECTION_F, CONTROLLER_1)) {
			power_dump = dump_motor_power;
		} else if (Joystick_Direction(DIRECTION_B, CONTROLLER_1)) {
			power_dump = -dump_motor_power;
		}

		Motor_SetPower(power_L, motor_L);
		Motor_SetPower(power_R, motor_R);
		Motor_SetPower(power_lift, motor_lift);
		Motor_SetPower(power_pickup, motor_pickup);
		Motor_SetPower(power_dump, motor_dump);

		Servo_SetPosition(servo_dump, servo_dump_pos);
	}
}
