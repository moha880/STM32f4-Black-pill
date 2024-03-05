/*
 * SSD_prg.c
 *
 *  Created on: Jul 17, 2022
 *      Author: Ibrahem
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

//#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "SSD_int.h"

static const u8 CGS_u8SSD_Nums[] ={
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111
};


MGPIO_Config_t SSD_PINS[7] = {
/*  Port         Pin            Mode               Output Speed               OutputType                  */
{.Port=GPIO_PORTA,.Pin=GPIO_PIN8 ,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN9 ,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN10,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN11,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN12,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN13,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN14 ,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
};

MGPIO_Config_t SSD_POWER[2] ={
{.Port=GPIO_PORTA,.Pin=GPIO_PIN0 ,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL},
{.Port=GPIO_PORTA,.Pin=GPIO_PIN5 ,.Mode =GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW,.OutputType=GPIO_OTYPE_PUSHPULL}
};

void HSSD_vInit(void){
//	MDIO_vSetPortDIR(SSD_PORT,0xff);
	for(u8 i=0;i<7;i++){
		MGPIO_vInit(&SSD_PINS[i]);
	}
	for(u8 i=0;i<2;i++){
		MGPIO_vInit(&SSD_POWER[i]);
	}
}


void HSSD_vDisplayNum(/*u8 SSDId ,*/ u8 A_u8Num)
{
	/*input validation*/

	if (A_u8Num < 10)
	{
#if SSD_TYPE==COM_CATHODE
		for(u8 i=0;i<7;i++){
			MGPIO_vSetPinVal(SSD_PINS[i].Port,SSD_PINS[i].Pin,GET_BIT(CGS_u8SSD_Nums[A_u8Num],i));
		}
//		MDIO_vSetPortVal(SSD_PORT , CGS_u8SSD_Nums[A_u8Num]);
#elif SSD_TYPE==COM_ANODE
//		MDIO_vSetPortVal(SSD_PORT , ~CGS_u8SSD_Nums[A_u8Num]);
		for(u8 i=0;i<7;i++){
			MGPIO_vSetPinVal(SSD_PINS[i].Port,SSD_PINS[i].Pin,~GET_BIT(CGS_u8SSD_Nums[A_u8Num],i));
		}

#endif

	}


}

void HSSD_vTurnOff(void)
{
#if SSD_TYPE==COM_CATHODE
	for(u8 i=0;i<7;i++){
		MGPIO_vSetPinVal(SSD_PINS[i].Port,SSD_PINS[i].Pin,0);
	}

//	MDIO_vSetPortVal(SSD_PORT,0);
#elif SSD_TYPE==COM_ANODE
//	MDIO_vSetPortVal(SSD_PORT,0xff);
	for(u8 i=0;i<7;i++){
		MGPIO_vSetPinVal(SSD_PINS[i].Port,SSD_PINS[i].Pin,1);
	}

#endif

}
