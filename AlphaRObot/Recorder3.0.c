// by Jason Becker
// since 12/11/16
// for VCAT Robotics

//~~~~~~~~~~~~This code should be called from the Driver Control using #include"Recorder3.0.c"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
#pragma DebuggerWindows("debugStream")
task main //Task Main used only to test the code
clearDebugStream(); //MAKE SURE THIS LINE IS ADDED IN MAIN CODE TO RESET STREAM
while(1)
{*/
//MAKE SURE #pragma DebuggerWindows("debugStream") IS IN MAIN CODE
int Time=100;	//in Ms how often will the program check conditions and also how long the driver controls wll be delayed for
if (vexRT[Ch1]>10||vexRT[Ch1]<-10) //theses values can be changed based on bandwidth
{writeDebugStreamLine("vexRT[Ch1]=%d;", vexRT[Ch1]);}
if (vexRT[Ch2]>10||vexRT[Ch2]<-10)
{writeDebugStreamLine("vexRT[Ch2]=%d;", vexRT[Ch2]);}
if (vexRT[Ch3]>10||vexRT[Ch3]<-10)
{writeDebugStreamLine("vexRT[Ch3]=%d;", vexRT[Ch3]);}
if (vexRT[Ch4]>10||vexRT[Ch4]<-10)
{writeDebugStreamLine("vexRT[Ch4]=%d;", vexRT[Ch4]);}
if (vexRT[Btn5U]>0)
{writeDebugStreamLine("vexRT[Btn5U],%d;", vexRT[Btn5U]);}
if (vexRT[Btn5D]>0)
{writeDebugStreamLine("vexRT[Btn5D]=%d", vexRT[Btn5D]);}
if (vexRT[Btn6U]>0)
{writeDebugStreamLine("vexRT[Btn6U]=%d", vexRT[Btn6U]);}
if (vexRT[Btn6D]>0)
{writeDebugStreamLine("vexRT[Btn6D]=%d", vexRT[Btn6D]);}
if (vexRT[Btn7U]>0)
{writeDebugStreamLine("vexRT[Btn7U]=%d", vexRT[Btn7U]);}
if (vexRT[Btn7D]>0)
{writeDebugStreamLine("vexRT[Btn7D]=%d", vexRT[Btn7D]);}
if (vexRT[Btn7L]>0)
{writeDebugStreamLine("vexRT[Btn7L]=%d", vexRT[Btn7L]);}
if (vexRT[Btn7R]>0)
{writeDebugStreamLine("vexRT[Btn7R]=%d", vexRT[Btn7R]);}
if (vexRT[Btn8U]>0)
{writeDebugStreamLine("vexRT[Btn8U]=%d", vexRT[Btn8U]);}
if (vexRT[Btn8D]>0)
{writeDebugStreamLine("vexRT[Btn8D]=%d", vexRT[Btn8D]);}
if (vexRT[Btn8L]>0)
{writeDebugStreamLine("vexRT[Btn8L]=%d", vexRT[Btn8L]);}
if (vexRT[Btn8R]>0)
{writeDebugStreamLine("vexRT[Btn8R]=%d", vexRT[Btn8R]);}
writeDebugStreamLine("wait1Msec(%d);", Time);
wait1Msec(Time);//wait for Time before checking the button values again. the way this is currently coded this may also pause the driving controls while recording
//}
//}
