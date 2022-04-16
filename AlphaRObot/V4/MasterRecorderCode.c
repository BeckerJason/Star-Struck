KillALL();
break;

while (1)
{
	if (vexRT[Btn6U]==1)
	{
		writeDebugStreamLine("ClawStatus(1);");
		writeDebugStreamLine("wait1Msec(100);");
		while (vexRT[Btn6U]==1)
		{
			ClawStatus(1);
		DrivingCode(15);
		}
	}
	else if (vexRT[Btn6U]==0)
	{
		writeDebugStreamLine("ClawStatus(0);");
		while (vexRT[Btn6U]==0)
		{ClawStatus(0);
			DrivingCode(8);
		}
	}
}
