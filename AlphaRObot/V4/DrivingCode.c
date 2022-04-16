void DrivingCode(int ArmValue)
{
int Time=1000;
int EncoderI, EncoderF, EncoderValue, Direction, ArmI, ArmF;
float GyroI, GyroF, GyroValue;
//AlphaRecorder(); //Comment this out to prevent recorder from running
/////////////////////
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
	writeDebugStreamLine("TurnDegree(%d, 70, 0);", -GyroValue/8);   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else if(vexRT[Btn7R]==1)
{SensorValue[Gyro]=0;
	GyroI=GyroRecord();
	while(vexRT[Btn7R]==1)
	{
		int speed=70;
		motor[LM] =  speed;
		motor[L1] =  speed;
		motor[L2] =  speed;
		motor[RM] = -speed;
		motor[R1] = -speed;
		motor[R2] = -speed;
	}
	GyroF=GyroRecord();
	GyroValue=DifferenceGyro(GyroI, GyroF);
	writeDebugStreamLine("TurnDegree(%d, 70, 0);", GyroValue/8);   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else if(vexRT[Btn7U]==1)
{
	Direction=1;   //Forward
	EncoderI=DistRecord(,);
	while (vexRT[Btn7U]==1)   //While the button is pressed
	{

		int speed=70;                                                             //SET SPEED
		motor[LM] = speed;
		motor[L1] = speed;
		motor[L2] = speed;
		motor[RM] = speed;
		motor[R1] = speed;
		motor[R2] = speed;
	}
	//Break();                   //Stop the robot...   thank you Norrin
	EncoderF=DistRecord();
	EncoderValue=Difference(EncoderI, EncoderF);
	writeDebugStreamLine("Dist( %d, %d, %d, 0);", EncoderValue, Direction, 70);   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else	if(vexRT[Btn7D]==1) //JOYSTICK DEADBAND
{
	Direction=0;   //Forward
	EncoderI=DistRecord();
	while(vexRT[Btn7D]==1)
	{
		int speed=-70;                                                             //SET SPEED
		motor[LM] = speed;
		motor[L1] = speed;
		motor[L2] = speed;
		motor[RM] = speed;
		motor[R1] = speed;
		motor[R2] = speed;
	}
	//Break();                   //Stop the robot...   thank you Norrin
	EncoderF=DistRecord();
	EncoderValue=Difference(EncoderI, EncoderF);
	writeDebugStreamLine("Dist( %d, %d, %d, 0);", EncoderValue, Direction, 70);   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else if(vexRT[Btn8L]==1)
{
	TurnDegree(-90, 50, 0);
	StopDrive();
	writeDebugStreamLine("TurnDegree(-90, 50);");   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
	ArmRun(ArmValue);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
else if(vexRT[Btn8R]==1)
{
	TurnDegree(90, 50, 0);
	StopDrive();
	writeDebugStreamLine("TurnDegree(90, 50);");   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
	else if(vexRT[Btn8U]==1)
{
	TurnDegree(-135, 50, 0);
	StopDrive();
	writeDebugStreamLine("TurnDegree(-135, 50);");   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
	ArmRun(ArmValue);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
	}
		else if(vexRT[Btn8D]==1)
{
	TurnDegree(45, 50, 0);
	StopDrive();
	writeDebugStreamLine("TurnDegree(45, 50);");   //SET SPEED
	writeDebugStreamLine("wait1Msec(%d);",Time);
	ArmRun(ArmValue);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
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
int armspeed=90;// ARM SPEED HERE
if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
{SensorValue[ArmEnc]=0;
	ArmI=ArmRecord();
	while(vexRT[Btn5U] == 1)
	{
		motor[leftArmM] = armspeed;
		motor[leftArmY] = armspeed;
		motor[rightArmM] = armspeed;
		motor[rightArmY] = armspeed;
	}
	ArmF=ArmRecord();
	EncoderValue=Difference(ArmI, ArmF);
	writeDebugStreamLine("ArmPosition(%d, 1, %d)",EncoderValue, 90);
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
{SensorValue[ArmEnc]=0;
	ArmI=ArmRecord();
	while(vexRT[Btn5D] == 1)
	{
		motor[leftArmM] = -armspeed;
		motor[leftArmY] = -armspeed;
		motor[rightArmM] = -armspeed;
		motor[rightArmY] = -armspeed;

	}
	ArmF=ArmRecord();
	EncoderValue=Difference(ArmI, ArmF);
	writeDebugStreamLine("ArmPosition(%d, 0, %d);",EncoderValue, 90);
	writeDebugStreamLine("wait1Msec(%d);",Time);
			writeDebugStreamLine("ArmRun(%d);",ArmValue);
}
else                      		//Else (neither button is pressed)...
{
ArmRun(ArmValue);     	//...stop the arm.
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
