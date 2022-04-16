void DebugCode(void)
{

DebugMaster();
DebugPuppet();


////
//SensorValue[pis2]=1;
//wait1Msec(300);
//SensorValue[pis2]=0;
//MoveArmPuppet(20);

////MASTER:DROPCLAW DOWN
//clawStatusMaster(1);
////clearTimer[T1];
//MoveArmMaster(-25);
//MoveMaster(2,80);

//while(TurnPuppet(113, 127, 1));

//StopDriveMaster();
//MoveArmMaster(0);
//clawStatusMaster(0);

//MoveArmPuppet(0);
//////PUPPET: GO FOR CUBE///////////////////////

////wait1Msec(500);//Simulate Puppet
//while(MoveDistPuppet(24, 127, 3000, 1)){if(time1[T1]>500)clawStatusMaster(0);}
////clawStatusPuppet(1);
////PUPPET:PICKUP CUBE AND THRROUGH
//MoveArmPuppet(127);
//wait1Msec(500);
//while(TurnPuppet(200, 127, 0));
//while(MoveDistPuppet(40, 127, 5000, 1));
//clawStatusPuppet(0);
//MoveArmPuppet(0);

while(1);
}
