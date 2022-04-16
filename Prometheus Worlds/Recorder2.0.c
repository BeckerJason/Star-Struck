// by Jason Becker
// since 12/11/16
// for VCAT Robotics

while(1)
{
int A,D3,D4,C;
//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE

int T=20;	//  TIME   in Ms how often will the program check conditions

if (vexRT[Ch2]>10||vexRT[Ch2]<-10)
{	A=vexRT[Ch2];}
else if (vexRT[Btn5D]>0){A=-127;}
else
{A=0;}

if (abs(vexRT[Ch3])>10||abs(vexRT[Ch4])>10)
{D3=vexRT[Ch3]; D4=vexRT[Ch4];
	}
	else {D3=0;D4=0;}
	if(vexRT[Btn6U]==1){SensorValue[clawR]=1;	SensorValue[clawL]=1;
		C=1;}
		else{SensorValue[clawR]=0;	SensorValue[clawL]=0;
		C=0;
		}

writeDebugStreamLine("F(%d,%d,%d,%d,%d);",A,D3,D4,C,T);
F(A,D3,D4,C,T);
//wait for Time before checking the button values again. the way this is currently coded this will also pause the driving controls while recording
//#include Stop //inclue Stop.c which stops all motors
//}
}
