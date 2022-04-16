void BlueAutoM1(void){
	if(autoStage==0)
		{
			//DO NOTHING
		}
		if(autoStage==1)
		{
			while(MoveDistMaster(-7, 127, 5000));
			//MASTER:DROPCLAW DOWN
			clawStatusMaster(1);
			//clearTimer[T1];
			MoveArmMaster(-25);
			while(MoveDistMaster(7, 127, 5000));

			clawStatusMaster(0);
			MoveArmMaster(0);
			StopDriveMaster();
			while(1);
		}

		if(autoStage==2)
		{
			StopDriveMaster();
			MoveArmMaster(0);
			while(1);
		}
		wait1Msec(20);
}
