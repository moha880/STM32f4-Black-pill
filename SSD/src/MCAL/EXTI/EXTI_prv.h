/*
 * EXTI_prv.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_



#define ENABLE 1
#define DISABLE  0

#define EXTI_RISING   1
#define EXTI_FALLING  2
#define EXTI_ONCHANGE 3


#define EXTI_BASE_ADDR		0x40013C00


typedef struct{

	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_MemMap_t;


#define EXTI		((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))



#endif /* MCAL_EXTI_EXTI_PRV_H_ */