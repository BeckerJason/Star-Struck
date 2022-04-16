// Jason Becker
// since 12/11/16
// for VCAT Robotics

/*void value(int value){
motor[leftArmM] =value;
motor[leftArmY] =value;
motor[rightArmM] =value;
motor[rightArmY] =value;}

void values(int value1, value2){    //Voids for autonvoids.c which should be changed when button assignments are changed
motor[LM] = value1 + value2;
motor[L1] = value1 + value2;
motor[L2] = value1 + value2;
motor[RM] = value1 - value2;
motor[R1] = value1 - value2;
motor[R2] = value1 - value2;}*/

//void AlphaRecorder(){//USE THIS VOID IF RUNNING IN DRIVER CONTROL
//~~~~~~~~~~~~This code should be called from the Driver Control using #include"Recorder3.0.c"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
#pragma DebuggerWindows("debugStream")
task main //Task Main used only to test the code
clearDebugStream(); //MAKE SURE THIS LINE IS ADDED IN MAIN CODE TO RESET STREAM*/
KillALL();
break;
while(1)
{
	DriverControlTestVoid();

	//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE

	//when ch4 >10 || <-10 robot is turning and ch3==0
	//record gyro start                        "gyrovalue=float gyroi"
	//check speed                               "ch4 = speed"
	//when turning stops record gyro position  "gyrovalue=float gyrof"
	//gyro= final-initial     "float gyrof"     gyrof-gyroi=float ticks'
	//          value of gyro/8= degrees
	//writeDebugStreamLine("TurnDegree(%d, %d);", degrees, speed);
	//



	float GyroF,GyroI;
	int Time=100;	//in Ms how often will the program check conditions and also how long the driver controls wll be delayed for
	//if (ve[Ch1]>10||vexRT[Ch1]<-10) //theses values can be changed based on bandwidth
	//{writeDebugStreamLine("vexRT[Ch1]=%d;", vexRT[Ch1]);}
	if (vexRT[Ch2]>10||vexRT[Ch2]<-10)
	{writeDebugStreamLine("value(%d);", vexRT[Ch2]);}
	else{writeDebugStreamLine("value(0);");}

	if(vexRT[Ch3]> 10 || vexRT[Ch4]  > 10 || vexRT[Ch3]< -10 || vexRT[Ch4] < -10) //JOYSTICK DEADBAND
	{
		if(vexRT[Ch4]> 10 ||vexRT[Ch4]<-10 && vexRT[Ch3]==0)
		{
			GyroI=GyroRecord();
			int speed = vexRT[Ch4];
			while (vexRT[Ch4]> 10 ||vexRT[Ch4]<-10 && vexRT[Ch3]==0)
			{
				DriverControlTestVoid();
			}
			GyroF=GyroRecord();
			float ticks=GyroF-GyroI;
			int degrees=ticks/8;
			writeDebugStreamLine("TurnDegree(%d, %d);", degrees, speed);
		}
		else
		{writeDebugStreamLine("values(%d,%d);", vexRT[Ch3], vexRT[Ch4]);}
	}
	else	if(vexRT[Btn7L]>0) //JOYSTICK DEADBAND
	{
		GyroI=GyroRecord();
		int speed = 70;			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~////////SET TURNING VOID SPEED HERE
		while (vexRT[Btn7L]> 0 ||vexRT[Btn7R]>0 && vexRT[Ch3]==0)
		{
			DriverControlTestVoid();
		}
		GyroF=GyroRecord();
		float ticks=GyroF-GyroI;
		int degrees=ticks/8;
		writeDebugStreamLine("TurnDegree(%d, %d);", degrees, speed);
	}
	else	if(vexRT[Btn7R]>0) //JOYSTICK DEADBAND
	{
		GyroI=GyroRecord();
		int speed = 70;			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~////////SET TURNING VOID SPEED HERE
		while (vexRT[Btn7L]> 0 ||vexRT[Btn7R]>0 && vexRT[Ch3]==0)
		{
			DriverControlTestVoid();
		}
		GyroF=GyroRecord();
		float ticks=GyroF-GyroI;
		int degrees=ticks/8;
		writeDebugStreamLine("TurnDegree(%d, %d);", degrees, speed);
	}
	else	if(vexRT[Btn7U]>0) //JOYSTICK DEADBAND
{
		writeDebugStreamLine("values(%d,%d);",70, 0);  											//SPEED SET HERE
	}
	else	if(vexRT[Btn7D]>0) //JOYSTICK DEADBAND
	{
		writeDebugStreamLine("values(%d,%d);",-70,0);												//SPEED SET HERE
	}
	else
	{writeDebugStreamLine("values(%d,%d);", vexRT[Ch3], vexRT[Ch4]);}																		//Deadband is used here
	//	writeDebugStreamLine("values(%d,%d);                      //Turning here", vexRT[Ch3], vexRT[Ch4]);}
	//	else
	//	{writeDebugStreamLine("values(%d,%d);", vexRT[Ch3], vexRT[Ch4]);}}																		//Deadband is used here
	//else
	//{writeDebugStreamLine("values(0,0);");}

	//if(vexRT[Ch3]> 10 || vexRT[Ch4]||vexRT[Ch1]  > 10 || vexRT[Ch3]< -10 || vexRT[Ch4] ||vexRT[Ch1] < -10) //JOYSTICK DEADBAND
	//{if(vexRT[Ch4]> 10 ||vexRT[Ch4]<-10)
	//	{writeDebugStreamLine("values(%d,%d);                      //Turning here", vexRT[Ch3], vexRT[Ch4]);}
	//	else
	//	{writeDebugStreamLine("values(%d,%d);", vexRT[Ch3], vexRT[Ch4]);}}																		//Deadband is used here
	//else
	//{writeDebugStreamLine("values(0,0);");}

	//if (vexRT[Btn5U]>0)
	//{writeDebugStreamLine("vexRT[Btn5U],%d;", vexRT[Btn5U]);}
	//if (vexRT[Btn5D]>0)
	//{writeDebugStreamLine("vexRT[Btn5D]=%d", vexRT[Btn5D]);}
	writeDebugStreamLine("SensorValue[clawR]=%d;	SensorValue[clawL]=%d;",vexRT[Btn6U],vexRT[Btn6U]);    //This is in place of the "if (vexRT[Btn6U]==0)" code
	//if (vexRT[Btn6U]==0)
	//{writeDebugStreamLine("SensorValue[clawR]=0;	SensorValue[clawL]=0;");}
	if (vexRT[Btn6D]>0)
	{writeDebugStreamLine("value(10)");}
	writeDebugStreamLine("wait1Msec(%d);", Time);

	//ClearTimer(T1);              //THIS SECTION IS A TEST
	//while(time1[T1] < Time)
	//{DriverControlsTestVoid();}
	DriverControlTestVoid();
	wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording

	//}
	//}
}
