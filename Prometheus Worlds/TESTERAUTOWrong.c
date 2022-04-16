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
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
Dist( -1468, 1, 127, 2000);
Break(150,70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(260, 1, 127, 2000);
ArmRun(15);
wait1Msec(150);
Dist( -239, 1, 127, 2000);
Break(150,70);
wait1Msec(150);
TurnDegree(-135, 70, 0);
TurnBreak(100, 70);
wait1Msec(150);
Dist( 956, 0, 127, 0);
Break(150,-70);
wait1Msec(150);
TurnDegree(45, 70, 0);
TurnBreak(50, -70);
wait1Msec(150);
SensorValue[Gyro]=0;
Dist( 649, 0, 127, 0);
Break(150,-70);
wait1Msec(150);
ArmPosition(385, 1, 127, 0);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-676, 0, 45, 2000);
wait1Msec(150);
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
Dist( -649, 1, 127, 2000);
FixDegree(SensorValue[Gyro],30,2000);//Robot is Grabbing cube and sets itself straight
wait1Msec(150);
ClawStatus(1);
wait1Msec(150);
//ThrowDist( 649, 0, 127, 3000,612, 1, 127);//~~~~~~~~~~~~~~~~~~~~
Dist( 649, 0, 127, 2000);												//*****Replaced
wait1Msec(150);																	//*****BY
ArmPosition(612, 1, 127, 1500);									//*****ThrowDist
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-930, 0, 45, 1500);
//wait1Msec(150);



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
Dist( 698, 0, 70, 1500);
Break(100,-70);
wait1Msec(150);
Dist( -59, 1, 70, 0);
Break(100,70);
wait1Msec(150);
TurnDegree(-90, 70, 1500);
TurnBreak(50, 70);
wait1Msec(150);
Dist( -1374, 1, 70, 1500);
Break(100,70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(281, 1, 90, 1500);
ArmRun(15);
wait1Msec(150);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(150);
ArmPosition(452, 1, 90, 1500);
ArmRun(15);

ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-1003, 0, 45, 1500);
wait1Msec(150);
Dist( 182, 0, 70, 1500);
Break(100,-70);
wait1Msec(150);
ClawStatus(1);
ArmPosition(646, 1, 90, 1500);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(150);
ArmPosition(-863, 0, 45, 1500);
wait1Msec(150);

