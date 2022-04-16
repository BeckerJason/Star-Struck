KillALL();
break;

	//LCD display data
	#include "LCD.c"
	//////////////////////

int Y1 = 0, Y2 = 0, X1 = 0, threshold = 15;
float turn = 1;

while (1)
	{
		//DEBUGGING SECTION///
		//SetData();
		GyroValuePuppet=SensorValue[PGyro];
		GyroValueMaster = SensorValue[Gyro];
		if(vexRT[Btn8D]==1)
		{
			SensorValue[pis2]=1;
		}
		else
		{
			SensorValue[pis2]=0;
		}


	//First Robot Code////////////////////////////////////////
		if ( abs ( vexRT[Ch3] ) > threshold) { Y1 = vexRT[Ch3]; }
		else { Y1 = 0; }

		if ( abs ( vexRT[Ch4] ) > threshold){ X1 = vexRT[Ch4]; }
		else if(vexRT[Btn5D]==1) { X1	= -127/turn; }
		else if(vexRT[Btn6D]==1) { X1 = 127/turn;}
		else { X1 = 0; }


		if ( abs ( vexRT[Ch2] ) > threshold){Y2 = vexRT[Ch2];}
		else { Y2 = 0; }

		motor[rightFrontM] = Y1 - X1 * turn;
		motor[rightBackM] = Y1 - X1 * turn;
		motor[leftFrontM] = Y1 + X1 * turn;
		motor[leftBackM] = Y1 + X1 * turn;
		//Arm Power////////////////////////////////
		motor[armLeftM] = Y2;
		motor[armRightM] = Y2;

		if( vexRT[Btn5U] == 1 )
		{SensorValue[pis1] = 1;}
		else {SensorValue[pis1] = 0;}
		/////////////////////////////////////////////////////////

		//Robot 2///////////////////////////////////////////////
		//Drive Train//////////////////////////////////////////
		if(vexRT[Ch3Xmtr2] > 10 || vexRT[Ch3Xmtr2] < -10 || vexRT[Ch4Xmtr2] < -10 || vexRT[Ch4Xmtr2]>10)
		{
		motor[rightP] = vexRT[Ch3Xmtr2]- vexRT[Ch4Xmtr2];
		motor[leftP] = vexRT[Ch3Xmtr2] + vexRT[Ch4Xmtr2];
		}
		else
		{
			motor[rightP] = 0;
			motor[leftP] = 0;
		}
		//Arm Control/////////////////////////////////////////////
		if(vexRT[Ch2Xmtr2] > 10 || vexRT[Ch2Xmtr2] < -10)
		{
			motor[armLeftP] = vexRT[Ch2Xmtr2];
			motor[armRightP] = vexRT[Ch2Xmtr2];
		}
		else
		{
			motor[armLeftP] = 0;
			motor[armRightP] = 0;
		}
		//Piston Control//////////////////////////////////////////
		if(vexRT[Btn6UXmtr2] == 1)
		{SensorValue[pistonPuppet]=1;}
		else
		{SensorValue[pistonPuppet]=0;}
}
