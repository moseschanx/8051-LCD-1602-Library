
#ifndef _LCM_H
#define _LCM_H

void LCM_Set_Signals_On(bit RS,bit RW);
void LCM_Set_Signals_Off();

bit LCM_Check_Busy();

void LCM_Write_Ins(unsigned char INS);
void LCM_Write_Dat(unsigned char DAT);

unsigned char LCM_Read_Dat();
void LCM_Set_CGAddr(unsigned char addr);
void LCM_Set_DDAddr(unsigned char addr);

void LCM_Init();
void LCM_Puts_Str(unsigned char LINE,unsigned char POSI,unsigned char *str);
void LCM_Puts_Num(unsigned char LINE,unsigned char POSI,unsigned char num);
//Instructon Mode
#define CLR_DISP 0X01		//Clear entire display and sets DDRAM address 0 in AC.
#define RET_HOME 0X02		//Sets DDRAM address 0 in AC, return to original positioin. DDRRAM unchanged.


//Entry mode set, sets cursor move direction and specifies display shift.
#define ENT_MOD_D_X 0X04	//Move left , no shifting
#define ENT_MOD_D_S	0X05  //Move left , shifting
#define ENT_MOD_I_X 0X06  //Move right , no shifting
#define ENT_MOD_I_S 0X07  //Move right , shifting

//Display mode set , Sets the entire entire display (D) on/off
//cursor (C) on/off and blinking of cursor position character (B)
#define DIS_MOD_X_X_X	0X08 //Sets Display off , cursor off , blinking off
#define DIS_MOD_X_X_B	0X09 //Sets Display off , cursor off , blinking on
#define DIS_MOD_X_C_X	0X0A //Sets Display off , cursor on , blinking off
#define DIS_MOD_X_C_B	0X0B //Sets Display off , cursor on , blinking on
#define DIS_MOD_D_X_X	0X0C //Sets Display on , cursor off , blinking off
#define DIS_MOD_D_X_B	0X0D //Sets Display on , cursor off , blinking on
#define DIS_MOD_D_C_X	0X0E //Sets Display on , cursor on , blinking off
#define DIS_MOD_D_C_B	0X0F //Sets Display on , cursor on , blinking on

//Cursor or display shift , Moves cursor and shifts display without changing DDRAM contents.
#define CUR_DIS_C_L		0X10	// cursor move left
#define CUR_DIS_C_R		0X14  // cursor move right 
#define CUR_DIS_S_L		0X18	// display shift left
#define CUR_DIS_S_R		0X1C	// display sfhit right

//Function set. Sets interface data length (DL) ,number of display lines (N),and character font (F)
#define FUN_SET_4_1_8		0X20	//4bit interface data length , 1 number of display line , 5 X 8 dots font
#define FUN_SET_4_1_10	0X24	//4bit interface data length , 1 number of display line , 5 X 10 dots font
#define FUN_SET_4_2_8		0X28	//4bit interface data length , 2 number of display line , 5 X 8 dots font
#define FUN_SET_4_2_10	0X2C	//4bit interface data length , 2 number of display line , 5 X 10 dots font
#define FUN_SET_8_1_8		0X30	//8bit interface data length , 1 number of display line , 5 X 8 dots font
#define FUN_SET_8_1_10	0X34	//8bit interface data length , 1 number of display line , 5 X 10 dots font
#define FUN_SET_8_2_8		0X38	//8bit interface data length , 2 number of display line , 5 X 8 dots font
#define FUN_SET_8_2_10	0X3C	//8bit interface data length , 2 number of display line , 5 X 10 dots font

#endif