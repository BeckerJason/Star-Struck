void DrivingCode(int ArmValue)
{//writeDebugStreamLine("(%d);",SensorValue[Gyro]);
	//writeDebugStreamLine("L (%d) R (%d);",SensorValue[LeftEnc],SensorValue[RightEnc]);
	//writeDebugStreamLine("(%d);",SensorValue[RightEnc]);
	int Time=300;
	int EncoderI, EncoderF, EncoderValue, Direction, ArmI, ArmF;
	float GyroI, GyroF, GyroValue;

	if(vexRT[Btn7L]==1)
	{SensorValue[Gyro]=0;
		GyroI=GyroRecord();
		while(vexRT[Btn7L]==1)
		{
			int speed=70;                                       //SPEED HERE
			motor[LM] = -speed;
			motor[L1] = -speed;
			motor[L2] = -speed;
			motor[RM] =  speed;
			motor[R1] =  speed;
			motor[R2] =  speed;
		}
		GyroF=GyroRecord();
		GyroValue=DifferenceGyro(GyroI, GyroF);
		TurnBreak(100,70);
		writeDebugStreamLine("TurnDegree(%d, 70);", -GyroValue/8);   //SET SPEED
		writeDebugStreamLine("TurnBreak(100, %d);", 70);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn7R]==1)
	{SensorValue[Gyro]=0;
		GyroI=GyroRecord();
		int speed=70;
		while(vexRT[Btn7R]==1)
		{
			motor[LM] =  speed;
			motor[L1] =  speed;
			motor[L2] =  speed;
			motor[RM] = -speed;
			motor[R1] = -speed;
			motor[R2] = -speed;
		}
		GyroF=GyroRecord();
		GyroValue=DifferenceGyro(GyroI, GyroF);
		TurnBreak(100, -70);
		writeDebugStreamLine("TurnDegree(%d, 70);", GyroValue/8);   //SET SPEED
		writeDebugStreamLine("TurnBreak(100,%d);", -70);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn7U]==1)
	{
		Direction=1;   //Forward
		EncoderI=DistRecord(,);
		int speed=70;												//SET SPEED
		SensorValue[Gyro]=0;
		while (vexRT[Btn7U]==1)   //While the button is pressed
		{if (SensorValue[Gyro]>0){
				motor[LM] = speed;
				motor[L1] = speed;
				motor[L2] = speed;
				motor[RM] = speed-15;
				motor[R1] = speed-15;
				motor[R2] = speed-15;}
			else if (SensorValue[Gyro]<0){
				motor[LM] = speed-15;
				motor[L1] = speed-15;
				motor[L2] = speed-15;
				motor[RM] = speed;
				motor[R1] = speed;
				motor[R2] = speed;}
			else{
				motor[LM] = speed;
				motor[L1] = speed;
				motor[L2] = speed;
				motor[RM] = speed;
				motor[R1] = speed;
				motor[R2] = speed;}


		}
		EncoderF=DistRecord();
		EncoderValue=Difference(EncoderI, EncoderF);
		Break(100,speed); 			 		//Stop the robot...   thank you Norrin
		writeDebugStreamLine("Dist( %d, %d, %d, 0);", EncoderValue, Direction, 70 /*,TimeOut*/);   //SET SPEED
		writeDebugStreamLine("Break(100,%d);", speed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn7D]==1)
	{
		Direction=0;   //Backward
		EncoderI=DistRecord(,);
		int speed=70;												//SET SPEED
		SensorValue[Gyro]=0;
		while (vexRT[Btn7D]==1)   //While the button is pressed
		{if (SensorValue[Gyro]>0){
				motor[LM] = -speed;
				motor[L1] = -speed;
				motor[L2] =-speed;
				motor[RM] = -speed-15;
				motor[R1] = -speed-15;
				motor[R2] = -speed-15;}
			else if (SensorValue[Gyro]<0){
				motor[LM] = -speed-15;
				motor[L1] = -speed-15;
				motor[L2] = -speed-15;
				motor[RM] = -speed;
				motor[R1] = -speed;
				motor[R2] = -speed;}
			else{
				motor[LM] = -speed;
				motor[L1] = -speed;
				motor[L2] = -speed;
				motor[RM] = -speed;
				motor[R1] = -speed;
				motor[R2] = -speed;}
		}
		EncoderF=DistRecord();
		EncoderValue=Difference(EncoderI, EncoderF);
		Break(100,-speed); 			 		//Stop the robot...   thank you Norrin
		writeDebugStreamLine("Dist( %d, %d, %d, %d);", EncoderValue, Direction, speed ,TimeOut);   //SET SPEED
		writeDebugStreamLine("Break(100,%d);", -speed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else	if(vexRT[Ch3]>=10) //JOYSTICK DEADBAND
	{
		Direction=1;   //Forward
		EncoderI=DistRecord();
		int speed=-70; 							//SET SPEED
		SensorValue[Gyro]=0;
		while(vexRT[Ch3]>=10)
		{if (SensorValue[Gyro]>0){
				motor[LM] = speed;
				motor[L1] = speed;
				motor[L2] = speed;
				motor[RM] = speed-10;
				motor[R1] = speed-10;
				motor[R2] = speed-10;}
			else if (SensorValue[Gyro]<0){
				motor[LM] = speed-10;
				motor[L1] = speed-10;
				motor[L2] = speed-10;
				motor[RM] = speed;
				motor[R1] = speed;
				motor[R2] = speed;}
			else{
				motor[LM] = speed;
				motor[L1] = speed;
				motor[L2] = speed;
				motor[RM] = speed;
				motor[R1] = speed;
				motor[R2] = speed;}

		}                  //Stop the robot...   thank you Norrin
		EncoderF=DistRecord();
		EncoderValue=Difference(EncoderI, EncoderF);
		Break(100,-speed);
		writeDebugStreamLine("Dist( %d, %d, %d, 0);", EncoderValue, Direction, 70);   //SET SPEED
		writeDebugStreamLine("Break(100,%d);", -speed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn8L]==1)
	{int turnspeed=70;							//SET TURN SPEED
		TurnDegree(-90, turnspeed, TimeOut);
		TurnBreak(50,turnspeed);
		writeDebugStreamLine("TurnDegree(-90, %d, %d);", turnspeed, TimeOut);
		writeDebugStreamLine("TurnBreak(50, %d);", turnspeed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn8R]==1)
	{int turnspeed=70;																//SET TURN SPEED
		TurnDegree(90, turnspeed, TimeOut);
		TurnBreak(50,-turnspeed);
		writeDebugStreamLine("TurnDegree(90, %d, %d);", turnspeed, TimeOut);
		writeDebugStreamLine("TurnBreak(50, %d);", -turnspeed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn8U]==1)
	{int turnspeed=70;																//SET TURN SPEED
		TurnDegree(-135, turnspeed, TimeOut);
		TurnBreak(50,turnspeed);
		writeDebugStreamLine("TurnDegree(-135, %d, %d);", turnspeed, TimeOut);
		writeDebugStreamLine("TurnBreak(50, %d);", turnspeed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn8D]==1)
	{int turnspeed=70;																//SET TURN SPEED
		TurnDegree(35, turnspeed, TimeOut);
		TurnBreak(50,-turnspeed);
		writeDebugStreamLine("TurnDegree(45, %d, %d);", turnspeed, TimeOut);
		writeDebugStreamLine("TurnBreak(50, %d);", -turnspeed);
		writeDebugStreamLine("wait1Msec(%d);",Time);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
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
	int armspeed=-90;// ARM SPEED HERE
	if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
	{SensorValue[ArmEnc]=0;
		ArmI=ArmRecord();
		while(vexRT[Btn5U] == 1)
		{
			motor[leftArmM] = -armspeed;
			motor[leftArmY] = -armspeed;
			motor[rightArmM] = -armspeed;
			motor[rightArmY] = -armspeed;
		}
		ArmF=ArmRecord();
		EncoderValue=Difference(ArmI, ArmF);
		writeDebugStreamLine("ArmPosition(%d, 1, %d, %d);",EncoderValue, 90,TimeOut);
		writeDebugStreamLine("ArmRun(%d);",ArmValue);
		writeDebugStreamLine("wait1Msec(%d);",Time);
	}
	else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
	{SensorValue[ArmEnc]=0;
		ArmI=ArmRecord();
		while(vexRT[Btn5D] == 1)
		{
			motor[leftArmM] = armspeed/2;
			motor[leftArmY] = armspeed/2;
			motor[rightArmM] = armspeed/2;
			motor[rightArmY] = armspeed/2;

		}
		ArmF=ArmRecord();
		EncoderValue=Difference(ArmI, ArmF);
		writeDebugStreamLine("ArmPosition(%d, 0, %d, 0);",EncoderValue, 45);
		//writeDebugStreamLine("ArmRun(%d);",ArmValue);
		writeDebugStreamLine("wait1Msec(%d);",Time);
	}
	else                      		//Else (neither button is pressed)...
	{
		ArmRun(ArmValue);     	//...hold the arm.
	}

	///PUNCHER DEBUG//////////
	//if(vexRT[Btn8D]==1){	SensorValue[puncher]=1;}
	//else	{SensorValue[puncher]=0;}
	//////////////////////////////////////
	//CLAW

	//	if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
	//else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
	///////////////
	wait1Msec(20);
	//writeDebugStream("wait1Msec(1000);

}
