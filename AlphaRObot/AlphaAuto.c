void auto()
{int timer=0;
	while (timer<1){
		KillALL();

	ClawStatus(0);

	while(MoveDist(50,90,2500));

	ClawStatus(1);

	wait1Msec(500);
	//Through middle stars
	MoveDist(-5, 40, 1000);
	ArmAngle(170, 100);

	TurnDegree(180, 45);

	MoveDist(-65, 85, 5000);


	SensorValue[ArmEnc]=0;
	MoveDist(-32, 127, 4000);
	if(SensorValue[ArmEnc]<800)
	{MoveArm(127);}

	else{StopArm();
	}
	StopArm();
	clawStatus(0);

	ArmAngle(-250, 127);
	StopArm();



	timer++;
}
}
