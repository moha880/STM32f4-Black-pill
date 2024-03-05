/*
 * FMI_prg.c
 *
 *  Created on: Oct 22, 2022
 *      Author: Ibrahem
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include"FMI_cfg.h"
#include"FMI_int.h"
#include"FMI_prv.h"

void FMI_vEraseAppArea(void)
{
	/**/

}
void FMI_vSectorErase(u8 A_u8SectorNo)
{
	/*1- wait if flash is busy (BSY)*/
	while (GET_BIT(FMI-> SR ,BSY)==1){}
	/*2- unlock flash register using KEYR*/
	if(GET_BIT(FMI-> CR ,LOCK)==1){
		FMI->KEYR =FMI_KEY1;
		FMI->KEYR =FMI_KEY2   ;
	}
	/*3- selector sector number to erase*/
	FMI-> CR &=~((u32)(0b1111<<3));
	FMI-> CR |= (A_u8SectorNo <<3);
	/*4- select erase operation*/
	SET_BIT(FMI-> CR ,SER);
	/*5- start erase operation*/
	SET_BIT(FMI-> CR ,STRT);

	/*6- wait for busy flag*/
	while (GET_BIT(FMI-> SR ,BSY)==1){}

	/*7- clear end of operation flag EOP*/
	SET_BIT(FMI-> SR ,EOP);

	/*8- DeSelect erase operation reverse of step 4*/

	CLR_BIT(FMI-> CR ,SER);



}
void FMI_vFlashWrite(u32 A_u32Address, u16* A_pu16Data,u16 A_u16Length)
{
	/*1- wait if flash is busy (BSY)*/
	while (GET_BIT(FMI-> SR ,BSY)==1){}
	/*2- unlock flash register using KEYR*/
	if(GET_BIT(FMI-> CR ,LOCK)==1){
		FMI->KEYR =FMI_KEY1;
		FMI->KEYR =FMI_KEY2;
	}
	/*3- select element size (PSIZE) */
	FMI->CR &=~((u32)(0b11<<8));
	FMI->CR |= (0b01<<8 );
	/*4- Activate programming mode  */
	SET_BIT(FMI-> CR ,PG);
	/*5- WRITE DATA ARRAY ON FLASH ADDRESS  */
	for(u16 i=0 ;i<A_u16Length;i++){

		*((volatile u16*)A_u32Address) = A_pu16Data[i];
		A_u32Address +=2 ;

		/*6- wait for busy flag*/
		while (GET_BIT(FMI-> SR ,BSY)==1){}
		/*7- clear end of operation flag EOP*/
		SET_BIT(FMI-> SR ,EOP);

	}
	/*8- DeActivate programming mode  */
	CLR_BIT(FMI-> CR ,PG);

}
