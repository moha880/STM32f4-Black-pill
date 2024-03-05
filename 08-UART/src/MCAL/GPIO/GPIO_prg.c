/*
 * GPIO_prg.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Ibrahem
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include"GPIO_prv.h"
#include"GPIO_cfg.h"
#include"GPIO_int.h"













void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Mode){
	/*GPIO port mode register (GPIOx_MODER) */
	switch(A_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11<<(A_u8PinNo*2));
		GPIOA->MODER |= (A_u8Mode<<(A_u8PinNo*2));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11<<(A_u8PinNo*2));
		GPIOB->MODER |= (A_u8Mode<<(A_u8PinNo*2));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(0b11<<(A_u8PinNo*2));
		GPIOC->MODER |= (A_u8Mode<<(A_u8PinNo*2));
		break;
	}
}
void MGPIO_vSetPinOutputType(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutType){
	/*GPIO port output type register (GPIOx_OTYPER) */
	if(A_u8OutType==GPIO_OTYPE_OPENDRAIN){
		switch(A_u8PortId)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}else if(A_u8OutType==GPIO_OTYPE_PUSHPULL){
		switch(A_u8PortId)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}

	}

}
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutSpeed){
	/**
	 * GPIO port output speed register (GPIOx_OSPEEDR)
	 */
	switch(A_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOA->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOB->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOC->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;
	}
}
void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PullType){
	/*GPIO port pull-up/pull-down register (GPIOx_PUPDR) */

	switch(A_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->PUPDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOA->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;
	case GPIO_PORTB:
		GPIOB->PUPDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOB->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;
	case GPIO_PORTC:
		GPIOC->PUPDR &= ~(0b11<<(A_u8PinNo*2));
		GPIOC->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;
	}
}
u8 MGPIO_u8GetPinValue(u8 A_u8PortId, u8 A_u8PinNo)
{
	u8 L_u8PinValue = 0;
	switch(A_u8PortId)
	{
	case GPIO_PORTA:
		L_u8PinValue = GET_BIT(GPIOA->IDR, A_u8PinNo);
		 break;
	case GPIO_PORTB:
		L_u8PinValue = GET_BIT(GPIOB->IDR, A_u8PinNo);
		 break;
	case GPIO_PORTC:
		L_u8PinValue = GET_BIT(GPIOC->IDR, A_u8PinNo);
		 break;
	}

	return L_u8PinValue;
}

void MGPIO_vSetPinVal(u8 A_u8PortId,
					  u8 A_u8PinNo,
					  u8 A_u8PinVal)
{
	if(A_u8PinVal == GPIO_HIGH)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,  A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,  A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,  A_u8PinNo);
			break;
		}
	}
	else if(A_u8PinVal == GPIO_LOW)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->ODR,  A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->ODR,  A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->ODR,  A_u8PinNo);
			break;
		}
	}
}
//void MGPIO_vSetAlternativeFunction (u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8AltFun){}


void MGPIO_vInit(MGPIO_Config_t* A_xPinConfig)
{

	MGPIO_vSetPinMode(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->Mode);
	MGPIO_vSetPinOutputType(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->OutputType);
	MGPIO_vSetPinOutputSpeed(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->OutputSpeed);
	MGPIO_vSetPinInputPull(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->InputPull);
//	MGPIO_vSetAlternativeFunction(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->AltFunc);

}


