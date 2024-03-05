/*
 * EXTI_prg.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Ibrahem
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"


#include"EXTI_int.h"
#include"EXTI_prv.h"
#include"EXTI_cfg.h"
#include"SYSCFG_prv.h"

void SYSCFG_vSetExtiPort(u8 A_u8LineNo,u8 A_u8PortNo){
	u8 L_u8index=A_u8LineNo/4;
	u8 L_u8ShiftAmount=(A_u8LineNo%4)*4;


	SYSCFG->EXTICR[L_u8index] &= ~((0b1111) <<(A_u8LineNo%4)*4);
	SYSCFG->EXTICR[L_u8index] |=((A_u8PortNo) <<(A_u8LineNo%4)*4);
}

void MEXTI_vInit(void)
{
	EXTI->IMR = 0 ;
	EXTI->IMR |= (EXTI_LINE_0_EN << 0) |
			     (EXTI_LINE_1_EN << 1) /*|
				 (EXTI_LINE_2_EN << 2)*/  ;


	/* Clear all flags */
	EXTI->PR = 0xffffffff;
}

void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8LineNo)
{
	if (A_u8LineNo<16){
		SET_BIT(EXTI->IMR,A_u8LineNo);
		switch(A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			CLR_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_FALLING:
			CLR_BIT(EXTI->RTSR,A_u8LineNo);
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		}
	}
}

void MEXTI_vDisableLine( u8 A_u8LineNo){
	if (A_u8LineNo<16)
	{
		CLR_BIT(EXTI->IMR , A_u8LineNo);
	}
}

void MEXTI_vSoftwareTrigger(u8 A_u8LineNo){
	if (A_u8LineNo<16){
		SET_BIT(EXTI->SWIER,A_u8LineNo);
	}
}

void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8LineNo)
{
	switch(A_u8Trigger)
	{
	case EXTI_RISING:
		SET_BIT(EXTI->RTSR,A_u8LineNo);
		CLR_BIT(EXTI->FTSR,A_u8LineNo);
		break;
	case EXTI_FALLING:
		CLR_BIT(EXTI->RTSR,A_u8LineNo);
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		break;
	case EXTI_ONCHANGE:
		SET_BIT(EXTI->RTSR,A_u8LineNo);
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		break;
	}

}






