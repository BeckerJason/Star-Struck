void RedAuto2(void)
{
//THROUGH 4 STARS GO FOR WALL(BLUE RIGHT, RED LEFT)

clawStatus(1);
while(ArmAngle(180, 100));

//GET MIDDLE STARS
TurnDegree(-90, 55);
clawStatus(0);
//ARM DOWN
while(ArmAngle(-160, 127));
StopArm();
wait1Msec(500);
/////////////////////////
while(MoveDist(30, 90, 5000));
TurnDegree(12, 55);

while(MoveDist(68, 90, 3000));
StopDrive();
clawStatus(1);

//Thorugh stars
while(MoveDist(-5, 40, 5000));
while(ArmAngle(180, 100));

TurnDegree(-90, 50);
Move(1, 10);
wait1Msec(250);
StopDrive();

while(moveDist(-65, 75, 2500));

clearTimer(T2);
SensorValue[ArmEnc]=0;
while(MoveDist(-32, 127, 5000)){
if(SensorValue[ArmEnc]<500) MoveArm(127);
else	StopArm();
if(time1[T2]>2500)break;
}
stopArm();
clawStatus(0);

wait1Msec(500);

//Bring Arm Down
while(ArmAngle(-300, 127));

//ALLIGN WITH WALL LINE
//SensorValue[LeftEnc]=0;									//MOVE BACK
//while(MoveDist(3, 50)){}
//Break(150, 8);
//wait1Msec(500);
//TurnDegree(-30, 40);												//TURN TOWARDS LINE
SensorValue[Gyro]=0;
while(LineStatusMiddle()!=1){Move(-1, 30);
	if(abs(SensorValue[Gyro])>(200*10))break;
}
StopDrive();

//FOLLOW LINE AND PUNCH STARS
clawStatus(1);
while(punchFollowLine(35, 0.0145, 5000) && LineStatusRight()==1);
StopDrive();
while(punchFollowLine(25, 0.008, 10500))
{
	if((SensorValue[sonar]<=5)&&(time1[T3]>10000))
	{
		MoveCounter=0;
		break;
	}
	if(LineStatusLeft()!=1&&LineStatusMiddle()!=1&&LineStatusRight()!=1)
	{
		KillALL();
		while(1){}
	}
}
StopDrive();

//GET CUBE
while(MoveDist(-7, 40, 5000));
TurnDegree(90, 40);

while(LineStatusLeft()==1||LineStatusMiddle()==1||LineStatusRight()==1){Move(2, 30);}
stopArm();
//while(MoveDist(7, 30, 5000));
//TURN
TurnDegree(90, 50);
MoveTime(1500, -60);
//
clawStatus(0);
///////////////
//GRAB CUBE
while(MoveDist(55, 100, 5000));
clawStatus(1);
//ARM UP
while(ArmAngle(150, 100)){}

TurnDegree(-90, 60);

//Dumping Cube Step by step
while(MoveDist(-32, 80, 2500));
StopDrive();
while(ArmAngle(280, 127));

clawStatus(0);
wait1Msec(500);
//Arm back down
while(ArmAngle(-300, 100));
StopArm();

while(1);
}
