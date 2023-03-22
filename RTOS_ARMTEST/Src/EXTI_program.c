#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"NVIC_int.h"
#include	"NVIC_priv.h"
#include	"NVIC_config.h"
#include    "EXTI_interface.h"
#include    "EXTI_private.h"


#ifndef		NULL
#define		NULL	(void *)0
#endif

static void (*EXTI0_CallBack) (void) = NULL;



void	EXTI_voidInit(void)
{
	
}

void	EXTI_voidEnableLine(u8 ExtiLine)
{
	SET_BIT(EXTI -> IMR , ExtiLine);
}

void	EXTI_voidDisableLine(u8 ExtiLine)
{
	CLR_BIT(EXTI -> IMR , ExtiLine);
}

void	EXTI_voidSetExtiEdge(u8 ExtiLine,u8 edge)
{
	switch(edge)
	{
		case	EXTI_RISING	:		SET_BIT(EXTI -> RSTR,ExtiLine);	
									CLR_BIT(EXTI -> FSTR,ExtiLine);	
		break;
		
		case	EXTI_FALLING:		SET_BIT(EXTI -> FSTR,ExtiLine);
									CLR_BIT(EXTI -> RSTR,ExtiLine);
		break;
		
		case	EXTI_IOC	:		SET_BIT(EXTI -> RSTR,ExtiLine);
									SET_BIT(EXTI -> FSTR,ExtiLine);
		break;
		default:
									CLR_BIT(EXTI -> RSTR,ExtiLine);
									CLR_BIT(EXTI -> FSTR,ExtiLine);
	}
}

void	EXTI_voidSetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI0_CallBack = Pf; //Ahmed
	}
}

//External Peripherals
void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack(); // Ahmed();
}
