This is a C code implementation of Hitachi HD44780. ( Scrictly depend on the manual )

To use these code to drive your LCD1602 or other HD44780 module :

	0.Probably you should modify delay functions in delay.c ( depends on your chip )
	
	1.Modify the "Connection" section in config.h 
	2.Invoke LCM_Init();
	3.Invoke LCM_Put_Str(); or LCM_Put_Num();. ( see HD44780.h )
	
You can use these basic function to implement your own LCD driving features.
