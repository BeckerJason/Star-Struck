KillALL();
//startTask(anglePIDControl);
//Puncher Test;	ACTIVATE PISTON 10 TIMES
//for(int i =0;i<10;i++)
//{
//SensorValue[puncher]=1;
//wait1Msec(300);
//SensorValue[puncher]=0;
//wait1Msec(300);
//}

//PID-ANGLE CONTROL////
//RequestedAngle = -50;
//pidRunning = 1;
///////////////////////

///punchFollowLine(pow, change) test\\\
//firstRun = false;
//while(punchFollowLine(45));	///RUN FOR 5 SECONDS
//KillALL();

//Autonomous start///////////////////////////////////
//ARM ANGLE FUNCTION
clawStatus(1);														//CLOSE CLAW
SensorValue[ArmEnc]=0;
while(ArmAngle(230,127)){clawStatus(1);Move(2, 90);}	//MOVE ARM UP
//wait1Msec(250);
SensorValue[LeftEnc]=0;
clawStatus(0);
while(MoveDist(34, 90)){}								//DRIVE FORWARD (INTIL WALL)

SensorValue[LeftEnc]=0;									//MOVE BACK
while(MoveDist(-3, 50)){}
Break(-150, 8);
//wait1Msec(500);
TurnDegree(75, 40);												//TURN TOWARDS LINE
SensorValue[Gyro]=0;
while(LineStatusMiddle()!=1){Move(1, 30);
	if(abs(SensorValue[Gyro])>(200*10))break;
}
StopDrive();

while(punchFollowLine(35, 0.0145) && LineStatusLeft()==1);
StopDrive();
clearTimer(T2);
SensorValue[ArmEnc]=0;
clawStatus(1);
while(ArmAngle(-100,40)){clawStatus(1);}	//ARM DOWN CLOSE CLAW
MoveArm(8);
wait1Msec(50);
clearTimer(T2);
while(punchFollowLine(25, 0.008));
StopDrive();

/////SECOND PART TESTING
//SensorValue[ArmEnc]=0;
//while(ArmAngle(170,100));
//wait1Msec(1000);
//MoveTime(2500, 25);
//StopDrive();
//////////////////////////
////ACTUAL CODE
SensorValue[leftEnc]=0;
while(MoveDist(-7, 40));
TurnDegree(90, 40);
//BREAK THE TURN
Move(-1, 20);
wait1Msec(250);
StopDrive();
//FORWARD UNTIL LINE
while(SensorValue[midLine]>1000){Move(2, 30);}
stopArm();
while(MoveDist(7, 30));
//TURN
TurnDegree(90, 50);
MoveTime(1000, -60);
//BREAK THE TURN
//Move(-1, 15);
//wait1Msec(250);
//StopDrive();
////////////////
clawStatus(0);
///////////////
//GRAB CUBE
SensorValue[LeftEnc]=0;
while(MoveDist(55, 100));
clawStatus(1);
//ARM UP
SensorValue[ArmEnc]=0;
while(ArmAngle(150, 100)){}
//
SensorValue[LeftEnc]=0;
while(MoveDist(77, 100));
while(MoveDist(-5, 40));
TurnDegree(-90, 55);
Move(1, 15);
wait1Msec(250);
StopDrive();
//DUMP CUBE
SensorValue[LeftEnc]=0;
SensorValue[ArmEnc]=0;
//Dumping Cube Step by step
while(MoveDist(-32, 80)){}
SensorValue[ArmEnc]=0;
while(ArmAngle(280, 127));
///////////////////////////////
//while(MoveDist(-32, 80)){
//if(SensorValue[ArmEnc]<900) MoveArm(80);
//else	StopArm();
//}
stopArm();
clawStatus(0);

////GET STAR//
SensorValue[ArmEnc]=0;
while(ArmAngle(-250, 127));
StopArm();
SensorValue[LeftEnc]=0;
while(moveDist(37, 60));
clawStatus(1);
//DUMP STAR///////////////
SensorValue[LeftEnc]=0;
SensorValue[ArmEnc]=0;
while(MoveDist(-37, 90)){
	if(SensorValue[ArmEnc]<1200) MoveArm(127);
	else	MoveArm(-8);
}
stopArm();
clawStatus(0);
///////////////////////

//Get MIDDLE STARS
SensorValue[ArmEnc]=0;
while(ArmAngle(-15, 30));
StopArm();

//SensorValue[LeftEnc]=0;
//while(moveDist(50, 60));
//StopArm();

TurnDegree(-90, 55);
SensorValue[ArmEnc]=0;
while(ArmAngle(-280, 127));
StopArm();

SensorValue[LeftEnc]=0;
while(MoveDist(30, 90));
TurnDegree(-12, 40);

SensorValue[LeftEnc]=0;
while(MoveDist(70, 90));
clawStatus(1);

wait1Msec(500);
//Through middle stars
SensorValue[LeftEnc]=0;
while(MoveDist(-5, 40));

SensorValue[ArmEnc]=0;
while(ArmAngle(150, 100));

TurnDegree(90, 45);

SensorValue[LeftEnc]=0;
while(moveDist(-65, 60));

SensorValue[LeftEnc]=0;
SensorValue[ArmEnc]=0;
while(MoveDist(-32, 127)){
	if(SensorValue[ArmEnc]<700) MoveArm(127);
	else	StopArm();
}
stopArm();
clawStatus(0);

while(1);
