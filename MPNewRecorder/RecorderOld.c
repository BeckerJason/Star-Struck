// by Jason Becker
// since 12/11/16
// for VCAT Robotics

//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE
//int Time=1000;	//in Ms how often will the program check conditions
PistonAuto();
writeDebugStreamLine("PistonAuto();");
while(1)
{
if (abs(vexRT[Ch2])>10)
{writeDebugStreamLine("CA(%d);", vexRT[Ch2]);
	CA(vexRT[Ch2]);}

if(abs(vexRT[Ch3]) > 10 || abs(vexRT[Ch4]) > 15)
{writeDebugStreamLine("CD(%d,%d);",vexRT[Ch3], vexRT[Ch4]);
	CD(vexRT[Ch3],vexRT[Ch4]);}



if (vexRT[Btn5U]>0||vexRT[Btn6U])
{SensorValue[pis1] = 1;
	writeDebugStreamLine("CM(1)");}
else {SensorValue[pis1] = 0;
	writeDebugStreamLine("CM(0)");}

//////////////////////////////////////////////////////////////////////////


if (abs(vexRT[Ch2Xmtr2])>10)
{writeDebugStreamLine("AA(%d);", vexRT[Ch2Xmtr2]);
	AA(vexRT[Ch2Xmtr2]);}

if(abs(vexRT[Ch3Xmtr2]) > 10 || abs(vexRT[Ch4Xmtr2]) > 15)
{
	writeDebugStreamLine("AD(%d,%d);",vexRT[Ch3Xmtr2], vexRT[Ch4Xmtr2]);
	AD(vexRT[Ch3Xmtr2],vexRT[Ch4Xmtr2]);}


if(vexRT[Btn6UXmtr2] == 1)
{SensorValue[pP]=1;
	writeDebugStreamLine("CV(1);");	}
else
{SensorValue[pP]=0;
	writeDebugStreamLine("CV(0);");}


writeDebugStreamLine("wait1Msec(%d);", Time);
wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording
writeDebugStreamLine("Stop();");
Stop(); //inclue Stop.c which stops all motors
}
