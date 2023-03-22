/*
 * PB_ARM_prog.c
 *
 *  Created on: ٠٢‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include  "DIO_int.h"
#include  "RCC_interface.h"
#include  "PB_int.h"
void PB_void_Init(){

	M_GPIO_void_SetPinDir(PORTA_ID,PIN3_ID,IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinValue(PORTA_ID,PIN3_ID, HIGH);

}
void PB_void_GetRead(u8 *Value)
{

	M_GPIO_void_GetPinValue(PORTA_ID,PIN3_ID, Value);


}
