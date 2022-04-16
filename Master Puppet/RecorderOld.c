// by Jason Becker
// since 12/11/16
// for VCAT Robotics

//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE
//int Time=1000;	//in Ms how often will the program check conditions
PistonAuto();
writeDebugStreamLine("PistonAuto();");
while(1)
{
//if (abs(vexRT[Ch1])>10) //theses values can be changed based on bandwidth
//{writeDebugStreamLine("vexRT[Ch1]=%d);", vexRT[Ch1]);}

if (abs(vexRT[Ch2])>10)
{writeDebugStreamLine("CalypsoArm(%d);", vexRT[Ch2]);
	CalypsoArm(vexRT[Ch2]);}

if(abs(vexRT[Ch3]) > 10 || abs(vexRT[Ch4]) > 15)
{writeDebugStreamLine("CalypsoDrive(%d,%d);",vexRT[Ch3], vexRT[Ch4]);
	CalypsoDrive(vexRT[Ch3],vexRT[Ch4]);}



if (vexRT[Btn5U]>0||vexRT[Btn6U])
{SensorValue[pis1] = 1;
	writeDebugStreamLine("SensorValue[pis1] = 1");}
else {SensorValue[pis1] = 0;
	writeDebugStreamLine("SensorValue[pis1] = 0");}

//if (vexRT[Btn5D]>0)
//{writeDebugStreamLine("vexRT[Btn5D]=%d", vexRT[Btn5D]);}
//if (vexRT[Btn6U]>0)
//{writeDebugStreamLine("vexRT[Btn6U]=%d", vexRT[Btn6U]);}
//if (vexRT[Btn6D]>0)
//{writeDebugStreamLine("vexRT[Btn6D]=%d", vexRT[Btn6D]);}
//if (vexRT[Btn7U]>0)
//{writeDebugStreamLine("vexRT[Btn7U]=%d", vexRT[Btn7U]);}
//if (vexRT[Btn7D]>0)
//{writeDebugStreamLine("vexRT[Btn7D]=%d", vexRT[Btn7D]);}
//if (vexRT[Btn7L]>0)
//{writeDebugStreamLine("vexRT[Btn7L]=%D", vexRT[Btn7L]);}
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
//////////////////////////////////////////////////////////////////////////


//if (abs(vexRT[Ch1Xmtr2])>10) //theses values can be changed based on bandwidth
//{writeDebugStreamLine("vexRT[Ch1Xmtr2]=%d);", vexRT[Ch1Xmtr2]);} //Time is an assumption of how long the button value is given based on

if (abs(vexRT[Ch2Xmtr2])>10)
{writeDebugStreamLine("AtlasArm(%d);", vexRT[Ch2Xmtr2]);
	AtlasArm(vexRT[Ch2Xmtr2]);}

if(abs(vexRT[Ch3Xmtr2]) > 10 || abs(vexRT[Ch4Xmtr2]) > 15)
{
	writeDebugStreamLine("AtlasDrive(%d,%d);",vexRT[Ch3Xmtr2], vexRT[Ch4Xmtr2]);
	AtlasDrive(vexRT[Ch3Xmtr2],vexRT[Ch4Xmtr2]);}

if (vexRT[Btn5UXmtr2]>0)
{writeDebugStreamLine("vexRT[Btn5UXmtr2]=%d;", vexRT[Btn5UXmtr2]);}
if (vexRT[Btn5DXmtr2]>0)
{writeDebugStreamLine("vexRT[Btn5DXmtr2]=%d", vexRT[Btn5DXmtr2]);}

if(vexRT[Btn6UXmtr2] == 1)
{SensorValue[pistonPuppet]=1;
	writeDebugStreamLine("SensorValue[pistonPuppet]=1;");	}
else
{SensorValue[pistonPuppet]=0;
	writeDebugStreamLine("SensorValue[pistonPuppet]=0;");}

//if (vexRT[Btn6DXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn6DXmtr2]=%d", vexRT[Btn6DXmtr2]);}
//if (vexRT[Btn7UXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn7UXmtr2]=%d", vexRT[Btn7UXmtr2]);}
//if (vexRT[Btn7DXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn7DXmtr2]=%d", vexRT[Btn7DXmtr2]);}
//if (vexRT[Btn7LXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn7LXmtr2]=%d", vexRT[Btn7LXmtr2]);}
//if (vexRT[Btn7RXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn7RXmtr2]=%d", vexRT[Btn7RXmtr2]);}
//if (vexRT[Btn8UXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn8UXmtr2]=%d", vexRT[Btn8UXmtr2]);}
//if (vexRT[Btn8DXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn8DXmtr2]=%d", vexRT[Btn8DXmtr2]);}
//if (vexRT[Btn8LXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn8LXmtr2]=%d", vexRT[Btn8LXmtr2]);}
//if (vexRT[Btn8RXmtr2]>0)
//{writeDebugStreamLine("vexRT[Btn8RXmtr2]=%d", vexRT[Btn8RXmtr2]);}




writeDebugStreamLine("wait1Msec(%d);", Time);
wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording
writeDebugStreamLine("Stop();");
Stop(); //inclue Stop.c which stops all motors
}
