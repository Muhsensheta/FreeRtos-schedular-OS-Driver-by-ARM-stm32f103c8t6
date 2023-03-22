/*
 * NVIC_int.h
 *
 *  Created on: Mar 5, 2023
 *      Author: houras
 */

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

void NVIC_void_Init();
void NVIC_void_EnableInt(u8 IntNum);
void NVIC_void_DisableInt(u8 IntNum);
void NVIC_void_Enable_PendingFlag(u8 IntNum);
void NVIC_void_Clr_PendingFlag(u8 IntNum);
u8 NVIC_u8_GetActiveFlag(u8 IntNum);
void NVIC_void_Set_Periority(u8 IntNum,u8 Periority);

void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void));
void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void));

#endif /* NVIC_INT_H_ */
