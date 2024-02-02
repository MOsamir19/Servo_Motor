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


#ifndef F_CPU
#define F_CPU 8000000UL
#endif

int main()
{

	u8 data=0 ;
	u8 arr[20]={0} ;
	s8 coun=-1 ;
	//LCD_voidInit();
	UART_VoidInit();
	SPI_voidInit();

	// UART_VoidReceiveString();

	while(1)
	{


		UART_VoidReceiveString(arr);

		do
		{
			coun++ ;
			SPI_VoidSendChar(arr[coun]);

		}while(arr[coun]!='#');
		coun =-1;




	}


	return 0 ;
}



