void DisplayLCD(int print)
{clearLCDLine(0);
	clearLCDLine(1);
	if (print==1){displayLCDString(0,0,"Forward");}
	if (print==2){displayLCDString(0,0,"Backward");}
	if (print==3){displayLCDString(0,0,"Arm Up");}
	if (print==4){displayLCDString(0,0,"Arm Down");}
	if (print==5){displayLCDString(0,0,"Claw O/C");}
	if (print==6){displayLCDString(0,0,"Turning");}
	if (print==7){displayLCDString(0,0,"");}
	if (print==8){displayLCDString(0,0,"");}
	if (print==9){displayLCDString(0,0,"");}
	if (print==10){displayLCDString(0,0,"10");}
}


///////////////////////////////////////STOP DRIVE TRAIN
void StopArm()
{
	motor[leftArmY] = 0;
	motor[leftArmM] = 0;
	motor[rightArmY] = 0;
	motor[rightArmM] = 0;
}

void StopDrive()
{
	motor[LM] = 0;
	motor[L1] = 0;
	motor[L2] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	motor[R2] = 0;
}

void TurnBreak(int time, int speed)
{
	motor[LM] = speed;
	motor[L1] = speed;
	motor[L2] = speed;
	motor[RM] = -speed;
	motor[R1] = -speed;
	motor[R2] = -speed;
	wait1Msec(time);
	StopDrive();
}

void Break(int time, int speed)
{
	motor[LM] = -speed;
	motor[L1] = -speed;
	motor[L2] = -speed;
	motor[RM] = -speed;
	motor[R1] = -speed;
	motor[R2] = -speed;
	wait1Msec(time);
	StopDrive();
}

void ArmRun(int speed)
{
	motor[leftArmM] = speed;
	motor[leftArmY] = speed;
	motor[rightArmM] = speed;
	motor[rightArmY] = speed;
}

int Difference(int first, int second)
{ int difference=second-first;
	return difference;
}
///////////////////////////////////////TURN BASED ON GYRO DEGREES EXAMPLE // TurnDegree(-90, 127);//THIS TURNS LEFT 90 DEGREES AT 127 POWER
void TurnDegree(int degrees, int speed, int TimeOut)//, int Timeout)
{DisplayLCD(6);
	int left = 0, right = 0;
	SensorValue[Gyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees*7.7);
	clearTimer(T3);
	SensorValue[LeftEnc]=0;
	SensorValue[RightEnc]=0;
	while(abs(SensorValue[Gyro]) < ticks)
	{
		////////////////////////////////////FAILSAFE TIMEOUT
		if(time1[T3] > TimeOut  && TimeOut > 0){ FailSafeEngaged = 1; break;}
		else if(degrees<0&&abs(SensorValue[LeftEnc])>abs(SensorValue[RightEnc]))///////
		{motor[LM] = speed*left+15;
			motor[L1] = speed*left+15;
			motor[L2] = speed*left+15;
			motor[RM] = speed*right;
			motor[R1] = speed*right;
			motor[R2] = speed*right;}
		else if(degrees<0&&abs(SensorValue[LeftEnc])<abs(SensorValue[RightEnc]))///////
		{motor[LM] = speed*left;
			motor[L1] = speed*left;
			motor[L2] = speed*left;
			motor[RM] = speed*right-15;
			motor[R1] = speed*right-15;
			motor[R2] = speed*right-15;}
		else if(degrees>0&&abs(SensorValue[LeftEnc])<abs(SensorValue[RightEnc]))///////
		{motor[LM] = speed*left+15;
			motor[L1] = speed*left+15;
			motor[L2] = speed*left+15;
			motor[RM] = speed*right;
			motor[R1] = speed*right;
			motor[R2] = speed*right;}
		else if(degrees>0&&abs(SensorValue[LeftEnc])>abs(SensorValue[RightEnc]))///////
		{	motor[LM] = speed*left;
			motor[L1] = speed*left;
			motor[L2] = speed*left;
			motor[RM] = speed*right-15;
			motor[R1] = speed*right-15;
			motor[R2] = speed*right-15;}
		else{
			motor[LM] = speed*left;
			motor[L1] = speed*left;
			motor[L2] = speed*left;
			motor[RM] = speed*right;
			motor[R1] = speed*right;
			motor[R2] = speed*right;}
	}
	motor[LM] = (speed*left*-1)/4;
	motor[L1] = (speed*left*-1)/4;
	motor[L2] = (speed*left*-1)/4;
	motor[RM] = (speed*left*-1)/4;
	motor[R1] = (speed*right*-1)/4;
	motor[R2] = (speed*right*-1)/4;
	wait1Msec(150);
	StopDrive();
}

