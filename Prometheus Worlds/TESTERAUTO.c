////////////////////////////////////////////////////////
//Gyro resets Before Dist and Turning
//////////////////////////////////////
SensorValue[Gyro]=0;
//while(1){
//writeDebugStreamLine("(%d);",SensorValue[Gyro]);
////wait1Msec(2000);
////writeDebugStreamLine("(%d);",SensorValue[Gyro]);
////FixDegree(SensorValue[Gyro],70,2000);//Robot is holding cube, straightens to wall
SensorValue[ArmEnc]=0;

//}

ClawStatus(1);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(100, 1, 127, 500);
wait1Msec(150);
ArmPosition(-20, 0, 70, 500);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
Dist( -1468, 1, 127, 2000);
Break(150,70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(260, 1, 127, 2000);
ArmRun(15);
wait1Msec(300);
Dist( -239, 1, 127, 2000);
Break(150,70);
wait1Msec(300);
TurnDegree(-150, 70, 2000);
TurnBreak(70, 70);
wait1Msec(150);
Dist( 1400, 0, 127, 2000);
Break(150,-70);
wait1Msec(150);
TurnDegree(50, 50, 2000);
TurnBreak(50, -70);
wait1Msec(150);
SensorValue[Gyro]=0;
Dist( 500, 0, 127, 1500);
Break(150,-70);
wait1Msec(150);
ArmPosition(385, 1, 127, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-676, 0, 45, 2000);
wait1Msec(150);
FixDegree(SensorValue[Gyro],50,2000);//Robot is sitting in front of wall and sets itself straight
Dist( -700, 1, 127, 2000);
//FixDegree(SensorValue[Gyro],40,2000);//Robot is Grabbing cube and sets itself straight
wait1Msec(150);
ClawStatus(1);
wait1Msec(150);
//ThrowDist( 649, 0, 127, 3000,612, 1, 127);//~~~~~~~~~~~~~~~~~~~~
Dist( 700, 0, 127, 2000);												//*****Replaced
wait1Msec(150);																	//*****BY
ArmPosition(612, 1, 127, 1500);									//*****ThrowDist
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
//TurnDegree(-100, 70, 2500);
//TurnBreak(50, 70);
wait1Msec(150);
ArmPosition(-930, 0, 45, 1500);
//wait1Msec(150);

Dist( 698, 0, 70, 1500);
Break(100,-70);
wait1Msec(150);
Dist( -59, 1, 70, 500);
Break(100,50);
wait1Msec(150);
SensorValue[Gyro]=0;
TurnDegree(-100, 70, 2500);
TurnBreak(50, 70);
wait1Msec(150);
Dist( -1800, 1, 70, 1500);
Break(100,70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(281, 1, 127, 1500);
ArmRun(15);
wait1Msec(150);
TurnDegree(95, 70, 1500);
TurnBreak(50, -70);
wait1Msec(150);
ArmPosition(452, 1, 127, 1500);
ArmRun(15);

ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-200, 0, 45, 1500);
Dist( 182, 0, 70, 1500);
Break(100,-70);
ArmPosition(-800, 0, 45, 1500);
wait1Msec(150);
ClawStatus(1);
ArmPosition(646, 1, 127, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-863, 0, 45, 1000);
wait1Msec(150);



ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
Dist( 203, 0, 70, 1500);
Break(100,-70);
wait1Msec(300);
Dist( -132, 1, 70, 0);
Break(100,70);
wait1Msec(300);
TurnDegree(-90, 70, 1500);
TurnBreak(50, 70);
wait1Msec(300);
Dist( -1190, 1, 127, 0);
Break(100,70);
wait1Msec(300);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(300);
Dist( 501, 0, 70, 1500);
Break(100,-70);
wait1Msec(300);









////////////////////////////////////////////////////////////////PART 1
///ArmPosition(-100, 0, 70, 1500);						//GOES WITH LINE BELOW
//ThrowDist( -649, 1, 127, 2000,-830, 0, 45);//~~~~~~~~~~~~~~~~~~~~
Dist( -649, 1, 127, 2000);
wait1Msec(150);
ClawStatus(1);
wait1Msec(150);
ThrowDist( 649, 0, 127, 3000,612, 1, 127);//~~~~~~~~~~~~~~~~~~~~
//wait1Msec(150);
//ArmPosition(612, 1, 127, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-930, 0, 45, 1500);
wait1Msec(150);


////////////////////////////////////////////////////////////////PART 2
Dist( -649, 1, 127, 2000);
//FixDegree(SensorValue[Gyro],30,2000);//Robot is Grabbing cube and sets itself straight
wait1Msec(150);
ClawStatus(1);
wait1Msec(150);
ThrowDist( 649, 0, 127, 3000,612, 1, 127);//~~~~~~~~~~~~~~~~~~~~
//wait1Msec(150);
//ArmPosition(612, 1, 127, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-930, 0, 45, 1500);
wait1Msec(150);


////////////////////////////////////////////////////////////////PART 3
/*FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
Dist( -649, 1, 127, 2000);
//FixDegree(SensorValue[Gyro],30,2000);//Robot is Grabbing cube and sets itself straight
wait1Msec(150);
ClawStatus(1);
wait1Msec(150);
ThrowDist( 649, 0, 127, 3000,612, 1, 127);//~~~~~~~~~~~~~~~~~~~~
//wait1Msec(150);
//ArmPosition(612, 1, 127, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-930, 0, 45, 1500);
wait1Msec(150);*/



//////////////////////////////////////////////////////////////////




ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
ArmPosition(-230, 1, 127, 1500);
ArmRun(8);
wait1Msec(300);
Dist( -2031, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
Dist( 166, 0, 127, 1500);
Break(100,-70);
wait1Msec(300);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(300);
ArmPosition(190, 0, 45, 1500);
wait1Msec(300);
Dist( -2908, 1, 127, 2500);
Break(100,70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(-100, 1,127, 1500);
TurnBreak(100,-70);
wait1Msec(150);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(150);
Dist( 318, 0, 127, 3000);
Break(100,-70);
wait1Msec(150);
Dist( -492, 1, 127, 2500);
Break(100,70);
wait1Msec(150);
TurnDegree(90, 70, 3000);						//Turn 90 to face side wall
TurnBreak(50, -70);
wait1Msec(150);
Dist( 700, 0, 127, 2500);
Break(100,-70);
wait1Msec(150);
Dist( -488, 1, 127, 1500);
Break(100,70);
wait1Msec(150);
TurnDegree(-45, 70, 1500);          //Turn 45 to face pole
TurnBreak(50, -70);
wait1Msec(300);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line


ArmPosition(-700, 1,70, 1500);
ArmRun(-8);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
Dist( 850, 0, 70, 1500);
wait1Msec(300);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
ArmPosition(-150, 1, 90, 1500);
ArmRun(8);
wait1Msec(2000);
int speed=127;
					motor[LM] = speed;
					motor[L1] = speed;
					motor[L2] = speed;
					motor[RM] = speed;
					motor[R1] = speed;
					motor[R2] = speed;

ArmPosition(-952, 0, 127,3000);

speed=0;
					motor[LM] = speed;
					motor[L1] = speed;
					motor[L2] = speed;
					motor[RM] = speed;
					motor[R1] = speed;
					motor[R2] = speed;
					wait1Msec(400);
wait1Msec(300);
