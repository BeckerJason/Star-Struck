void StopDriveMaster()
{
	motor[rightFrontM] = 0;
	motor[rightBackM] = 0;
	motor[leftFrontM] = 0;
	motor[leftBackM] = 0;
}

void breakMaster(int time, int power)
{
	motor[rightFrontM] = -power;
	motor[rightBackM] = -power;
	motor[leftFrontM] = -power;
	motor[leftBackM] = -power;
	wait1Msec(time);
	StopDriveMaster();
}

//MOVE ROBOT BASED ON SPEED EXAMPLE // direction: -1 = left   1 = right 2 = Forward -2 = Backwards
//EX: while(condition){ MoveMaster(2,127) };//THIS MOVES FORWARD UNTIL CONDITION IS MET
void MoveMaster(int direction, int speed)
{
	int left = 0, right = 0;
	if (direction == 1){left = 1; right = -1;}
	else if (direction == -1){left = -1; right =  1; }
	else if (direction == 2) {left =  1; right =  1; }
	else if (direction == -2){left = -1; right = -1; }
	else if (direction == 3){left = 1; right = 0; }
	else if (direction == -3){left = 0; right = 1; }
	else if (direction == 4){left = -1; right = 0; }
	else if (direction == -4){left = 0; right = -1; }
	motor[rightFrontM] = speed*right;
	motor[rightBackM] = speed*right;
	motor[leftFrontM] = speed*left;
	motor[leftBackM] = speed*left;
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
}

int SetDegreesMaster(int degrees, int timeOut)//, int speed)
{
	if(MoveCounterMaster==0)
	{
		clearTimer(T4);
		MoveCounterMaster=1;
	}

	int left = 0, right = 0;
	int error = (SensorValue[Gyro]-degrees);
	int status = 1;
	float proportion = 0.3, integral = 0, pin=0.4;
	integral = integral+abs(error)*pin;

	if (error < 0){left = -1; right = 1;}
	else if (error > 0){left = 1; right = -1; }
	if(error!=0)//>allowedError || error<-allowedError)
	{
		motor[rightFrontM] = (integral+proportion*abs(error))*right;//speed*right;
		motor[rightBackM] = (integral+proportion*abs(error))*right;//speed*right;
		motor[leftFrontM] = (integral+proportion*abs(error))*left;//speed*left;
		motor[leftBackM] = (integral+proportion*abs(error))*left;
		status=1;
	}
	else
	{
		StopDriveMaster();
		MoveCounterMaster=0;
		status=0;
	}
		//////////////////////////////////FAILASFE TIMEOUT
			if(time1[T4] > TimeOut && TimeOut > 0){status=0;StopDriveMaster();MoveCounterMaster=0;}
		//////////////////////////////////////////////////
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}

//TURN BASED ON GYRO DEGREES EXAMPLE
//EX: TurnDegreeMaster(-90, 127);//THIS TURNS LEFT 90 DEGREES AT 127 POWER
void TurnDegreeMaster(int degrees, int speed)//, int Timeout)
{
	int left = 0, right = 0;
	SensorValue[Gyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees*7.7);
	clearTimer(T4);

	while(abs(SensorValue[Gyro]) < ticks)
	{
		////////////////////////////////////FAILASFE TIMEOUT
		//	if(time1[T3] > TimeOut && TimeOut > 0){ FailSafeEngagedM = 1; break;}
		////////////////////////////////////////////////////
		motor[rightFrontM] = speed*right;
		motor[rightBackM] = speed*right;
		motor[leftFrontM] = speed*left;
		motor[leftBackM] = speed*left;
		//AVOID CPU OVERLOAD(HOGGING)//
		wait1Msec(10);
		/////////////////////
	}
	motor[rightFrontM] = (speed*right*-1)/4;;
	motor[rightBackM] = (speed*right*-1)/4;;
	motor[leftFrontM] = (speed*left*-1)/4;
	motor[leftBackM] = (speed*left*-1)/4;
	wait1Msec(150);
	StopDriveMaster();
}

//TURN ROBOT TO A SPESIFIC DEGREE WITH A SPECIFIC VALUE CONVERTION
//USE TO MAKE A CUSTOMIZABLE TURN
void TurnDegreeMaster(int degrees, int speed, int Break)//, int Timeout)
{
	int left = 0, right = 0;
	SensorValue[Gyro] = 0;
	wait1Msec(50);
	SensorValue[Gyro] = 0;
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees);
	clearTimer(T4);

	while(abs(SensorValue[Gyro]) < ticks)
	{
		////////////////////////////////////FAILASFE TIMEOUT
		//	if(time1[T3] > TimeOut && TimeOut > 0){ FailSafeEngagedM = 1; break;}
		////////////////////////////////////////////////////
		motor[rightFrontM] = speed*right;
		motor[rightBackM] = speed*right;
		motor[leftFrontM] = speed*left;
		motor[leftBackM] = speed*left;
		//AVOID CPU OVERLOAD(HOGGING)//
		wait1Msec(10);
		/////////////////////
	}
	if(Break == 1)
	{
		motor[rightFrontM] = (speed*right*-1)/4;;
		motor[rightBackM] = (speed*right*-1)/4;;
		motor[leftFrontM] = (speed*left*-1)/4;
		motor[leftBackM] = (speed*left*-1)/4;
		wait1Msec(150);
	}
	StopDriveMaster();
}

