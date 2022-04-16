void PistonAuto()
{writeDebugStreamLine("PistonAuto();");
	SensorValue[pis2] = 1;
	wait1Msec(500);
	SensorValue[pis2] = 0;}

void AtlasDrive(int c3, int c4)
{
	motor[rightP] = c3- c4;
	motor[leftP] = c3+ c4;
}

void CalypsoDrive(int c3, int c4)
{
	motor[rightFrontM] = c3- c4;
	motor[rightBackM] = c3- c4;
	motor[leftFrontM] =  c3+ c4;
	motor[leftBackM] =  c3+ c4;

}

//void CalypsoClaw(int value)
//{SensorValue[left]=value; SensorValue[right]=value;}

//void AtlasClaw(int value)
//{SensorValue[left]=value; SensorValue[right]=value;}

void CalypsoArm(int c2)
{
motor[armLeftM] = c2;
motor[armRightM] = c2;
}

void AtlasArm(int c2)
{
motor[armLeftP] = c2;
motor[armRightP] = c2;
}

void Stop(){
	motor[rightFrontM]=0;
	motor[rightP]=0;
	motor[armLeftP]=0;
	motor[armRightM]=0;
	motor[leftFrontM]=0;
	motor[leftBackM]=0;
	motor[armLeftM]=0;
	motor[armRightP]=0;
	motor[leftP]=0;
	motor[rightBackM]=0;}
