//CALL THIS FUNCTION TO START THE AUTO TASK
void DebugMaster(void)
{
	//DEBUG STAGE//
	if(autoStage==0)
	{
		while(MoveDistMaster(-24, 127, 2000, 1));

		clawStatusMaster(0);
		MoveArmMaster(0);
		StopDriveMaster();
		while(1);
		//DO NOTHING
	}
	if(autoStage==2)
	{
		//MASTER:DROPCLAW DOWN
		while(MoveDistMaster(-10, 127, 2000, 0));
		clawStatusMaster(1);
		MoveArmMaster(-30);
		while(MoveDistMaster(5, 127, 2000, 0));
		clawStatusMaster(0);
		//while(SetDegreesMaster(50));
		TurnDegreeMaster(35, 127, 0);
		///
		while(MoveDistMaster(55, 127, 5000, 0));
		///
		clawStatusMaster(1);
		while(ArmAngleMaster(50, 127, 3000));
		//while(SetDegreesMaster(900));
		TurnDegreeMaster(-860, 127, 1);
		while(MoveDistMaster(-50, 127, 5000, 1));
		while(ArmAngleMaster(60, 127, 3000));
		clawStatusMaster(0);
		//
		clawStatusMaster(0);
		MoveArmMaster(0);
		StopDriveMaster();
		while(1);
	}

	if(autoStage==4)
	{
		StopDriveMaster();
		MoveArmMaster(0);
		while(1);
	}
	wait1Msec(20);
}
