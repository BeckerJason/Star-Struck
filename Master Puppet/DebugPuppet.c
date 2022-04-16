//FUNCTION TO START THE PUPPET AUTONOMOUS TASK
void DebugPuppet(void)
{
	//DEBUG STAGE//
	if(autoStage==0)
	{
		while(MoveDistPuppet(40, 127, 5000, 0));

		StopDrivePuppet();
		MoveArmPuppet(0);
		while(1);
	}
	if(autoStage==1){
			SensorValue[pis2]=1;
			wait1Msec(500);
			SensorValue[pis2]=0;
			MoveArmPuppet(50);
			//while(MoveDistPuppet(-5, 127, 5000));
			TurnPuppet(110, 127, 1);
			//do{condition = TurnPuppet(113, 127, 1);}while(condition);
			MoveArmPuppet(-40);

			autoStage++;
		}
		if(autoStage==2){
			////PUPPET: GO FOR CUBE///////////////////////
			//MASTER:DROPCLAW DOWN
			while(MoveDistPuppet(25, 127, 3000, 0));
			clawStatusPuppet(1);
			////PUPPET:PICKUP CUBE AND THRROUGH
			MoveArmPuppet(127);

			wait1Msec(750);
			TurnPuppet(300, 127, 1, 2500);
			while(MoveDistPuppet(42, 127, 5000, 0));

			StopDrivePuppet();
			clawStatusPuppet(0);
			//autoStage++;

			MoveArmPuppet(0);
			while(1);
		}

		if(autoStage==5){
			//STOP AUTONOMOUS
			StopDrivePuppet();
			MoveArmPuppet(0);
			while(1);
		}
		wait1Msec(20);
}
