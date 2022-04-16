void value(int value){
	motor[leftArmM] =value;
	motor[leftArmY] =value;
	motor[rightArmM] =value;
	motor[rightArmY] =value;}

void values(int value1, int value2){
	motor[LM] = value1 + value2;
	motor[L1] = value1 + value2;
	motor[L2] = value1 + value2;
	motor[RM] = value1 - value2;
	motor[R1] = value1 - value2;
	motor[R2] = value1 - value2;}
