/*
 * NVIC_prv.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_NVAC_NVIC_PRV_H_
#define MCAL_NVAC_NVIC_PRV_H_

#define NVIC_BASE_ADDR		0xE000E100

typedef struct{

    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IAPR[32];
    volatile u32 RESERVED[32];
    volatile u8  IPR[128];




}NVIC_MemMap_t;



#endif /* MCAL_NVAC_NVIC_PRV_H_ */
