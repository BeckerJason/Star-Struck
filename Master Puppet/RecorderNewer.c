// by Jason Becker
// since 12/11/16
// for VCAT Robotics

task Recorder()
{int Time=100;

	if (abs(vexRT[Ch2])>10)
	{writeDebugStreamLine("CalypsoArm(%d);", vexRT[Ch2]);
		CalypsoArm(vexRT[Ch2]);}

	if(abs(vexRT[Ch3]) > 10 || abs(vexRT[Ch4]) > 15)
	{writeDebugStreamLine("CalypsoDrive(%d,%d);",vexRT[Ch3], vexRT[Ch4]);
		CalypsoDrive(vexRT[Ch3],vexRT[Ch4]);}



	if (vexRT[Btn5U]>0||vexRT[Btn6U])
	{SensorValue[pis1] = 1;
		writeDebugStreamLine("SensorValue[pis1] = 1;");}
	else {SensorValue[pis1] = 0;
		writeDebugStreamLine("SensorValue[pis1] = 0;");}

	//////////////////////////////////////////////////////////////////////////


	if (abs(vexRT[Ch2Xmtr2])>10)
	{writeDebugStreamLine("AtlasArm(%d);", vexRT[Ch2Xmtr2]);
		AtlasArm(vexRT[Ch2Xmtr2]);}

	if(abs(vexRT[Ch3Xmtr2]) > 10 || abs(vexRT[Ch4Xmtr2]) > 15)
	{
		writeDebugStreamLine("AtlasDrive(%d,%d);",vexRT[Ch3Xmtr2], vexRT[Ch4Xmtr2]);
		AtlasDrive(vexRT[Ch3Xmtr2],vexRT[Ch4Xmtr2]);}

	if(vexRT[Btn6UXmtr2] == 1)
	{SensorValue[pistonPuppet]=1;
		writeDebugStreamLine("SensorValue[pistonPuppet]=1;");	}
	else
	{SensorValue[pistonPuppet]=0;
		writeDebugStreamLine("SensorValue[pistonPuppet]=0;");}





	writeDebugStreamLine("wait1Msec(%d);", Time);
	wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording
	writeDebugStreamLine("Stop();");
	Stop(); //inclue Stop.c which stops all motors
}

task Atlas()
{int Time=100;
	while(1)
	{
		clearTimer[T3];
		while( T3< Time)
		{}
		if (abs(vexRT[Ch2Xmtr2])>10)
		{writeDebugStreamLine("AtlasArm(%d);", vexRT[Ch2Xmtr2]);
			AtlasArm(vexRT[Ch2Xmtr2]);}

		if(abs(vexRT[Ch3Xmtr2]) > 10 || abs(vexRT[Ch4Xmtr2]) > 15)
		{
			writeDebugStreamLine("AtlasDrive(%d,%d);",vexRT[Ch3Xmtr2], vexRT[Ch4Xmtr2]);
			AtlasDrive(vexRT[Ch3Xmtr2],vexRT[Ch4Xmtr2]);}

		if(vexRT[Btn6UXmtr2] == 1)
		{SensorValue[pistonPuppet]=1;
			writeDebugStreamLine("SensorValue[pistonPuppet]=1;");	}
		else
		{SensorValue[pistonPuppet]=0;
			writeDebugStreamLine("SensorValue[pistonPuppet]=0;");}
	}
}


task Calypso()
{int Time=100;
	while(1)
	{
		clearTimer[T4];
		while( T4< Time)
		{}
		if (abs(vexRT[Ch2])>10)
		{writeDebugStreamLine("CalypsoArm(%d);", vexRT[Ch2]);
			CalypsoArm(vexRT[Ch2]);}

		if(abs(vexRT[Ch3]) > 10 || abs(vexRT[Ch4]) > 15)
		{writeDebugStreamLine("CalypsoDrive(%d,%d);",vexRT[Ch3], vexRT[Ch4]);
			CalypsoDrive(vexRT[Ch3],vexRT[Ch4]);}



		if (vexRT[Btn5U]>0||vexRT[Btn6U])
		{SensorValue[pis1] = 1;
			writeDebugStreamLine("SensorValue[pis1] = 1;");}
		else {SensorValue[pis1] = 0;
			writeDebugStreamLine("SensorValue[pis1] = 0;");}
	}
}
