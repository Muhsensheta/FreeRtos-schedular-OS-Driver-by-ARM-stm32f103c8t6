#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

void	EXTI_voidInit(void);
void	EXTI_voidEnableLine(u8 ExtiLine);
void	EXTI_voidDisableLine(u8 ExtiLine);
void	EXTI_voidSetCallBack(void (*Pf) (void));
void	EXTI_voidSetExtiEdge(u8 ExtiLine,u8 edge);

#define			EXTI_NONE				0
#define			EXTI_RISING				1
#define			EXTI_FALLING			2
#define			EXTI_IOC				3

#endif