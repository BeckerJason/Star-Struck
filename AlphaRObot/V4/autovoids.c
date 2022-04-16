float DifferenceGyro(float first, float second)
{ float difference=second-first;
	return difference;
}
void ClawButton()
{if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
	else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
		//writeDebugStreamLine("
}
void value(int value){
	motor[leftArmM] =value;
	motor[leftArmY] =value;
	motor[rightArmM] =value;
	motor[rightArmY] =value;}

void values(int value1, int value2){
	motor[LM] = value1 + value2;
	motor[L1] = value1 + value2;
	motor[L2] = value1 + value2;
	motor[RM] = value1 - value2;
	motor[R1] = value1 - value2;
	motor[R2] = value1 - value2;}

float GyroRecord(){
	float gyro = SensorValue[Gyro];
	return gyro;}

int DistRecord(){
	int encoder = SensorValue[LeftEnc];
	return encoder;}

int ArmRecord(){
	int encoder = SensorValue[ArmEnc];
	return encoder;}

void Move(int direction, int speed)
{
	int left = 0, right = 0;
	if (direction == 1){left = 1; right = 1;}//FORWARD = 1
	else if (direction == 2){left = -1; right =  -1; } //BACKWARD = 2
	else if (direction == 3) {left =  -1; right =  1; } //LEFT = 3
	else if (direction == 4){left = 1; right = -1; } //RIGHT = 4
	motor[LM] = speed*left;
	motor[L1] = speed*left;
	motor[L2] = speed*left;
	motor[RM] = speed*right;
	motor[R1] = speed*right;
	motor[R2] = speed*right;
}


void Dist( int EncoderValue, int Direction,int speed,int TimeOut)
{SensorValue[LeftEnc]=0;
	if (Direction ==1)    ///  1 = FORWARD
	{
		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			else{
			motor[LM] = speed;
			motor[L1] = speed;
			motor[L2] = speed;
			motor[RM] = speed;
			motor[R1] = speed;
			motor[R2] = speed;}
		}
	}
	else													///BACKWARD = 0
	{		while (abs(SensorValue[LeftEnc])<abs(EncoderValue))
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			motor[LM] =-speed;
			motor[L1] = -speed;
			motor[L2] = -speed;
			motor[RM] = -speed;
			motor[R1] = -speed;
			motor[R2] = -speed;
		}
	}
	StopDrive();
}
void ClawAct()
{if(vexRT[Btn6D]==1)
	{
		motor[leftArmM] = 10;
		motor[leftArmY] =10;
		motor[rightArmM] = 10;
		motor[rightArmY] = 10;
	}
	if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
	else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
}
int Difference(int first, int second)
{ int difference=second-first;
	return difference;
}
/*void DriveStop()
{	motor[LM] = 0;
motor[L1] = 0;
motor[L2] = 0;
motor[RM] =0;
motor[R1] = 0;
motor[R2] = 0;}*/
void ArmPosition(int EncoderValue, int Direction, int speed, int TimeOut)
{time1[T3]=0;
	if (Direction==1)////UP
	{SensorValue[ArmEnc]=0;
		while (abs(SensorValue[ArmEnc])<abs(EncoderValue))
		{if(time1[T3]>TimeOut){StopDrive();break;}
			motor[leftArmM] = speed;
			motor[leftArmY] =speed;
			motor[rightArmM] = speed;
			motor[rightArmY] = speed;
		}
	}
	else
	{SensorValue[ArmEnc]=0;
		while (SensorValue[ArmEnc]>EncoderValue)
		{if(time1[T3] > TimeOut && TimeOut > 0){StopDrive();break;}
			motor[leftArmM] = -speed;
			motor[leftArmY] =-speed;
			motor[rightArmM] = -speed;
			motor[rightArmY] = -speed;
		}
	}StopArm();
}
void ArmRun(int speed)
{
			motor[leftArmM] = speed;
			motor[leftArmY] = speed;
			motor[rightArmM] = speed;
			motor[rightArmY] = speed;
}
