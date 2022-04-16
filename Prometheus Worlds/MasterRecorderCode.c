KillALL();
//break;

while (1)
{
	if (vexRT[Btn6U]==1)
	{
		writeDebugStreamLine("ClawStatus(1);");
		while (vexRT[Btn6U]==1)
		{
			ClawStatus(1);
		DrivingCode(15);
		}
	}
	else if (vexRT[Btn6U]==0)
	{
		writeDebugStreamLine("ClawStatus(0);			//Move wait timer that is above this line, to bellow this line");
		while (vexRT[Btn6U]==0)
		{ClawStatus(0);
		DrivingCode(8);
		}
	}
}
