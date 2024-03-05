/*
 * LEDMTX_prg.c
 *
 *  Created on: Sep 29, 2022
 *      Author: Ibrahem
 */


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_int.h"
#include"../../MCAL/STK/STK_int.h"
#include"../../HAL/S2P/S2P_int.h"

#include"LEDMTX_prv.h"
#include"LEDMTX_cfg.h"
#include"LEDMTX_int.h"


void HLEDMTX_vInit(void)
{
#if METHOD==LEDMTX_DIRECT
	for(int i =0;i<NO_COLS;i++)
	{
		MGPIO_vInit(&cols[i]);
	}
	for(int i =0;i<NO_ROWS;i++)
	{
		MGPIO_vInit(&rows[i]);
	}
#endif
#if METHOD==LEDMTX_S2P
	HS2P_vInit();
#endif

	MSTK_vInit();
}


//static void LEDMTX_vDiableALLColumns(void){
//	for(u8 i =0;i<NO_COLS;i++){
//		MGPIO_vSetPinVal( cols[i].Port,cols[i].Pin,GPIO_LOW );
//	}
//
//}
//static void LEDMTX_vSetRowValues(u8 RowNo ){
//	for(u8 i =0;i<NO_COLS;i++){
//		MGPIO_vSetPinVal( rows[i].Port,rows[i].Pin,GET_BIT(RowNo,i) );
//	}
//
//}
//static void LEDMTX_vSetCurrentColumn(u8 ColNo ){
//	MGPIO_vSetPinVal( cols[ColNo].Port,cols[ColNo].Pin,GPIO_HIGH );
//
//}



void HLEDMTX_vDisplayFrame(u8 A_u8Frame[],u32 A_u32Frame_delay)
{
#if METHOD==LEDMTX_S2P
	u16 L_u16S2pData;
#endif
	for(u8 j =0;j<A_u32Frame_delay;j++){
		for(u8 i =0;i<NO_COLS;i++){
#if METHOD==LEDMTX_DIRECT
			/* 1 disable all columns*/
			LEDMTX_vDiableALLColumns();
			/* 2 set row values*/
			LEDMTX_vSetRowValues(A_u8Frame[i]);
			/* 3 set current column*/
 			LEDMTX_vSetCurrentColumn(i);
#endif

#if METHOD==LEDMTX_S2P
			/* 1 disable all columns*/
 			L_u16S2pData=0x00ff;
 			HS2P_vSendData(L_u16S2pData);
			/* 2 set row values		*/
			/* 3 set current column	*/
 			L_u16S2pData = ((u16)A_u8Frame[i])|(((u16)(1<<i))<<8);
 			HS2P_vSendData(L_u16S2pData);
#endif
			/* 4 delay for suitable FBS*/
			MSTK_vSetBusyWait(SCAN_TIME);		//2.5MS

		}
	}
}

//void HLEDMTX_vDisplayMatrix(u8 A_u8Matrix[][NO_COLS] ,u32 A_u32Matrix_delay){}



























