/*
 * GPIO_prv.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_GPIO_GPIO_PRV_H_
#define MCAL_GPIO_GPIO_PRV_H_

#define GPIOA_BASE_ADDR		0X40020000
#define GPIOB_BASE_ADDR		0X40020400
#define GPIOC_BASE_ADDR		0X40020800

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_MemMap_t;

#define GPIOA		((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDR))
#define GPIOB		((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDR))
#define GPIOC		((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDR))

#endif /* MCAL_GPIO_GPIO_PRV_H_ */
