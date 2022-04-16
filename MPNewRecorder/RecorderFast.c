// by Jason Becker
// since 12/11/16
// for VCAT Robotics

//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE
//int Time=1000;	//in Ms how often will the program check conditions
PistonAuto();
int ca,cd3,cd4,aa,ad3,ad4,pp,p1;
writeDebugStreamLine("PistonAuto();");
while(1)
{
	if (abs(vexRT[Ch2])>10)
	{ca=vexRT[Ch2];}
	else{ca=0;}

	if(abs(vexRT[Ch3]) > 10 || abs(vexRT[Ch4]) > 15)
{cd3=vexRT[Ch3];cd4=vexRT[Ch4];}
		else{cd3=0;cd4=0;}



	if (vexRT[Btn5U]>0||vexRT[Btn6U])
	{SensorValue[pis1] = 1;
		p1=1;}
	else {SensorValue[pis1] = 0;
				p1=0;}

	//////////////////////////////////////////////////////////////////////////


	if (abs(vexRT[Ch2Xmtr2])>10)
{aa=vexRT[Ch2Xmtr2];}
else{aa=0;}

	if(abs(vexRT[Ch3Xmtr2]) > 15 || abs(vexRT[Ch4Xmtr2]) > 15)
	{
		ad3=vexRT[Ch3Xmtr2];
		ad4=vexRT[Ch4Xmtr2];
	}
	else
	{ad3=0;
		ad4=0;}


	if(vexRT[Btn6UXmtr2] == 1)
	{SensorValue[pP]=1;
		pp=1;	}
	else
	{SensorValue[pP]=0;
		pp=0;}

writeDebugStreamLine("F(%d,%d,%d,%d,%d,%d,%d,%d);",ca,cd3,cd4,aa,ad3,ad4,pp,p1);
F(ca,cd3,cd4,aa,ad3,ad4,pp,p1);
	writeDebugStreamLine("wait1Msec(%d);", Time);
	wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording
	writeDebugStreamLine("Stop();");
	Stop(); //inclue Stop.c which stops all motors
}
