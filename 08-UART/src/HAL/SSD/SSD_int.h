/*
 * SSD_int.h
 *
 *  Created on: Jul 17, 2022
 *      Author: Ibrahem
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_


#define COM_CATHODE   1
#define COM_ANODE     0



#define SSD_TYPE   COM_CATHODE
#define SSD_PORT   DIO_PORTC





#define SSD_1  1
#define SSD_2  2

void HSSD_vInit(void);   //99% mn el drivers bib2a fiha tazbeet ll48l ,mdrstna bn3tbrha void
//void HSSD_vInit_ARM(u8 A_u8Pins[]);   //99% mn el drivers bib2a fiha tazbeet ll48l ,mdrstna bn3tbrha void
void HSSD_vDisplayNum(/*u8 SSDId ,*/ u8 A_u8Num);
void HSSD_vTurnOff(void);



#endif /* HAL_SSD_SSD_INT_H_ */


