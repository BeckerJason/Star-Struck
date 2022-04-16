void DebugCode(void)
{
KillALL();
while(MoveDist(4,127,3000));

SensorValue[Gyro]=0;
wait1Msec(100);

pidMove(72);
clawStatus(1);
wait1Msec(150);
while(ArmAngle(200,100,3000));
if(FailSafeEngaged==1)
{
	while(MoveDist(-6,70,2000));
}

pidTurn(-90,0);

pidMove(-47);
SensorValue[Gyro]=0;
wait1Msec(100);

wait1Msec(1000);
while(ArmAngle(200,127,3000));
clawStatus(0);
wait1Msec(500);
while(ArmAngle(-150, 80, 3000);
StopArm();
wait1Msec(1000);
pidMove(24);
pidTurn(-90,0);
pidMove(48);
clawStatus(1);
wait1Msec(150);
while(ArmAngle(200, 100,3000));
SensorValue[Gyro]=0;
wait1Msec(100);
pidTurn(90,0);
pidMove(-20);
while(ArmAngle(200,127,3000));
clawStatus(0);
StopArm();
wait1Msec(500);
while(ArmAngle(-150,80,3000));
StopArm();
while(1);
}
