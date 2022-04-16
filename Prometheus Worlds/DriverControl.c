KillALL();
break;
while (1)
	{

		//LCD display data
	//#include "LCD.c"
	//////////////////////
		if(vexRT[Ch3] > 10 || vexRT[Ch4] > 10 || vexRT[Ch3] < -10 || vexRT[Ch4] < -10) //JOYSTICK DEADBAND
		{
			motor[LM] = vexRT[Ch3] + vexRT[Ch4];
			motor[L1] = vexRT[Ch3] + vexRT[Ch4];
			motor[L2] = vexRT[Ch3] + vexRT[Ch4];
			motor[RM] = vexRT[Ch3] - vexRT[Ch4];
			motor[R1] = vexRT[Ch3] - vexRT[Ch4];
			motor[R2] = vexRT[Ch3] - vexRT[Ch4];
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
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[leftArmM] = -127;
			motor[leftArmY] = -127;
			motor[rightArmM] = -127;
			motor[rightArmY] = -127;
		}
		/*else if (vexRT[Ch2] > 10 && SensorValue[ArmStop]==0)
		{
			wait1Msec(200);
			motor[leftArmM] = 0;
			motor[leftArmY] = 0;
			motor[rightArmM] = 0;
			motor[rightArmY] = 0;
			motor[leftArmM] = -10;
			motor[leftArmY] = -10;
			motor[rightArmM] = -10;
			motor[rightArmY] =-10;
		}*/
		else if(vexRT[Ch2] > 10 || vexRT[Ch2] < -10)
		{
			motor[leftArmM] = vexRT[Ch2];
			motor[leftArmY] = vexRT[Ch2];
			motor[rightArmM] = vexRT[Ch2];
			motor[rightArmY] = vexRT[Ch2];
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[leftArmM] = 0;
			motor[leftArmY] = 0;
			motor[rightArmM] = 0;
			motor[rightArmY] = 0;      	//...stop the arm.
		}
if (vexRT[Btn7U]==1){SensorValue[Trans]=1;}
else if(vexRT[Btn7D]==1){SensorValue[Trans]=0;}
		///PUNCHER DEBUG//////////
		//if(vexRT[Btn8D]==1)	SensorValue[puncher]=1;
		//else	SensorValue[puncher]=0;
		//////////////////////////////////////
	//CLAW
		//if(SensorValue[ArmStop]==0){SensorValue[clawR]=0;	SensorValue[clawL]=0;}
		//else if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
		//else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
if (SensorValue[ArmEnc]>550&&vexRT[Btn6D]==1){SensorValue[clawR]=0;	SensorValue[clawL]=0;}
		else if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
		else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
		wait1Msec(20);
}
