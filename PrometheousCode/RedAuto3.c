void RedAuto3(void)
{
	//GO FOR CUBE FIRST(BLUE LEFT, RED RIGHT)

//MOVE UNTIL LINE
while(MoveDist(6, 45, 2500));
while(LineStatusLeft()!=1&&LineStatusMiddle()!=1&&LineStatusRight()!=1){Move(2, 40);}
StopDrive();
//TURN AND ALIGN WITH LINE
TurnDegree(-90, 50);
clawStatus(1);				//DROP CLAW
MoveTime(1500, -60);
//OPEN CLAW
clawStatus(0);
//PICK UP CUBE
while(MoveDist(55, 100, 3500));
clawStatus(1);
while(ArmAngle(150, 100)){}
//DRIVE TO OTHER SIDE OF FIELD
while(MoveDist(77, 100, 5000));
while(MoveDist(-5, 40, 5000));
//Dumping Cube Step by step
TurnDegree(-90, 60);
while(MoveDist(-32, 80, 3500));
while(ArmAngle(280, 127));
Move(-2, 30);	//KEEP BACKING UP UNTIL TURN
clawStatus(0);
wait1Msec(500);
//TURN AND GET THE FENSE STARS
while(ArmAngle(-250, 127));
SensorValue[Gyro]=0;
while(LineStatusMiddle()!=1){Move(-1, 30);		//PUT FAIL SAFE USING TIME
	if(abs(SensorValue[Gyro])>(200*10))break;
}
StopDrive();
//FOLLOW LINE AND PUNCH STARS
//clawStatus(1);
while(punchFollowLine(35, 0.0145, 5000) && LineStatusRight()==1);
StopDrive();
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
}
StopDrive();
//TURN TO GET STARS
while(MoveDist(-7, 40, 1000));
TurnDegree(90, 40);
//BREAK THE TURN
Move(-1, 20);
wait1Msec(250);
StopDrive();
//GET STAR
while(ArmAngle(-250, 127));
StopArm();
while(moveDist(37, 60, 3000));
clawStatus(1);
wait1Msec(500);
//DUMP STAR///////////////
SensorValue[ArmEnc]=0;
while(MoveDist(-37, 90, 3500)){
	if(SensorValue[ArmEnc]<1100) MoveArm(127);
	else	MoveArm(-8);
}
clawStatus(0);
//wait1Msec(500);
//BRING ARM DOWN
while(ArmAngle(-80, 45));
//StopArm();

//while(moveDist(50, 60, 3000));
while(MoveSonar(10, 40, 3500);

TurnDegree(85, 50);
MoveArm(-90);
wait1Msec(800);
StopArm();

while(MoveDist(30, 90, 2500));
TurnDegree(12, 40);

while(MoveDist(70, 90, 4000));
clawStatus(1);

wait1Msec(500);

//TURN TO DUMP
while(MoveDist(-5, 40, 2000));
while(ArmAngle(180, 100));

TurnDegree(-90, 50);
Move(1, 10);
wait1Msec(250);
StopDrive();

while(moveDist(-65, 75, 2500));

clearTimer(T2);
//ARM UP TO DUMP STARS
while(ArmAngle(220, 127));
stopArm();
clawStatus(0);

wait1Msec(500);

//Bring Arm Down
while(ArmAngle(-300, 127));
StopArm();
///////////////////////

while(1);


}
