/*
 * RCC_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"


void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */
	SET_BIT(RCC->CR, CSSON);
	/*2- HSE_BYP */
	CLR_BIT(RCC->CR, HSEBYP);
	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC->CFGR, SW1);
	/*4- Bus prescalers   */
	/*5- PLL configuration */
	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

}

void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId){

	case RCC_AHB1:
		SET_BIT(RCC-> AHB1ENR , A_u32PeripheralId);
		break;
	case RCC_AHB2:
		SET_BIT(RCC-> AHB2ENR , A_u32PeripheralId);
		break;
	case RCC_APB1:
		SET_BIT(RCC-> APB1ENR , A_u32PeripheralId);
		break;
	case RCC_APB2:
		SET_BIT(RCC-> APB2ENR , A_u32PeripheralId);
		break;

	}
}

void MRCC_vDisableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId){

	case RCC_AHB1:
		CLR_BIT(RCC-> AHB1ENR , A_u32PeripheralId);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC-> AHB2ENR , A_u32PeripheralId);
		break;
	case RCC_APB1:
		CLR_BIT(RCC-> APB1ENR , A_u32PeripheralId);
		break;
	case RCC_APB2:
		CLR_BIT(RCC-> APB2ENR , A_u32PeripheralId);
		break;

	}

}
