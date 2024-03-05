/*
 * RCC_prv.h
 *
 *  Created on: Aug 16, 2022
 *      Author: mazen
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_


#define RCC_BASE_ADDR		0x40023800

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1 ;
	u32 reserved2 ;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved3 ;
	u32 reserved4 ;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5 ;
	u32 reserved6 ;
	u32 APB1ENR;
	u32 APB2ENR;
}RCC_MemMap_t;


#define RCC  ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


#define HSION	0

#define HSEON	16
#define HSEBYP	18
#define CSSON	19


#define SW1		1
#define SW0		0



#define ENABLE		1
#define DISABLE		0






#endif /* MCAL_RCC_RCC_PRV_H_ */
