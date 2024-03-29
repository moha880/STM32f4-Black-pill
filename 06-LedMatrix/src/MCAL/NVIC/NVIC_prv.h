/*
 * NVIC_prv.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

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


#define NVIC  ((volatile NVIC_MemMap_t*)(NVIC_BASE_ADDR))

#define VECTKEY		  0x05FA0000
typedef struct
{

    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;

}SCB_MemMap_t;



#define SCB_BASE_ADDR		0xE000ED00


#define SCB ((volatile SCB_MemMap_t *)(SCB_BASE_ADDR))

#endif /* MCAL_NVIC_NVIC_PRV_H_ */