void FixDegree(int degrees,int speed, int TimeOut)
{ int left = 0, right = 0;
	SensorValue[Gyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }

	else{writeDebugStreamLine("Its 0");}///////////////////////////////////////////////////////
	float ticks =abs(degrees*.77);
	SensorValue[LeftEnc]=0;
	SensorValue[RightEnc]=0;
	clearTimer(T3);
	if(degrees!=0)
	{
		while(abs(SensorValue[Gyro]) < ticks)
		{
			////////////////////////////////////FAILSAFE TIMEOUT
			if(time1[T3] > TimeOut  && TimeOut > 0){ FailSafeEngaged = 1;break;}
			else if(degrees<0&&abs(SensorValue[LeftEnc])>abs(SensorValue[RightEnc]))///////
			{motor[LM] = speed*left+10;
				motor[L1] = speed*left+10;
				motor[L2] = speed*left+10;
				motor[RM] = speed*right;
				motor[R1] = speed*right;
				motor[R2] = speed*right;}
			else if(degrees<0&&abs(SensorValue[LeftEnc])<abs(SensorValue[RightEnc]))///////
			{motor[LM] = speed*left;
				motor[L1] = speed*left;
				motor[L2] = speed*left;
				motor[RM] = speed*right-10;
				motor[R1] = speed*right-10;
				motor[R2] = speed*right-10;}
			else if(degrees>0&&abs(SensorValue[LeftEnc])<abs(SensorValue[RightEnc]))///////
			{motor[LM] = speed*left+10;
				motor[L1] = speed*left+10;
				motor[L2] = speed*left+10;
				motor[RM] = speed*right;
				motor[R1] = speed*right;
				motor[R2] = speed*right;}
			else if(degrees>0&&abs(SensorValue[LeftEnc])>abs(SensorValue[RightEnc]))///////
			{	motor[LM] = speed*left;
				motor[L1] = speed*left;
				motor[L2] = speed*left;
				motor[RM] = speed*right-10;
				motor[R1] = speed*right-10;
				motor[R2] = speed*right-10;}
			else{
				motor[LM] = speed*left;
				motor[L1] = speed*left;
				motor[L2] = speed*left;
				motor[RM] = speed*right;
				motor[R1] = speed*right;
				motor[R2] = speed*right;}
		}

		/*motor[LM] = (speed*left*-1)/4;
		motor[L1] = (speed*left*-1)/4;
		motor[L2] = (speed*left*-1)/4;
		motor[RM] = (speed*left*-1)/4;
		motor[R1] = (speed*right*-1)/4;
		motor[R2] = (speed*right*-1)/4;
		wait1Msec(150);*/
		//SensorValue[Gyro]=0;
		TurnBreak(100,speed*right);
	}

	StopDrive();
}

void ClawStatus(int value)
{DisplayLCD(5);
	SensorValue[clawL]=value;
	SensorValue[clawR]=value;
}


void KillALL(void)
{
	StopArm();
	StopDrive();
}

float DifferenceGyro(float first, float second)
{ float difference=second-first;
	return difference;
}

float GyroRecord(){
	float gyro = SensorValue[Gyro];
	return gyro;}

int DistRecord(){
	int encoder = SensorValue[LeftEnc];
	return encoder;}

int ArmRecord(){
	int encoder = SensorValue[ArmEnc];
	return encoder;}

