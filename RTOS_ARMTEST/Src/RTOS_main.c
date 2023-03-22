#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_int.h"
#include	"STK_interface.h"
#include	"RTOS_interface.h"

void	Task1(void);
void	Task2(void);
void	Task3(void);

int	main(void)
{
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	Direction for C13 is output Push Pull */
	M_GPIO_void_SetPinDir(PORTC_ID, PIN13_ID, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(PORTC_ID, PIN14_ID, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(PORTC_ID, PIN15_ID, OUT_2MHZ_PP);
	
	//RTOS_voidCreatTask(0,1000,Task1);
	//RTOS_voidCreatTask(1,2000,Task2);
	//RTOS_voidCreatTask(2,3000,Task3);
	/*	RTOS initilaization	*/

	RTOS_voidCreatTask(0, 0, 1,Task1);
	RTOS_voidCreatTask(1,1, 2,Task2);
	RTOS_voidCreatTask(2,2, 3,Task3);
	RTOS_voidInit();
	
	
	while(1)
	{

	}
	return 0;
}


void	Task1(void)
{
	static u8	flag1 = 0;
	if(flag1 == 0)
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, LOW);
		flag1 = 1;
	}else
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID,HIGH);
		flag1 = 0;
	}
}

void	Task2(void)
{
	static u8	flag2 = 0;
	if(flag2 == 0)
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, LOW);
		flag2 = 1;
	}else
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID,HIGH);
		flag2 = 0;
	}
}

void	Task3(void)
{
	static u8	flag3 = 0;
	if(flag3 == 0)
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, LOW);
		flag3 = 1;
	}else
	{
		M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);
		flag3 = 0;
	}
}
