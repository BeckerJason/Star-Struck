void StopDrivePuppet()
{
	motor[rightP] = 0;
	motor[leftP] = 0;
}

void breakPuppet(int time, int power)
{
	motor[rightP] = -power;
	motor[leftP] = -power;
	wait1Msec(time);
	StopDrivePuppet();
}

//MOVE ROBOT BASED ON SPEED EXAMPLE // direction: -1 = left   1 = right 2 = Forward -2 = Backwards
//EX: while(condition){ MovePuppet(2,127) };//THIS MOVES FORWARD UNTIL CONDITION IS MET
void MovePuppet(int direction, int speed)
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
	motor[rightP] = speed*right;
	motor[leftP] = speed*left;
}

//TURN BASED ON GYRO DEGREES EXAMPLE
//EX: TurnDegreePuppet(-90, 127);//THIS TURNS LEFT 90 DEGREES AT 127 POWER
void TurnDegreePuppet(int degrees, int speed)
{
	int left = 0, right = 0;
	SensorValue[PGyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees*7.7);
	clearTimer(T3);

	while(abs(SensorValue[PGyro]) < ticks)
	{
		motor[rightP] = speed*right;
		motor[leftP] = speed*left;
		//AVOID CPU OVERLOAD(HOGGING)//
		wait1Msec(10);
		/////////////////////
	}
	motor[rightP] = (speed*right*-1)/4;;
	motor[leftP] = (speed*left*-1)/4;
	wait1Msec(150);
	StopDrivePuppet();
}

void TurnPuppet(int degrees, int speed, int Break)
{
	int left = 0, right = 0;
	SensorValue[PGyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees);
	clearTimer(T3);

	while(abs(SensorValue[PGyro]) < ticks)
	{
		motor[rightP] = speed*right;
		motor[leftP] = speed*left;
		//AVOID CPU OVERLOAD(HOGGING)//
		wait1Msec(10);
		/////////////////////
	}
	if(Break==1)
	{
		motor[rightP] = (speed*right*-1)/4;
		motor[leftP] = (speed*left*-1)/4;
		wait1Msec(250);
	}
	StopDrivePuppet();
}

void TurnPuppet(int degrees, int speed, int Break, int Timeout)
{
	int left = 0, right = 0;
	SensorValue[PGyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees);
	clearTimer(T3);

	while(abs(SensorValue[PGyro]) < ticks)
	{
		////////////////////////////////////FAILASFE TIMEOUT
		if(time1[T3] > TimeOut && TimeOut > 0){ FailSafeEngagedP = 1; break;}
		////////////////////////////////////////////////////
		motor[rightP] = speed*right;
		motor[leftP] = speed*left;
		//AVOID CPU OVERLOAD(HOGGING)//
		wait1Msec(10);
		/////////////////////
	}
	if(Break==1)
	{
		motor[rightP] = (speed*right*-1)/4;
		motor[leftP] = (speed*left*-1)/4;
		wait1Msec(250);
	}
	StopDrivePuppet();
}

void MoveTimePuppet(int time, int speed)
{
	motor[rightP] = speed;
	motor[leftP] = speed;
	wait1Msec(time);
	breakPuppet(250, speed/4);
}

//MOVE FORWARD/BACKWARDS BASED ON ENCODER READING
//EX: while(MoveDistPuppet(-10, 127) == 1){DO SOMETHING LIKE INTAKE ON}//THIS MOVES BACKWARDS FOR 10 INCHES AT POWER 127
int MoveDistPuppet(int inches, int speed, int TimeOut)
{
	int status, direction = 0;
	//RESET ENCODER/////
	if (MoveCounterPuppet == 0 )
	{
		SensorValue[encPDrive] = 0;
		wait1Msec(50);
		MoveCounterPuppet = 1;
		clearTimer(T3);
	}
	//TIME OUT FAILSAFE
	if(time1[T3]>TimeOut){MoveCounterPuppet=0;StopDriveMaster();return 0;}
	////////////////

	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	int ticks = abs(inches*360/10.205)*2; ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	if(abs(SensorValue[encPDrive]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		motor[rightP] = speed*direction;
		motor[leftP] = speed*direction;
		status = 1;
	}
	else
	{
		breakPuppet(150, direction*speed/8);
		status = 0;
		MoveCounterPuppet = 0;
	}
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}
//USES GYRO TO MOVE STRAGHT
int MoveDistPuppet(int inches, int speed, int TimeOut, int straight)
{
	int status, direction = 0;
	int correction, correctionLimit=70;
	//RESET ENCODER/////
	if (MoveCounterPuppet == 0 )
	{
		if(straight){SensorValue[PGyro]=0;}
		SensorValue[encPDrive] = 0;
		wait1Msec(50);
		MoveCounterPuppet = 1;
		clearTimer(T3);
	}
	//TIME OUT FAILSAFE
	if(time1[T3]>TimeOut){MoveCounterPuppet=0;StopDriveMaster();return 0;}
	////////////////

	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	int ticks = abs(inches*360/10.205)*2; ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	correction = SensorValue[PGyro]*direction*2;
	if(abs(correction)>correctionLimit)correction=correctionLimit;	//LIMIT CORRECTION VALUE
		if(abs(SensorValue[encPDrive]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		if(straight!=1)
		{
			motor[rightP] = speed*direction;
			motor[leftP] = speed*direction;
		}
		else {
			motor[rightP] = speed*direction-(correction);
			motor[leftP] = speed*direction+(correction);
		}
		status = 1;
	}
	else
	{
		breakPuppet(150, direction*speed/8);
		status = 0;
		MoveCounterPuppet = 0;
	}
	//AVOID CPU OVERLOAD(HOGGING)//
	wait1Msec(10);
	/////////////////////
	return status;
}

//MOVE ARM UNTIL CONIDITION IS MET
//EX: while(condition){ MoveArmPuppet(127) };
void MoveArmPuppet(int speed)
{
	motor[armRightP] = speed;
	motor[armLeftP] = speed;
}

//USE TO OPEN OR CLOSE CLAW//EX: clawStatusPuppet(1)//CLOSE CLAW
void clawStatusPuppet(int on)
{
	SensorValue[pP]=on;
}

void killMotorsPuppet(void)
{
	motor[armRightP] = 0;
	motor[armLeftP] = 0;
	motor[rightP] = 0;
	motor[leftP] = 0;
}
