/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
#include "LCD_Interface.h"

#include"string.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


u8 SelectServoAngle(u8 copy_data) ;
u8 arr[20]={0} ;
u8 select= 0 ;
int main()
{

	s8 coun=-1 ;
	u8 c =0 ;
	u8 error =1 ;


	LCD_voidInit();
	UART_VoidInit();
	SPI_voidInit();

	M_TIMER1_voidPwm1Init();
	M_TIMER1_voidPwm1SetTop();
	M_TIMER1_voidPwm1SetDutyCycle(0);

	DIO_voidSetPinDirection(PORTD_ID,PIN0,PIN_OUTPUT);





	while(1)
	{

		//make all arr =0 every time
		for(c=0 ; c!=20 ; c++)
		{
			arr[c]=0 ;
		}

		do
		{
			coun++ ;
			SPI_voidReceiveChar(&arr[coun]);

		}while(arr[coun]!='#');
		coun =-1;


		//string check
		error =SelectServoAngle(arr[0]) ;

		if (error==0)
		{
			LCD_voidClear() ;
			LCD_voidWriteString(arr);
		}
		else
		{
			LCD_voidClear() ;
			LCD_voidWriteString((u8*)"ERROR TRY AGAIN");
		}

		M_TIMER1_voidPwm1Stop();





	}



	return 0 ;
}




u8 SelectServoAngle(u8 copy_data)
{
	select =0 ;
	switch(copy_data)
	{
	case '0':
		DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_LOW);

		M_TIMER1_voidPwm1Start();
		if(strcmp((char*)arr,(char*)"0s-90#")==0)
		{

			M_TIMER1_voidPwm1SetDutyCycle(25);


		}


		else if(strcmp((char*)arr,(char*)"0s+90#")==0)
		{
			M_TIMER1_voidPwm1SetDutyCycle(65);

		}
		else
		{
			select =1 ;
		}
		break ;
	case '1':
		DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_HIGH);

		M_TIMER1_voidPwm1Start();
		if(strcmp((char*)arr,(char*)"1s-90#")==0)
		{
			M_TIMER1_voidPwm1SetDutyCycle(25);
			//TIMER0_VoidSetPWMCompareMatch(0);

		}

		else if(strcmp((char*)arr,(char*)"1s+90#")==0)
		{
			M_TIMER1_voidPwm1SetDutyCycle(65);
			//	TIMER0_VoidSetPWMCompareMatch(100);
		}
		else
		{
			select =1 ;
		}
		break ;

	default : select =1 ;
	break ;
	}

	return select ;
}


