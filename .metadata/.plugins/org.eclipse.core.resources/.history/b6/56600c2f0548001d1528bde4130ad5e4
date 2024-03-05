/*
 * S2P_prg.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Ibrahem
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_int.h"

#include"S2P_cfg.h"
#include"S2P_int.h"
#include"S2P_prv.h"

extern MGPIO_Config_t s2p_shift_pin;
extern MGPIO_Config_t s2p_latch_pin;
extern MGPIO_Config_t s2p_data_pin;

void HS2P_vInit(void)
{

	MGPIO_vInit(&s2p_shift_pin);
	MGPIO_vInit(&s2p_latch_pin);
	MGPIO_vInit(&s2p_data_pin);
}

static void ShiftData(void){
	MGPIO_vSetPinVal(s2p_shift_pin.Port,s2p_shift_pin.Pin,GPIO_HIGH);
	//DELAY
	MGPIO_vSetPinVal(s2p_shift_pin.Port,s2p_shift_pin.Pin,GPIO_LOW);
	//DELAY

}static void LatchtData(void){
	MGPIO_vSetPinVal(s2p_shift_pin.Port,s2p_shift_pin.Pin,GPIO_HIGH);
	//DELAY
	MGPIO_vSetPinVal(s2p_shift_pin.Port,s2p_shift_pin.Pin,GPIO_LOW);
	//DELAY

}

void HS2P_vSendData(u32 A_u32Data)
{


	/* 1- shift data on data pin */
	/* 2- shift data using shift pin */
	/* 	2a send high*/
	/* 	2b delay*/
	/* 	2c send low*/


	/* 3 send a latch signal */
	/* 	2a send high*/
	/* 	2b delay*/
	/* 	2c send low*/


	for(int i=0; i<8*S2P_NUMBER_OF_REGS ; i++){

		MGPIO_vSetPinVal( s2p_shift_pin.Port , s2p_shift_pin.Pin , GET_BIT(A_u32Data,i));
		ShiftData();
	}
	LatchtData();

}




