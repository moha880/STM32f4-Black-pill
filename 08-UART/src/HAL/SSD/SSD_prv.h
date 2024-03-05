/*
 * SSD_prv.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Ibrahem
 */

#ifndef HAL_SSD_SSD_PRV_H_
#define HAL_SSD_SSD_PRV_H_

#define AVR			1
#define ARM			2


#define PORTA		*((volatile u8*)(0x3B))
#define DDRA		*((volatile u8*)(0x3A))
#define PINA		*((volatile u8*)(0x39))

#define PORTB		*((volatile u8*)(0x38))
#define DDRB		*((volatile u8*)(0x37))
#define PINB		*((volatile u8*)(0x36))

#define PORTC		*((volatile u8*)(0x35))
#define DDRC		*((volatile u8*)(0x34))
#define PINC		*((volatile u8*)(0x33))

#define PORTD		*((volatile u8*)(0x32))
#define DDRD		*((volatile u8*)(0x31))
#define PIND		*((volatile u8*)(0x30))


#endif /* HAL_SSD_SSD_PRV_H_ */
