This is a C code implementation of Hitachi HD44780. ( Based on the manual , under the current directory )

	The Dot Matrix Liquid Crystal Display Controller/Driver Library for HITACHI.

To use these code to drive your LCD1602 or other HD44780 module :

	Probably you should modify delay functions in delay.c first ( depends on your chip )
	
	1.Modify the "Connection" section in config.h 
	2.Invoke LCM_Init();
	3.Invoke LCM_Put_Str(); or LCM_Put_Num();. ( see HD44780.h )
	
You can use these basic function to implement your own LCD driving features.
