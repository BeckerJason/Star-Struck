#define refreshRate 20

float DistanceTraveled = 0;

task DistanceTask()
{
float AccelValue;
float proportion = 1/(1000^2);
	while(1)
	{
		AccelValue = SensorValue[accel];
		DistanceTraveled += AccelValue*(refreshRate^2)*proportion;

		wait1Msec(refreshRate);
	}
}