void Dist( int EncoderValue, int Direction,int speed,int TimeOut)
{SensorValue[LeftEnc]=0;
	time1[T3]=0;
	if (Direction ==1)    ///  1 = FORWARD
	{

		DisplayLCD(1);//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		SensorValue[Gyro]=0;
		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			else{if (SensorValue[Gyro]>0){
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
					motor[R2] = speed;}}
		}
	}
	else													///BACKWARD = 0
	{
		DisplayLCD(2);//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			else{if (SensorValue[Gyro]>0){
					motor[LM] = -speed;
					motor[L1] = -speed;
					motor[L2] = -speed;
					motor[RM] = -speed+10;
					motor[R1] = -speed+10;
					motor[R2] = -speed+10;}
				else if (SensorValue[Gyro]<0){
					motor[LM] = -speed+10;
					motor[L1] = -speed+10;
					motor[L2] = -speed+10;
					motor[RM] = -speed;
					motor[R1] = -speed;
					motor[R2] = -speed;}
				else{
					motor[LM] = -speed;
					motor[L1] = -speed;
					motor[L2] = -speed;
					motor[RM] = -speed;
					motor[R1] = -speed;
					motor[R2] = -speed;}}
		}
	}
	StopDrive();
}
/////////////////////////////////////////////////////////////////////////
void ThrowDist( int EncoderValue, int Direction,int speed,int TimeOut,int ArmEncoderValue,int ArmDirection,int armspeed)
{SensorValue[LeftEnc]=0;
	SensorValue[ArmEnc]=0;
	time1[T3]=0;
	if (Direction ==1)    ///  1 = FORWARD
	{

		DisplayLCD(1);//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		SensorValue[Gyro]=0;
		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;
			}
			else{if (SensorValue[Gyro]>0)
				{
					motor[LM] = speed;
					motor[L1] = speed;
					motor[L2] = speed;
					motor[RM] = speed-10;
					motor[R1] = speed-10;
					motor[R2] = speed-10;}
				else if (SensorValue[Gyro]<0)
				{
					motor[LM] = speed-10;
					motor[L1] = speed-10;
					motor[L2] = speed-10;
					motor[RM] = speed;
					motor[R1] = speed;
					motor[R2] = speed;
				}
				else{
					motor[LM] = speed;
					motor[L1] = speed;
					motor[L2] = speed;
					motor[RM] = speed;
					motor[R1] = speed;
					motor[R2] = speed;
				}
			}
		}
	}
	else													///BACKWARD = 0
	{
		DisplayLCD(2);//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			else
			{if (SensorValue[Gyro]>0)
				{
					motor[LM] = -speed;
					motor[L1] = -speed;
					motor[L2] = -speed;
					motor[RM] = -speed+10;
					motor[R1] = -speed+10;
					motor[R2] = -speed+10;
				}
				else if (SensorValue[Gyro]<0)
				{
					motor[LM] = -speed+10;
					motor[L1] = -speed+10;
					motor[L2] = -speed+10;
					motor[RM] = -speed;
					motor[R1] = -speed;
					motor[R2] = -speed;
				}
				else{
					motor[LM] = -speed;
					motor[L1] = -speed;
					motor[L2] = -speed;
					motor[RM] = -speed;
					motor[R1] = -speed;
					motor[R2] = -speed;
				}
				if (ArmDirection==1)////UP
				{
					while (abs(SensorValue[ArmEnc])<abs(ArmEncoderValue))
					{
						motor[leftArmM] = armspeed;
						motor[leftArmY] =armspeed;
						motor[rightArmM] = armspeed;
						motor[rightArmY] = armspeed;
					}
					StopArm();ClawStatus(0);
				}
				else
				{
					while (SensorValue[ArmEnc]>ArmEncoderValue)
					{	motor[leftArmM] = -armspeed;
						motor[leftArmY] =-armspeed;
						motor[rightArmM] = -armspeed;
						motor[rightArmY] = -armspeed;
					}
					StopArm(); ClawStatus(0);
				}
			}
		}
		StopDrive();
		//////////////////////////////////////////////////GIVE MORE TIME FOR ARM TO THROW IF NEEDED
		if (ArmDirection==1)////UP
		{																																											/////
			if (abs(SensorValue[ArmEnc])<abs(ArmEncoderValue))
			{																																											///
				motor[leftArmM] = speed;																														///
				motor[leftArmY] =speed;																															///
				motor[rightArmM] = speed;																														///
				motor[rightArmY] = speed;																														///
			}																																											///
			else{StopArm();ClawStatus(0);}
		}
		else
		{
			if (SensorValue[ArmEnc]>ArmEncoderValue)																			///
			{	motor[leftArmM] = -speed;
				motor[leftArmY] =-speed;
				motor[rightArmM] = -speed;
				motor[rightArmY] = -speed;
			}
			else{StopArm(); ClawStatus(0);}
		}
		///////////////////////////////////////////////////////////////
	}
}

void ArmPosition(int EncoderValue, int Direction, int speed, int TimeOut)
{time1[T3]=0;
	if (Direction==1)////UP
	{
		DisplayLCD(3);//~~~~~~~~~~~~~~~~~~~

		SensorValue[ArmEnc]=0;
		while (abs(SensorValue[ArmEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();StopArm();break;}
			else{
				motor[leftArmM] = speed;
				motor[leftArmY] =speed;
				motor[rightArmM] = speed;
				motor[rightArmY] = speed;}
		}
	}
	else
	{
		DisplayLCD(4);//~~~~~~~~~~~~~~~~~~~~~~~~~~~

		SensorValue[ArmEnc]=1;
		while (SensorValue[ArmEnc]>EncoderValue)
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			else{
				motor[leftArmM] = -speed;
				motor[leftArmY] =-speed;
				motor[rightArmM] = -speed;
				motor[rightArmY] = -speed;}
		}
	}StopArm();
}

void F(int A,int D3,int D4,int C, int W)
{motor[leftArmM] = A;
	motor[leftArmY] =A;
	motor[rightArmM] =A;
	motor[rightArmY] =A;

	motor[LM] = D3 + D4;
	motor[L1] = D3 + D4;
	motor[L2] = D3 +D4;
	motor[RM] = D3 - D4;
	motor[R1] = D3 - D4;
	motor[R2] = D3 - D4;

	SensorValue[clawR]=C;	SensorValue[clawL]=C;

	wait1Msec(W);
}
