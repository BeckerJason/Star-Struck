void DriverControlTestVoid()
{
	if(vexRT[Ch3]> 10 || vexRT[Ch4]||vexRT[Ch1]  > 10 || vexRT[Ch3]< -10 || vexRT[Ch4] ||vexRT[Ch1] < -10) //JOYSTICK DEADBAND
		{
			motor[LM] = vexRT[Ch3]+ vexRT[Ch4];
			motor[L1] = vexRT[Ch3]+ vexRT[Ch4];
			motor[L2] = vexRT[Ch3]+ vexRT[Ch4];
			motor[RM] = vexRT[Ch3]-vexRT[Ch4];
			motor[R1] = vexRT[Ch3]- vexRT[Ch4];
			motor[R2] = vexRT[Ch3]- vexRT[Ch4];
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

		///PUNCHER DEBUG//////////
		if(vexRT[Btn8D]==1)	SensorValue[puncher]=1;
		else	SensorValue[puncher]=0;
		//////////////////////////////////////
		//CLAW
		if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
		else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
		///////////////
		wait1Msec(20);


}
