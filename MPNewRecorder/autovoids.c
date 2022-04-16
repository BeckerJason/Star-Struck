void F(int ca,int cd3,int cd4,int aa,int ad3,int ad4,int pp,int p1)
{
	motor[rightP] = ad3- ad4;
	motor[leftP] = ad3+ ad4;

		motor[rightFrontM] = cd3- cd4;
	motor[rightBackM] = cd3- cd4;
	motor[leftFrontM] =  cd3+ cd4;
	motor[leftBackM] =  cd3+ cd4;

	sensorValue[pP]=pp;

	sensorValue[pis1]=p1;

	motor[armLeftM] = ca;
motor[armRightM] = ca;

motor[armLeftP] = aa;
motor[armRightP] = aa;
}

void PistonAuto()
{writeDebugStreamLine("PistonAuto();");
	SensorValue[pis2] = 1;
	wait1Msec(500);
	SensorValue[pis2] = 0;}

//void AD(int c3, int c4)
//{
//	motor[rightP] = c3- c4;
//	motor[leftP] = c3+ c4;
//}

//void CD(int c3, int c4)
//{
//	motor[rightFrontM] = c3- c4;
//	motor[rightBackM] = c3- c4;
//	motor[leftFrontM] =  c3+ c4;
//	motor[leftBackM] =  c3+ c4;

//}

//void CP(int status)
//{sensorValue[pP]=status;}
//void CM(int status)
//{sensorValue[pis1]=status;}
//void CalypsoClaw(int value)
//{SensorValue[left]=value; SensorValue[right]=value;}

//void AtlasClaw(int value)
//{SensorValue[left]=value; SensorValue[right]=value;}

//void CA(int c2)
//{
//motor[armLeftM] = c2;
//motor[armRightM] = c2;
//}

//void AA(int c2)
//{
//motor[armLeftP] = c2;
//motor[armRightP] = c2;
//}

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
