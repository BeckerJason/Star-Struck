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


void Dist(int EncoderValue, int Direction,int speed)
{SensorValue [LeftEnc]=0;

	if (Direction ==1)    ///  1 = FORWARD
	{
		while (SensorValue[LeftEnc]<EncoderValue)
		{
			Claw();
			motor[LM] = speed;
			motor[L1] = speed;
			motor[L2] = speed;
			motor[RM] = speed;
			motor[R1] = speed;
			motor[R2] = speed;
		}
	}
	else													///BACKWARD = 0
	{		while (SensorValue[LeftEnc]>EncoderValue)
		{
			Claw();
			motor[LM] = -speed;
			motor[L1] = -speed;
			motor[L2] = -speed;
			motor[RM] = -speed;
			motor[R1] = -speed;
			motor[R2] = -speed;
		}
	}
}
void Claw()
{if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;}
	else{SensorValue[clawR]=0;	SensorValue[clawL]=0;}
	if(vexRT[Btn6D]==1)
	{
		motor[leftArmM] = 10;
		motor[leftArmY] =10;
		motor[rightArmM] = 10;
		motor[rightArmY] = 10;
	}
}
int Difference(int first, int =second)
{int difference=second-first;
	return difference;
}
