void moveArm( int pot, int speed )
{
	while( SensorValue[armpot] >= pot )
	{
		motor[ltl]=speed;
		motor[ltm]=speed;
		motor[ltt]=speed;
		motor[rtl]=speed;
		motor[rtm]=speed;
		motor[rtt]=speed;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void moveArms(int speed )
{
	while( SensorValue[armswitch]==0 )
	{
		motor[ltl]=speed;
		motor[ltm]=speed;
		motor[ltt]=speed;
		motor[rtl]=speed;
		motor[rtm]=speed;
		motor[rtt]=speed;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void armStall( int speed )
{
	motor[ltl]=speed;
	motor[ltm]=speed;
	motor[ltt]=speed;
	motor[rtl]=speed;
	motor[rtm]=speed;
	motor[rtt]=speed;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void moveClaw(int speed )
{
	while( SensorValue[clawswitch]==0 )
	{
		motor[clawr]=speed;
		motor[clawl]=speed;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void moveRob( int time, int speed )
{

	motor[rd]=-speed;
	motor[ld]=speed;
	wait1Msec(time);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void turnRob( int time, int speed, int direction ) // direction = -1 for left turn ; direction = 1 for right turn
{

	motor[rd]=speed;
	motor[ld]=speed*direction;
	wait1Msec(time);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void motorsOff()
{
	motor[ltl]=0;
	motor[ltm]=0;
	motor[ltt]=0;
	motor[rtl]=0;
	motor[rtm]=0;
	motor[rtt]=0;
	motor[rd]=0;
	motor[ld]=0;
	motor[clawl]=0;
	motor[clawr]=0;
}