/*
SensorValue[LeftEnc]=0;
SensorValue[RightEnc]=0;
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
ClawStatus(1);
wait1Msec(300);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
Dist( -600*2.5, 1, 50, 4000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
ArmPosition(250, 1, 90, 2000);
ArmRun(15);
wait1Msec(300);
Dist( -100*2.5, 1, 50, 2000);
Break(100,70);
wait1Msec(300);
TurnDegree(-143, 70,2000);
TurnBreak(100, 70);
wait1Msec(300);
Dist(550*2.5, 0, 50, 2000);
Break(100,-70);
wait1Msec(300);
TurnDegree(47, 70,2000);
TurnBreak(100,-70);
wait1Msec(300);
Dist( 450*2.5, 0, 50, 2000);
Break(100,-70);
wait1Msec(300);
SensorValue[Gyro]=0;//RESET GYRO
ArmPosition(435, 1, 127, 2000);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-899, 0, 45, 2000);
wait1Msec(300);
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
//SensorValue[Gyro]=0;//RESET GYRO
Dist( -581*2.5, 1, 50, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
//SensorValue[Gyro]=0;//RESET GYRO
Dist( 659*2.5, 0, 50, 2000);
Break(100,-70);
wait1Msec(300);
ArmPosition(671, 1, 270, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-863, 0, 45, 2000);
wait1Msec(300);
/////////////////////////////////////////////////////////////////PRELOADS
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
//SensorValue[Gyro]=0;//RESET GYRO
Dist( -581*2.5, 1, 50, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
FixDegree(SensorValue[Gyro],30,2000);//Robot is holding cube, straightens to wall
SensorValue[Gyro]=0;//RESET GYRO
Dist( 659*2.5, 0, 50, 2000);
Break(100,-70);
wait1Msec(300);
ArmPosition(671, 1, 270, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-863, 0, 45, 2000);
wait1Msec(300);
///////////////////////////////////////////////////////////////Preload part 2
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
SensorValue[Gyro]=0;//RESET GYRO
Dist( -581*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
FixDegree(SensorValue[Gyro],30,2000);//Robot is holding cube, straightens to wall
SensorValue[Gyro]=0;//RESET GYRO
Dist( 659*2.5, 0, 70, 2000);
Break(100,-70);
wait1Msec(300);
ArmPosition(671, 1, 270, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-863, 0, 45, 2000);
wait1Msec(300);
/////////////////////////////Preload part3
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
SensorValue[Gyro]=0;//RESET GYRO
Dist( -581*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
FixDegree(SensorValue[Gyro],30,2000);//Robot is holding cube, straightens to wall
SensorValue[Gyro]=0;//RESET GYRO
Dist( 659*2.5, 0, 70, 2000);
Break(100,-70);
wait1Msec(300);
ArmPosition(671, 1, 270, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-863, 0, 45, 2000);
wait1Msec(300);
/////////////////////////////////////////////Continue routine

Dist( 26*2.5, 0, 70, 2000);
Break(100,-70);
FixDegree(SensorValue[Gyro],30,2000);//Robot is sitting in front of wall and sets itself straight
TurnBreak(100,-70);
wait1Msec(300);
TurnDegree(-90, 70, 1500);
TurnBreak(50, 70);
wait1Msec(300);
Dist( -638*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
ArmPosition(252, 1, 90, 2000);
ArmRun(15);
wait1Msec(300);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(300);
ArmPosition(255, 1, 90, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-870, 0, 45, 2000);
wait1Msec(300);
ClawStatus(1);
ArmPosition(722, 1, 90, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-1014, 0, 45, 2000);
wait1Msec(300);
Dist( 235*2.5, 0, 70, 2000);
Break(100,-70);
wait1Msec(300);
Dist( 0, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
TurnDegree(-90, 70, 1500);
TurnBreak(50, 70);
wait1Msec(300);
Dist( -606*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
Dist( -166*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(300);
Dist( -505*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
Dist( 464*2.5, 0, 70, 2000);
Break(100,-70);
wait1Msec(300);
ArmPosition(686, 1, 90, 2000);
ArmRun(15);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
wait1Msec(300);
ArmPosition(-842, 0, 45, 1000);
wait1Msec(300);
Dist( 409*2.5, 0, 70, 2000);
Break(100,-70);
wait1Msec(300);
//////////////////////////////////////////////Middle Cube Grabbed above
Dist( -76*2.5, 1, 70, 2000);
Break(100,70);
wait1Msec(300);
TurnDegree(-90, 70, 1500);
TurnBreak(50, 70);
wait1Msec(300);
Dist( -635*2.5, 1, 70, 1500);
Break(100,70);
wait1Msec(300);
ClawStatus(1);
Dist( 53*2.5, 0, 70, 1500);
Break(100,-70);
wait1Msec(300);
TurnDegree(90, 70, 1500);
TurnBreak(50, -70);
wait1Msec(300);
TurnDegree(-18, 70, 2000);
TurnBreak(100, 70);
wait1Msec(300);
ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
Dist( -372*2.5, 1, 70, 1500);
Break(100,70);
//wait1Msec(300);
//ClawStatus(1);
//ArmPosition(191, 1, 90, 0);
//ArmRun(15);
//wait1Msec(300);
//Dist( 444, 0, 70, 0);
//Break(100,-70);
//wait1Msec(300);
//ArmPosition(362, 1, 90, 0);
//ArmRun(15);
//wait1Msec(300);
//ClawStatus(0);			//Move wait timer that is above this line, to bellow this line
//ArmPosition(-869, 0, 45, 0);
//wait1Msec(300);
//TurnDegree(90, 70, 1500);
//TurnBreak(50, -70);
//wait1Msec(300);
//TurnDegree(90, 70, 1500);
//TurnBreak(50, -70);
//wait1Msec(300);
//Dist( 553, 0, 70, 0);
//Break(100,-70);*/
