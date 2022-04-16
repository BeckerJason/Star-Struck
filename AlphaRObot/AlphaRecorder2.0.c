// bxRTy Jason Becker
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

void AlphaRecorder(){//USE THIS VOID IF RUNNING IN DRIVER CONTROL
	//~~~~~~~~~~~~This code should be called from the Driver Control using #include"Recorder3.0.c"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/*
#pragma DebuggerWindows("debugStream")
	task main //Task Main used only to test the code
	clearDebugStream(); //MAKE SURE THIS LINE IS ADDED IN MAIN CODE TO RESET STREAM
	while(1)
	{*/

	//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE

	int Time=100;	//in Ms how often will the program check conditions and also how long the driver controls wll be delayed for
	//if (ve[Ch1]>10||vexRT[Ch1]<-10) //theses values can be changed based on bandwidth
	//{writeDebugStreamLine("vexRT[Ch1]=%d;", vexRT[Ch1]);}
	if (vexRT[Ch2]>10||vexRT[Ch2]<-10)
	{writeDebugStreamLine("value(%d);", vexRT[Ch2]);}
	if(vexRT[Ch3]> 10 || vexRT[Ch4]||vexRT[Ch1]  > 10 || vexRT[Ch3]< -10 || vexRT[Ch4] ||vexRT[Ch1] < -10) //JOYSTICK DEADBAND
	{
		writeDebugStreamLine("values(%d,%d);", vexRT[Ch3], vexRT[Ch4]);
	}
	//if (vexRT[Btn5U]>0)
	//{writeDebugStreamLine("vexRT[Btn5U],%d;", vexRT[Btn5U]);}
	//if (vexRT[Btn5D]>0)
	//{writeDebugStreamLine("vexRT[Btn5D]=%d", vexRT[Btn5D]);}
	writeDebugStreamLine("SensorValue[clawR]=%d;	SensorValue[clawL]=%d;",vexRT[Btn6U],vexRT[Btn6U]);    //This is in place of the "if (vexRT[Btn6U]==0)" code
	//if (vexRT[Btn6U]==0)
	//{writeDebugStreamLine("SensorValue[clawR]=0;	SensorValue[clawL]=0;");}
	//if (vexRT[Btn6D]>0)
	//{writeDebugStreamLine("vexRT[Btn6D]=%d", vexRT[Btn6D]);}
	//if (vexRT[Btn7U]>0)
	//{writeDebugStreamLine("vexRT[Btn7U]=%d", vexRT[Btn7U]);}
	//if (vexRT[Btn7D]>0)
	//{writeDebugStreamLine("vexRT[Btn7D]=%d", vexRT[Btn7D]);}
	//if (vexRT[Btn7L]>0)
	//{writeDebugStreamLine("vexRT[Btn7L]=%d", vexRT[Btn7L]);}
	//if (vexRT[Btn7R]>0)
	//{writeDebugStreamLine("vexRT[Btn7R]=%d", vexRT[Btn7R]);}
	//if (vexRT[Btn8U]>0)
	//{writeDebugStreamLine("vexRT[Btn8U]=%d", vexRT[Btn8U]);}
	//if (vexRT[Btn8D]>0)
	//{writeDebugStreamLine("vexRT[Btn8D]=%d", vexRT[Btn8D]);}
	//if (vexRT[Btn8L]>0)
	//{writeDebugStreamLine("vexRT[Btn8L]=%d", vexRT[Btn8L]);}
	//if (vexRT[Btn8R]>0)
	//{writeDebugStreamLine("vexRT[Btn8R]=%d", vexRT[Btn8R]);}
	writeDebugStreamLine("wait1Msec(%d);", Time);

	//ClearTimer(T1);              //THIS SECTION IS A TEST
	//while(time1[T1] < Time)
	//{DriverControlsTestVoid();}

	wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording

	//}
	//}
}
