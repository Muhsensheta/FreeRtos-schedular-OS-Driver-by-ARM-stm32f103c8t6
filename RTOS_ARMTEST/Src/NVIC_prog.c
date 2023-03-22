/*
 * NVIC_prog.c
 *
 *  Created on: Mar 5, 2023
 *      Author: houras
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_priv.h"
#include"NVIC_config.h"
#include"NVIC_int.h"

static void (*EXTI0_CallBack) (void) = NULL;
static void (*EXTI1_CallBack) (void) = NULL;


void NVIC_void_Init()
{
#ifndef SCB_AIRCR
#define  SCB_AIRCR    *((volatile u32*)(0xE000ED00+0x0C))
#endif
SCB_AIRCR	=	 NVIC_GRB_SUB_NUM;
}

void NVIC_void_EnableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISER0=(1<< IntNum);
	}
	else if(IntNum<64)
	{
		IntNum -=32;
			NVIC_ISER1=(1<<IntNum);
	}
}

void NVIC_void_DisableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICER0=(1<< IntNum);
	}
	else if(IntNum<64)
	{
		IntNum -=32;
			NVIC_ICER1=(1<<IntNum);
	}
}

void NVIC_void_Enable_PendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISPR0=(1<< IntNum);
	}
	else if(IntNum<64)
	{
		IntNum -=32;
		NVIC_ISPR1=(1<<IntNum);
	}
}
void NVIC_void_Clr_PendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICPR0=(1<< IntNum);
	}
	else if(IntNum<64)
	{
		IntNum -=32;
		NVIC_ICPR1=(1<<IntNum);
	}
}

u8 NVIC_u8_GetActiveFlag(u8 IntNum)
{
	u8 Local_Active =0x22;
	if(IntNum<32)
	{
		Local_Active =GET_BIT( NVIC_IABR0,(1<< IntNum));
	}
	else if(IntNum<64)
	{
		IntNum -=32;
		Local_Active =GET_BIT( NVIC_IABR1,(1<< IntNum));

	}
}


//NVIC_voidSetPriority(0,0b0111) /*Group 1 Sub 3*/
void NVIC_void_Set_Periority(u8 IntNum,u8 Periority)
{
	NVIC_IPR[IntNum]=(Periority<<4);
}





void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI0_CallBack = Pf; //Ahmed
	}
}

//External Peripherals

void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI1_CallBack = Pf; //Ahmed
	}
}

//External Peripherals
void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
}






