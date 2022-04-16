void Drive(int ch3,int ch4)
{int left=ch3-ch4;
	int right=ch3+ch4;
	motor[LM] = left;
	motor[L1] = left;
	motor[L2] = left;
	motor[RM] = right;
	motor[R1] = right;
	motor[R2] = right;
}
void Arm(int speed)
{
motor[leftArmM] = speed;
			motor[leftArmY] = speed;
			motor[rightArmM] = speed;
			motor[rightArmY] = speed;

}
void Stopdrive()
{
	motor[LM] = 0;
	motor[L1] = 0;
	motor[L2] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	motor[R2] = 0;
}
void StopArm()
{			motor[leftArmM] = 0;
			motor[leftArmY] = 0;
			motor[rightArmM] = 0;
			motor[rightArmY] = 0;
			}
