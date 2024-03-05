/*
 * EXTI_int.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_




enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,

};


typedef struct
{
	u8 LineNo;
	u8 Trigger;
}EXTI_Config_t;

void SYSCFG_vSetExtiPort(u8 A_u8LineNo,u8 A_u8PortNo);

void MEXTI_vInit(/*EXTI_Config_t* A_xConfig*/);

void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8LineNo);
void MEXTI_vDisableLine(u8 A_u8LineNo);

void MEXTI_vSoftwareTrigger(u8 A_u8LineNo);

void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8LineNo);



#endif /* MCAL_EXTI_EXTI_INT_H_ */
