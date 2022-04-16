#pragma config(Sensor, in1,    armpot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  clawswitch,     sensorTouch)
#pragma config(Sensor, dgtl2,  armswitch,      sensorTouch)
#pragma config(Sensor, dgtl3,  lencoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rencoder,       sensorQuadEncoder)
#pragma config(Motor,  port1,           ltl,           tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           ltm,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           ltt,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           clawl,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           ld,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           rd,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           clawr,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           rtm,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           rtt,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          rtl,           tmotorVex393HighSpeed_HBridge, openLoop)
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

#include "basicmovements.c"
void resetencoders(){SensorValue[rencoder]=0; SensorValue[lencoder]=0;}

void pre_auton()
{
  bStopTasksBetweenModes = true;

}
task autonomous()
{
#include "auto.c"
}

task usercontrol()
{
	while(1==1)
	{
		if(vexRT[Ch3] > 10 || vexRT[Ch1] > 10 || vexRT[Ch3] < -10 || vexRT[Ch1] < -10) //JOYSTICK DEADBAND
		{
			motor[ld]=(vexRT[Ch1]+vexRT[Ch3]);
			motor[rd]=(vexRT[Ch1]-vexRT[Ch3]);
		}
		else						//else drive motors stop
		{
			motor[ld]=0;
			motor[rd]=0;
		}
		if (vexRT[Btn5U]==1&&SensorValue[armpot]>2000)//5U Arm Up
		{
			motor[ltl]=127;
			motor[ltm]=127;
			motor[ltt]=127;
			motor[rtl]=127;
			motor[rtm]=127;
			motor[rtt]=127;
		}
		else if (vexRT[Btn5D]==1&&SensorValue[armswitch]==0) //5D Arm Down
		{
			motor[ltl]=-127;
			motor[ltm]=-127;
			motor[ltt]=-127;
			motor[rtl]=-127;
			motor[rtm]=-127;
			motor[rtt]=-127;
		}
		else                //else tower motors stop
		{
			motor[ltl]=0;
			motor[ltm]=0;
			motor[ltt]=0;
			motor[rtl]=0;
			motor[rtm]=0;
			motor[rtt]=0;
		}
		if(vexRT[Btn6D]==1&&SensorValue[clawswitch]==0||SensorValue[armpot]<=2000&&SensorValue[clawswitch]==0)	//6D Claw open
		{
			motor[clawl]=127;
			motor[clawr]=127;
		}
		else if(vexRT[Btn6U]==1&SensorValue[armpot]>2000)	//6U Claw close
		{
			motor[clawl]=-90;
			motor[clawr]=-90;
		}
		else	//else claw motors stop
		{
			motor[clawl]=0;
			motor[clawr]=0;
		}
			if(vexRT[Btn7R]==1)	//6D Claw open
		{
		resetencoders();
		}
		if(vexRT[Btn7L]==1&SensorValue[armpot]>2000)	//6U Claw close
		{
			motor[clawl]=-127;
			motor[clawr]=-127;
		}
	}
}
