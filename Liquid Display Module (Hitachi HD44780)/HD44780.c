#include "config.h"
#include "HD44780.h"
#include <reg51.h>

/***************** HD44780U Intrisic Operation Implementations *****************/
void LCM_Set_Signals_On(bit RS,bit RW){
	
	/* RS : 0 for Instruction Register (IR)
					1 for Data Register (DR)
		 RW : 0 for Write
					1 for Read
		 When RS = 0 RW = 1 , it reads busy flag from LCM_LCM_DB7 and address coutner 
													from (LCM_DB0 to LCM_DB6).		*/
		LCM_RS = RS;
		LCM_RW = RW;
		LCM_E  = 1;		//Starts read/Write process.
		delay(1);
}

void LCM_Set_Signals_Off(){
	
		LCM_E = 0;	 //Stop the process
}

bit LCM_Check_Busy(){
	
	LCM_Set_Signals_On(0,1);
	
	if(LCM_DB7 == 1){
		LCM_Set_Signals_Off();
		return 1;
	}
	else{ 
		LCM_Set_Signals_Off();
		return 0;
	}
}
		
void LCM_Write_Ins(unsigned char INS){
	while(LCM_Check_Busy());
	LCM_Set_Signals_On(0,0);
	LCM_DB = INS ; 
	delay(1);		//For the internal instruction execution time.
	
	LCM_Set_Signals_Off();
}

void LCM_Write_Dat(unsigned char DAT){
	while(LCM_Check_Busy());
	LCM_Set_Signals_On(1,0);
	LCM_DB = DAT;
	delay(1);		//For the internal instruction execution time.
	
	LCM_Set_Signals_Off();
}

unsigned char LCM_Read_Dat(){
	while(LCM_Check_Busy());
	LCM_Set_Signals_On(1,1);
	delay(1);			//For the internal instruction execution time.
	
	LCM_Set_Signals_Off();
	return LCM_DB;
}

void LCM_Set_CGAddr(unsigned char addr){
	unsigned char tmp;
	tmp = 0x40+addr; 
	 
	LCM_Write_Ins(tmp);
	
}
void LCM_Set_DDAddr(unsigned char addr){
	unsigned char tmp;
	tmp = 0x80+addr;
	 
	LCM_Write_Ins(tmp);
	
}

/***************** HD44780U Intrisic Operation Implementations *****************/



/*****************     HD44780U Display Module Applications    *****************/

void LCM_Init(){
	
	LCM_Write_Ins(CLR_DISP);
	LCM_Write_Ins(FUN_SET_8_2_8);
	LCM_Write_Ins(ENT_MOD_I_X);
	LCM_Write_Ins(DIS_MOD_D_C_X);
	
}

void LCM_Puts_Str(unsigned char LINE,unsigned char POSI,unsigned char *str){
	switch(LINE){
		case	1	:	{
			LCM_Set_DDAddr(POSI);
			while(*str != '\0')
				LCM_Write_Dat(*str++);
		}
		break;
		
		case	2	:	{
			unsigned char tmp;
			tmp = 0x40+POSI;
			LCM_Set_DDAddr(tmp);
			while(*str != '\0')
				LCM_Write_Dat(*str++);
			
		}
		break;
		
	}
	
}

unsigned char p3,p2,p1;
void LCM_Puts_Num(unsigned char LINE,unsigned char POSI,unsigned char num){
	switch(LINE){
		case	1	:	{
			LCM_Set_DDAddr(POSI);
			
			p3 = num / 100 + 0x30;
			p2 = (num % 100) / 10 + 0x30;
			p1 = (num % 100) % 10 + 0x30;
			LCM_Write_Dat(p3);
			LCM_Write_Dat(p2);
			LCM_Write_Dat(p1);
			
		}
		break;
		
		case	2	:	{
			unsigned char tmp;
			tmp = 0x40+POSI;
			LCM_Set_DDAddr(tmp);

			p3 = num / 100 + 0x30;
			p2 = (num % 100) / 10 + 0x30;
			p1 = (num % 100) % 10 + 0x30;
			LCM_Write_Dat(p3);
			LCM_Write_Dat(p2);
			LCM_Write_Dat(p1);
			
		}
		break;
		
	}
}


	
	
/*****************     HD44780U Display Module Applications    *****************/
