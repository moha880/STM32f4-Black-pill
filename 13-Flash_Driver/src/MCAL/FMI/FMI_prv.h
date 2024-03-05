/*
 * FMI_prv.h
 *
 *  Created on: Oct 22, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_FMI_FMI_PRV_H_
#define MCAL_FMI_FMI_PRV_H_

#define FMI_KEY1		0x45670123
#define FMI_KEY2		0xCDEF89AB



#define FMI_BASE_ADDR		0x40023C00

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FMI_MemMap_t;

#define FMI		((volatile FMI_MemMap_t*)(FMI_BASE_ADDR))

#define LOCK		31
#define BSY			16
#define SER			1
#define STRT		16
#define EOP			0
#define PG			0


#endif /* MCAL_FMI_FMI_PRV_H_ */
