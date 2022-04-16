void BlueAuto5(void)
{
KillALL();
	clawStatus(1);
	while(ArmAngle(240,127)){clawStatus(1);Move(2, 90);}
	clawStatus(0);
	while(MoveDist(36, 90, 2500)){}

	while(MoveDist(-24, 45, 3000)){}
	StopDrive();
//	while(LineStatusLeft()!=1&&LineStatusMiddle()!=1&&LineStatusRight()!=1){Move(-2, 40);}
//StopDrive();
//Break(150, 8);
while(ArmAngle(-100, 127));
StopArm();
//TURN AND ALIGN WITH LINE
TurnDegree(-90, 50);
clawStatus(1);				//DROP CLAW
MoveTime(1500, -60);
	clawStatus(0);
	while(MoveDist(70, 60, 5000));
	clawStatus(1);

while(ArmAngle(150, 100)){}
//while(SensorValue[sonar]>15){Move(2, 85)};
Break(150, 13);
TurnDegree(-90, 55);
Move(1, 15);
wait1Msec(250);
StopDrive();
while(MoveDist(-32, 80, 3500)){}
while(ArmAngle(280, 127));
///////////////////////////////
stopArm();
clawStatus(0);
wait1Msec(500);
while(ArmAngle(-250, 127));
StopArm();
while(moveDist(37, 40, 3000));
clawStatus(1);
//DUMP STAR///////////////
SensorValue[ArmEnc]=0;
while(MoveDist(-37, 90, 3500)){
	if(SensorValue[ArmEnc]<1200) MoveArm(127);
	else	MoveArm(-8);
}
stopArm();
clawStatus(0);
wait1Msec(500);
while(ArmAngle(-150, 127));
stopArm();

//TurnDegree(-30, 40);												//TURN TOWARDS LINE
//SensorValue[Gyro]=0;
//while(LineStatusMiddle()!=1){Move(-1, 35);
//	if(abs(SensorValue[Gyro])>(200*10))break;
//}
//StopDrive();
//clawStatus(0);
//while(punchFollowLine(35, 0.0145, 5000) && LineStatusRight()==1);
//StopDrive();
//while(punchFollowLine(30, 0.008, 10500)){}

while(1);
}
