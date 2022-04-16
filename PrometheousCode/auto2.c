//BLUE, RIGHT. THROUGH 4 STARS GO FOR WALL

clawStatus(1);
SensorValue[ArmEnc]=0;
while(ArmAngle(180, 100));

//GET MIDDLE STARS
TurnDegree(-90, 55);
clawStatus(0);
//ARM DOWN
SensorValue[ArmEnc]=0;
while(ArmAngle(-160, 127));
StopArm();
wait1Msec(500);
/////////////////////////
SensorValue[LeftEnc]=0;
while(MoveDist(30, 90));
TurnDegree(12, 55);

clearTimer(T2);
SensorValue[LeftEnc]=0;
while(MoveDist(68, 90)){if(time1[T2]>3000)break;}
StopDrive();
clawStatus(1);

//Thorugh stars
SensorValue[LeftEnc]=0;
while(MoveDist(-5, 40));

SensorValue[ArmEnc]=0;
while(ArmAngle(180, 100));

TurnDegree(-90, 50);
Move(1, 10);
wait1Msec(250);
StopDrive();

clearTimer(T2);
SensorValue[LeftEnc]=0;
while(moveDist(-65, 75)){if(time1[T2]>2500)break;}

clearTimer(T2);
SensorValue[LeftEnc]=0;
SensorValue[ArmEnc]=0;
while(MoveDist(-32, 127)){
if(SensorValue[ArmEnc]<450) MoveArm(127);
else{StopArm();}
if(time1[T2]>2500)break;
}
stopArm();
clawStatus(0);

wait1Msec(1000);

//Bring Arm Down
SensorValue[ArmEnc]=0;
while(ArmAngle(-200, 127));
//StopArm();

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
clearTimer(T2);
while(punchFollowLine(35, 0.0145) && LineStatusRight()==1);
StopDrive();
clearTimer(T2);
while(punchFollowLine(25, 0.008));
StopDrive();

//GET CUBE
SensorValue[leftEnc]=0;
while(MoveDist(-7, 40));
TurnDegree(90, 40);

while(SensorValue[midLine]>1000){Move(2, 30);}
stopArm();
while(MoveDist(7, 30));
//TURN
TurnDegree(90, 50);
MoveTime(1000, -60);
//
clawStatus(0);
///////////////
//GRAB CUBE
SensorValue[LeftEnc]=0;
while(MoveDist(55, 100));
clawStatus(1);
//ARM UP
SensorValue[ArmEnc]=0;
while(ArmAngle(150, 100)){}

TurnDegree(-90, 60);

SensorValue[LeftEnc]=0;
SensorValue[ArmEnc]=0;
//Dumping Cube Step by step
clearTimer(T2);
while(MoveDist(-32, 80)){if(time1[T2]>2500)break;}
StopDrive();
SensorValue[ArmEnc]=0;
while(ArmAngle(280, 127));

clawStatus(0);
wait1Msec(1000);
//Arm back down
SensorValue[ArmEnc]=0;
while(ArmAngle(-280, 100));
StopArm();
