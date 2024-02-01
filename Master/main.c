/*
 * main.c
 *
 *  Created on: Sep 25, 2022
 *      Author: General
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_Interface.h"
#include "EXTINT_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Interface.h"
#include "TMR0_Interface.h"
#include "KPD_Interface.h"
#include "LCD_Interface.h"

#include "TWI_int.h"
#include "EXT_EEPROM_int.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
//#include "avr/io.h"
//#undef  F_CPU
//#define F_CPU (16000000UL)




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



