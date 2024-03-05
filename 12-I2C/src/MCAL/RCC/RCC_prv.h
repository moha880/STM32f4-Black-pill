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
	u32 reserved7 ;
	u32 reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 reserved9;
	u32 reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved11;
	u32 reserved12;
	u32 BDCR;
	u32 CSR;
	u32 reserved13;
	u32 reserved14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 reserved15;
	u32 DCKCFGR;
}RCC_MemMap_t;


#define RCC  ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


/*Bits of RCC clock control register (RCC_CR)*/
#define HSION    16
#define HSEON    0
#define HSEBYP   18
#define CSSON    19
#define PLLON    24

/*Bits of RCC configuration register (RCC_CFGR)*/
#define SW0      0
#define SW1      1
#define HPRE_0   4
#define HPRE_1   5
#define HPRE_2   6
#define HPRE_3   7

#define PPRE1_0  10
#define PPRE1_1  11
#define PPRE1_2  12

#define PPRE2_0  13
#define PPRE2_1  14
#define PPRE2_2  15

/*Bits of RCC PLL configuration register (RCC_PLLCFGR)*/
#define PLLSRC   22


/*Bits of RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)*/
#define TIMPRE	24


/*define ENABLE and DISABLE macro */
#define ENABLE  1
#define DISABLE 2

/*Define Options of System Clock */
#define HSI    1
#define HSE    2
#define PLL    3

/*define Division of clock */
#define NOT_DIVISION  1
#define DIVISION_2    2
#define DIVISION_4    3
#define DIVISION_8    4
#define DIVISION_16   5
#define DIVISION_64   6
#define DIVISION_128  7
#define DIVISION_256  8
#define DIVISION_512  9

#endif /* MCAL_RCC_RCC_PRV_H_ */
