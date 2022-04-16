void RedAuto1(void)
{
//FENCE FIRST (RED LEFT, BLUE RIGHT)

KillALL();
//Autonomous start///////////////////////////////////
//ARM ANGLE FUNCTION
clawStatus(1);														//CLOSE CLAW

while(ArmAngle(240,127)){clawStatus(1);Move(2, 90);}	//MOVE ARM UP

clawStatus(0);
while(MoveDist(36, 90, 2500)){}								//DRIVE FORWARD (INTIL WALL)

							//MOVE BACK
while(MoveDist(-3, 30, 1000)){}
//Break(-150, 8);

TurnDegree(70, 40);												//TURN TOWARDS LINE
SensorValue[Gyro]=0;
while(LineStatusMiddle()!=1){Move(1, 30);
	if(abs(SensorValue[Gyro])>(200*10))break;
}

while(punchFollowLine(35, 0.0145, 2000) && LineStatusLeft()==1)
{}

StopDrive();
clawStatus(1);
while(ArmAngle(-100,40)){clawStatus(1);}	//ARM DOWN CLOSE CLAW
MoveArm(8);
wait1Msec(50);
while(punchFollowLine(25, 0.008, 10500))
{
	if((SensorValue[sonar]<=5)&&(time1[T3]>10000))
	{
		MoveCounter=0;
		break;
	}
	//if(LineStatusLeft()!=1&&LineStatusMiddle()!=1&&LineStatusRight()!=1)
	//{
	//	KillALL();
	//	while(1){}
	//}
}		//SONAR FAIL SAFE
StopDrive();

/////SECOND PART TESTING
//SensorValue[ArmEnc]=0;
//while(ArmAngle(170,100));
//wait1Msec(1000);
//MoveTime(2500, 25);
//StopDrive();
//////////////////////////

////ACTUAL CODE
while(MoveDist(-7, 40, 1000));
TurnDegree(90, 40);
//BREAK THE TURN
Move(-1, 20);
wait1Msec(250);
StopDrive();
//FORWARD UNTIL LINE
while(SensorValue[midLine]>1000){Move(2, 30);}
StopArm();
//TURN
TurnDegree(90, 50);
MoveTime(1000, -60);
////////////////
clawStatus(0);
MoveArm(-80);
wait1Msec(250);

StopArm();
///////////////
//GRAB CUBE
while(MoveDist(55, 100, 3000));
clawStatus(1);
//ARM UP
while(ArmAngle(150, 100)){}
//
//while(MoveDist(79, 100, 3500));
while(SensorValue[sonar]>15){Move(2, 85)};
Break(150, 13);
//while(MoveDist(-5, 40, 1000));
TurnDegree(-90, 55);
Move(1, 15);
wait1Msec(250);
StopDrive();
//DUMP CUBE
//Dumping Cube Step by step
while(MoveDist(-32, 80, 3500)){}
while(ArmAngle(280, 127));
///////////////////////////////
StopArm();
clawStatus(0);
wait1Msec(500);
////GET STAR//
while(ArmAngle(-250, 127));
StopArm();
while(MoveDist(37, 40, 3000));
clawStatus(1);
//DUMP STAR///////////////
SensorValue[ArmEnc]=0;
while(MoveDist(-37, 90, 3500)){
	if(SensorValue[ArmEnc]<1100) MoveArm(127);
	else	MoveArm(-8);
}
stopArm();
clawStatus(0);
///////////////////////

//Get MIDDLE STARS
Move(-2, 30);
while(ArmAngle(-80, 50));	//IF ARM DOES'NT COME DOWN ENOUGH IT GETS STUCK
wait1Msec(500);
StopDrive();

//while(moveDist(63, 60, 3500));
while(MoveSonar(10, 40, 3500);
//while(MoveDist(-2, 30, 3500);

TurnDegree(-85, 50);
MoveArm(-90);
wait1Msec(800);
StopArm();

while(MoveDist(30, 90, 2500));
TurnDegree(-12, 40);

while(MoveDist(70, 90, 4000));
clawStatus(1);

wait1Msec(500);
//Through middle stars
while(MoveDist(-5, 40, 1000));
while(ArmAngle(170, 100));

TurnDegree(90, 45);

while(moveDist(-65, 85, 5000));

SensorValue[ArmEnc]=0;
while(MoveDist(-32, 127, 4000)){
	if(SensorValue[ArmEnc]<800) MoveArm(127);
	else	StopArm();
}
stopArm();
clawStatus(0);

while(ArmAngle(-250, 127));
StopArm();

while(1);
}
