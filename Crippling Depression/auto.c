
 resetencoders();
	moveRob(.5,-127);
motorsOff()
	wait1Msec(1000);
	moveArm( 2800, 100 );
wait1Msec(1000);
	motorsOff();
	armStall( 5 );
	moveClaw(127);
	motorsOff();
	armStall( 5 );
	moveRob( 1900, 100 );
	motorsOff();
	wait1Msec(500);
	moveRob( 800, -100 );
	motorsOff();
	moveArm(3800, -100 );
	motorsOff();
turnRob(1100, 40, 1);
	motorsOff();
	delay(500);
	moveRob( 800, -100);
	motorsOff();
	wait1Msec(200);
	moveArms(-100);
	wait1Msec(1000);
	motorsOff();
	moveRob(1000,100);
	motorsOff();//
	motor[clawr]=-100;
	motor[clawl]=-100;
	wait1Msec(500);
	motor[clawr]=-10;
	motor[clawl]=-10;
	turnRob(1500, 75, 1);
	motorsOff();
	motor[clawr]=-10;
	motor[clawl]=-10;
	moveRob( 1700, -100 );
	moveArm( 2000, 100 );
		moveClaw(127 );

