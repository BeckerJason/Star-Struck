void DebugCode(void)
{
//auto 1 c turn
//MoveArm(8);
//while(MoveDist(-7, 40, 1000));
//TurnDegree(90, 40);
//Move(-1, 10);
//wait1Msec(150);
//StopDrive();

////Auto 3 c turn
//while(MoveDist(6, 45, 2500));
//while(LineStatusLeft()!=1&&LineStatusMiddle()!=1&&LineStatusRight()!=1){Move(2, 40);}
//StopDrive();
//Break(150, 8);
//TurnDegree(-90, 50);
//clawStatus(1);
//MoveTime(1500, -60);

//while(SensorValue[midLine]>1000){Move(2, 35);}
//StopDrive();



///// previous program ////////////////////

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

while(1);
}



////////new program///////////////////

//MoveDist(25, 90, 2500);

//while(1){};
//}
