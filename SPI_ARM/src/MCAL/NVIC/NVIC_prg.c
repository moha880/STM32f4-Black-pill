/*
 * NVIC_prg.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Ibrahem
 */



#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include"NVIC_cfg.h"
#include"NVIC_int.h"
#include"NVIC_prv.h"

static u32 GS_u32GroupConf;

void MNVIC_vEnableInterrupt(u8 A_u8IntId){

	NVIC -> ICPR[ A_u8IntId / 32 ] = 1<<(A_u8IntId%32);
}
void MNVIC_vDisableInterrupt(u8 A_u8IntId){
	NVIC -> ICPR[ A_u8IntId / 32 ] = 1<<(A_u8IntId%32);

}
void MNVIC_vSetPending(u8 A_u8IntId){
	NVIC -> ICPR[ A_u8IntId / 32 ] = 1<<(A_u8IntId%32);

}
void MNVIC_vClrPending(u8 A_u8IntId){
	NVIC -> ICPR[ A_u8IntId / 32 ] = 1<<(A_u8IntId%32);

}
u8 MNVIC_u8GetStatus(u8 A_u8IntId){

	u8 L_u8Status=GET_BIT(NVIC -> IAPR[ A_u8IntId / 32 ],(A_u8IntId%32));

	return L_u8Status;

}
void MNVIC_vPriorityCfg(u8 A_u8PriGroup){

	GS_u32GroupConf = VECTKEY | (A_u8PriGroup<<8);
	SCB ->AIRCR = GS_u32GroupConf;
}
void MNVIC_vSetPriority(s8 A_s8IntId ,u8 A_u8Group,u8 A_u8SubGroup){

	 u8 L_u8Priority =(A_u8Group<<(((GS_u32GroupConf&0x00000700)>>8)-3))| A_u8SubGroup;
	if(A_s8IntId<0){

		if(A_s8IntId==MEMORY_MANAGE || A_s8IntId==BUS_FAULT || A_s8IntId==USAGE_FAULT){
			A_s8IntId+=3;
			SCB -> SHPR1 |= (L_u8Priority <<(A_s8IntId*8 + 4));

		}else if(A_s8IntId==SV_CALL){
			A_s8IntId+=8;
			SCB -> SHPR2 |= (L_u8Priority <<(A_s8IntId*8 + 4));

		}else if(A_s8IntId==PEND_SV||A_s8IntId==SYSTICK){
			A_s8IntId+=9;
			SCB -> SHPR3 |= (L_u8Priority <<(A_s8IntId*8 + 4));

		}
	}
	else if(A_s8IntId>=0){

		NVIC -> IPR[ A_s8IntId] = ((A_u8Group<<L_u8Priority)+A_u8SubGroup)<<4;

	}

}


