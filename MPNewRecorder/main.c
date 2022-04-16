#pragma config(Sensor, in7,    PGyro,          sensorGyro)
#pragma config(Sensor, in8,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  encArm,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  encPDrive,      sensorQuadEncoder) //secondary controller
#pragma config(Sensor, dgtl8,  encDrive,       sensorQuadEncoder)
#pragma config(Sensor, dgtl10, pP,   sensorDigitalOut)//puppet piston
#pragma config(Sensor, dgtl11, pis1,           sensorDigitalOut)//main robot claw
#pragma config(Sensor, dgtl12, pis2,           sensorDigitalOut) //on side of main robot
#pragma config(Motor,  port1,           rightFrontM,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightP,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           armLeftP,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           armRightM,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftFrontM,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftBackM,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armLeftM,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           armRightP,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftP,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightBackM,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma DebuggerWindows("debugStream")
#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

//DECLARE GLOBAL VARIABLES FOR FUNCTION'S USE
#define DEBUG 1
int GyroValuePuppet;
int GyroValueMaster;



int alliance = 4;
int autonomousN = 5;
task MasterTask();
task PuppetTask();
void DebugMaster();
void DebugPuppet();
#include "vex.c"

//int condition;
int MoveCounterMaster = 0, MoveCounterPuppet=0;
int FailSafeEngagedM = 0, FailSafeEngagedP;



#include "BasicMovementsMaster.c"
#include "BasicMovementsPuppet.c"
#include "SendDataTask.c"
//#include "DebugCode.c"
#include "autovoids.c"
//MASTER AND PUPPET AUTONOMOUS STAGES
int autoStage=1;
//INPORT MASTER AUTO FILES
//IMPORT PUPPET AUTO FILES(ADD NEW AUTO ROUTINES AT THE BEGINNING)
#include "autoTasks.c"
#include "BlueAutoM1.c"
#include "DebugMaster.c"//
#include "DebugPuppet.c"

//#include "RecorderNewer.c"//~~~~~~~~~~

void pre_auton()
{
	bStopTasksBetweenModes = false;
#include "PreAuto.c"
}

task autonomous()
{
	autoStage=1;
	//startTask(SendData);
	stopTask(usercontrol);
	//startTask(PuppetTask);
	//startTask(MasterTask);
//#include"RECORDERAUTO.c";
	//while(SetDegreesMaster(0)){
	//	GyroValuePuppet=SensorValue[PGyro];
	//	GyroValueMaster = SensorValue[Gyro];
	//}



}

task usercontrol()
{
clearDebugStream();
int Time=25;
//startTask(Atlas);
#include "RecorderFast.c";

	//startTask(SendData);
	//#include "DriverControl.c"

}