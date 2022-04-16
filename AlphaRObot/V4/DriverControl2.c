#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    leftLine,       sensorLineFollower)
#pragma config(Sensor, in3,    midLine,        sensorLineFollower)
#pragma config(Sensor, in4,    rightLine,      sensorLineFollower)
#pragma config(Sensor, in5,    punchIR,        sensorAnalog)
#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  ArmStop,        sensorTouch)
#pragma config(Sensor, dgtl3,  LeftEnc,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  clawL,          sensorDigitalOut)
#pragma config(Sensor, dgtl6,  clawR,          sensorDigitalOut)
#pragma config(Sensor, dgtl8,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl11, ArmEnc,         sensorQuadEncoder)
#pragma config(Motor,  port1,           LM,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftArmY,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           R1,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightArmM,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           R2,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           L2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftArmM,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           L1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightArmY,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RM,            tmotorVex393_HBridge, openLoop)

#pragma DebuggerWindows("debugStream")

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)
#define DEBUG 1
bool firstRun = false;				//PUNCHER TIMING
int pistonActive = 0, pistonCount=0;
///////////////////////////BEGIN INCLUDED FILES
int alliance = 4;
int autonomousN = 5;
//int stage = 1;
int MoveCounter = 0;
//int FailSafeEngaged = 0;
//float LastError=0;
#include "vex.c"
#include "BasicMovements.c"
#include "autovoids.c"
#include "DrivingCode.c"
*/

KillALL();
break;

while (1)
{
	//#include"AlphaRecorder.c"
	//LCD display data
//#include "LCD.c"
	//AlphaRecorder(); //Comment this out to prevent recorder from running
	//////////////////////
	if(vexRT[Ch3]> 10 || vexRT[Ch4]||vexRT[Ch1]  > 10 || vexRT[Ch3]< -10 || vexRT[Ch4] ||vexRT[Ch1] < -10) //JOYSTICK DEADBAND
	{
		motor[LM] = vexRT[Ch3]+ vexRT[Ch4];
		motor[L1] = vexRT[Ch3]+ vexRT[Ch4];
		motor[L2] = vexRT[Ch3]+ vexRT[Ch4];
		motor[RM] = vexRT[Ch3]-vexRT[Ch4];
		motor[R1] = vexRT[Ch3]- vexRT[Ch4];
		motor[R2] = vexRT[Ch3]- vexRT[Ch4];
	}
	else if(vexRT[Btn7L]==1) //JOYSTICK DEADBAND
	{
		motor[LM] = -70;
		motor[L1] = -70;
		motor[L2] = -70;
		motor[RM] =70;
		motor[R1] = 70;
		motor[R2] = 70;
	}
	else if(vexRT[Btn7R]==1) //JOYSTICK DEADBAND
	{
		motor[LM] = 70;
		motor[L1] = 70;
		motor[L2] = 70;
		motor[RM] =-70;
		motor[R1] = -70;
		motor[R2] = -70;
	}
	else if(vexRT[Btn7U]==1) //JOYSTICK DEADBAND
	{
		motor[LM] = 70;
		motor[L1] = 70;
		motor[L2] = 70;
		motor[RM] =70;
		motor[R1] =70;
		motor[R2] =70;
	}
	else	if(vexRT[Btn7D]==1) //JOYSTICK DEADBAND
	{
		motor[LM] = -70;
		motor[L1] = -70;
		motor[L2] = -70;
		motor[RM] =-70;
		motor[R1] =-70;
		motor[R2] =-70;
	}
	else
	{
		motor[LM] = 0;
		motor[L1] = 0;
		motor[L2] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		motor[R2] = 0;

	}

	if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
{
		motor[leftArmM] = 127;
		motor[leftArmY] = 127;
		motor[rightArmM] = 127;
		motor[rightArmY] = 127;
	}
	else	if(vexRT[Btn5D] == 1)       	//If button 5D is pressed...
{
		motor[leftArmM] = -127;
		motor[leftArmY] = -127;
		motor[rightArmM] = -127;
		motor[rightArmY] = -127;
	}
		else	if(vexRT[Ch2]>10||vexRT[Ch2]<10)       	//If button is pressed...
{
		motor[leftArmM] =vexRT[Ch2];
		motor[leftArmY] = vexRT[Ch2];
		motor[rightArmM] =vexRT[Ch2];
		motor[rightArmY] =vexRT[Ch2];
	}
	else                      		//Else (neither button is pressed)...
	{
		motor[leftArmM] = 0;
		motor[leftArmY] = 0;
		motor[rightArmM] = 0;
		motor[rightArmY] = 0;      	//...stop the arm.
	}

	///PUNCHER DEBUG//////////
	//if(vexRT[Btn8D]==1)	SensorValue[puncher]=1;
	//else	SensorValue[puncher]=0;
	//////////////////////////////////////
	//CLAW
	if(SensorValue[ArmStop]==1){SensorValue[clawR]=0;	SensorValue[clawL]=0;}
	else if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
	else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
	///////////////
	wait1Msec(20);
}
