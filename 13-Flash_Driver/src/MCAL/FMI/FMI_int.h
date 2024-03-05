/*
 * FMI_int.h
 *
 *  Created on: Oct 22, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_FMI_FMI_INT_H_
#define MCAL_FMI_FMI_INT_H_

void FMI_vEraseAppArea(void);
void FMI_vSectorErase(u8 A_u8SectorNo);
void FMI_vFlashWrite(u32 A_u32Address, u16* A_pu16Data,u16 A_u16Length);



#endif /* MCAL_FMI_FMI_INT_H_ */
