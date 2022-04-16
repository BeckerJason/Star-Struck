//GLOBAL VARIABLES FOR DATA BEING SENT
int var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0, var6 = 0, var7 = 0, var8 = 0, var9 = 0, var10 = 0;
int var11 = 0, var12 = 0, var13 = 0, var14 = 0, var15 = 0, var16 = 0, var17 = 0, var18 = 0, var19 = 0, var20 =0;

void SetData()
{
	//var1 is used to send ID (For graphing purpose)
	var2 = SensorValue[PGyro];
	var3 = SensorValue[encPDrive];
	var4 = SensorValue[Gyro];
	var5 = SensorValue[encDrive];
	var6 = SensorValue[encArm];
	var7 = 250;
	var8 = 300;
	var9 = 350;
	var10 = 400;
	var11 = 450;
	var12 = 500;
	var13 = 550;
	var14 = 600;
	var15 = 650;
	var16 = 700;
	var17 = 750;
	var18 = 800;
	var19 = 900;
	var20 = 1000;
	//delay(20);
}

task SendData()//SEND DATA TASK
{
	while(1)
	{
		SetData();
		char final[99];
		sprintf(final,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",var1,var2,var3,var4,var5,var6,var7,var8,var9,var10,var11,var12,var13,var14,var15,var16,var17,var18,var19,var20);
		char    *p;
		int      i;
		p = &final[0];
		for(i=0;i<strlen(final);i++)
		{
			sendChar( UART0, *p++ );
			while(!bXmitComplete(UART0));
		}
		var1++;
		delay(150); //INTERVAL OF DATA BEING SENT
		//endTimeSlice();
	}

}