void MoveTimeMaster(int time, int speed)
{
	motor[rightFrontM] = speed;
	motor[rightBackM] = speed;
	motor[leftFrontM] = speed;
	motor[leftBackM] = speed;
	wait1Msec(time);
	breakMaster(250, speed/4);
}

//MOVE FORWARD/BACKWARDS BASED ON ENCODER READING
//EX: while(MoveDistMaster(-10, 127) == 1){DO SOMETHING LIKE INTAKE ON}//THIS MOVES BACKWARDS FOR 10 INCHES AT POWER 127
int MoveDistMaster(int inches, int speed, int TimeOut)
{
	int status, direction = 0;
	//RESET ENCODER/////
	if (MoveCounterMaster == 0 )
	{
		SensorValue[encDrive] = 0;
		wait1Msec(50);
		SensorValue[encDrive] = 0;
		MoveCounterMaster = 1;
		clearTimer(T4);
	}
	//TIME OUT FAILSAFE
	if(time1[T4]>TimeOut){MoveCounterMaster=0;StopDriveMaster();return 0;}
	////////////////

	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	int ticks = abs(inches*360/10.205)*2; ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	if(abs(SensorValue[encDrive]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		motor[rightFrontM] = speed;
		motor[rightBackM] = speed;
		motor[leftFrontM] = speed;
		motor[leftBackM] = speed;
		status = 1;
	}
	else
	{
		breakMaster(250, direction*speed/8);
		status = 0;
		MoveCounterMaster = 0;
	}
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}

int MoveDistMaster(int inches, int speed, int TimeOut, int straight)
{
	int status, direction = 0;
	int correction, correctionLimit=50;
	//RESET ENCODER/////
	if (MoveCounterMaster == 0 )
	{
		if(straight){SensorValue[Gyro]=0;}
		SensorValue[encDrive] = 0;
		wait1Msec(50);
		SensorValue[encDrive] = 0;
		MoveCounterMaster = 1;
		clearTimer(T4);
	}
	//TIME OUT FAILSAFE
	if(time1[T4]>TimeOut){MoveCounterMaster=0;StopDriveMaster();return 0;}
	////////////////

	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	int ticks = abs(inches*360/10.205)*2; ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	correction = SensorValue[Gyro]*direction*2;
	if(abs(correction)>correctionLimit)correction=correctionLimit;	//LIMIT CORRECTION VALUE
		if(abs(SensorValue[encDrive]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		if(straight!=1){
			motor[rightFrontM] = speed*direction;
			motor[rightBackM] = speed*direction;
			motor[leftFrontM] = speed*direction;
			motor[leftBackM] = speed*direction;
		}
		else {
			motor[rightFrontM] = speed*direction+(correction)*direction;
			motor[rightBackM] = speed*direction+(correction)*direction;
			motor[leftFrontM] = speed*direction-(correction*direction);
			motor[leftBackM] = speed*direction-(correction*direction);
		}
		status = 1;
	}
	else
	{
		breakMaster(150, direction*speed/8);
		status = 0;
		MoveCounterMaster = 0;
	}
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}

//MOVE ARM UNTIL CONIDITION IS MET
//EX: while(condition){ MoveArmMaster(127) };
void MoveArmMaster(int speed)
{
	motor[armRightM] = speed;
	motor[armLeftM] = speed;
}

//SET THE ANGLE OF THE ARM TO A SPESIFIED DEGREE
//EX: while(ArmAngleMaster(45, 127, 3000)){}
int ArmAngleMaster(float angle, int speed, int TimeOut)
{
	int status, direction;
	//RESET ENCODER/////
	if (MoveCounterMaster == 0 )
	{
		SensorValue[encArm] = 0;
		wait1Msec(50);
		MoveCounterMaster = 1;
		clearTimer(T4);
	}
	////////////////////

	//TIME OUT FAILSAFE
	if(time1[T4]>TimeOut){MoveCounterMaster=0;return 0;}//FailSafeEngagedM=1;StopDriveMaster();}
	////////////////

	float ticks = abs(angle)*5;//2*(7/5);
	if(angle<0){direction=-1;}
	if(angle>0){direction=1;}
	if(abs(SensorValue[encArm])<ticks)
	{
		motor[armRightM] = speed*direction;
		motor[armLeftM] = speed*direction;
		status=1;
	}
	else
	{
		motor[armRightM] = speed/8;
		motor[armLeftM] = speed/8;
		status=0;
		MoveCounterMaster=0;
	}
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}

//USE TO OPEN OR CLOSE CLAW//EX: clawStatusMaster(1)//CLOSE CLAW
void clawStatusMaster(int on)
{
	SensorValue[pis1] = on;
	//SensorValue[pis2] = on;
}

void killMotorsMaster(void)
{
	motor[rightFrontM] = 0;
	motor[rightBackM] = 0;
	motor[leftFrontM] = 0;
	motor[leftBackM] = 0;
	motor[armRightM] = 0;
	motor[armLeftM] = 0;
}
