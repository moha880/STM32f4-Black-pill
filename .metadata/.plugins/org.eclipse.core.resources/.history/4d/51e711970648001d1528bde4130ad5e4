/*
 * GPIO_int.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_


#define GPIO_MODE_INPUT		0b00
#define GPIO_MODE_OUTPUT	0b01
#define GPIO_MODE_ALTFUN	0b10
#define GPIO_MODE_ANALOG	0b11

#define GPIO_INPUT_NO_PULL		0b00
#define GPIO_INPUT_PULL_UP		0b01
#define GPIO_INPUT_PULL_DOWN	0b10


#define GPIO_PORTA			0
#define GPIO_PORTB			1
#define GPIO_PORTC			2


#define GPIO_OTYPE_PUSHPULL         0
#define GPIO_OTYPE_OPENDRAIN		1

#define GPIO_SPEED_LOW      0b00
#define GPIO_SPEED_MED		0b01
#define GPIO_SPEED_HIGH		0b10
#define GPIO_SPEED_VHIGH	0b11


#define GPIO_LOW		0
#define GPIO_HIGH		1

#define GPIO_PIN0       0
#define GPIO_PIN1       1
#define GPIO_PIN2       2
#define GPIO_PIN3       3
#define GPIO_PIN4       4
#define GPIO_PIN5       5
#define GPIO_PIN6       6
#define GPIO_PIN7       7
#define GPIO_PIN8       8
#define GPIO_PIN9       9
#define GPIO_PIN10       10
#define GPIO_PIN11       11
#define GPIO_PIN12       12
#define GPIO_PIN13       13
#define GPIO_PIN14       14
#define GPIO_PIN15       15

typedef struct{
	u8 Port;
	u8 Pin;
	u8 Mode;
	u8 OutputType;
	u8 OutputSpeed;
	u8 InputPull;
	u8 AltFunc;
}MGPIO_Config_t;










void MGPIO_vInit(MGPIO_Config_t* A_xPinConfig);


/*GPIO port mode register (GPIOx_MODER) */
void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Mode);

/*GPIO port output type register (GPIOx_OTYPER) */
void MGPIO_vSetPinOutputType(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutType);

/*GPIO port output speed register (GPIOx_OSPEEDR)*/
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutSpeed);

/*GPIO port pull-up/pull-down register (GPIOx_PUPDR) */
void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PullType);

/*GPIO port input data register (GPIOx_IDR) */
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo);

/*GPIO port output data register (GPIOx_ODR) */
void MGPIO_vSetPinVal(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8PinVal);

void MGPIO_vSetPortVal(u8 A_u8PortId,u8 A_u8PinVal);

/*GPIO port bit set/reset register (GPIOx_BSRR)  */
void MGPIO_vSetPinVal_fast(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8PinVal);

/*GPIO port mode register (GPIOx_MODER) */
void MGPIO_vSetAlternativeFunction (u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8AltFun);


#endif /* MCAL_GPIO_GPIO_INT_H_ */
