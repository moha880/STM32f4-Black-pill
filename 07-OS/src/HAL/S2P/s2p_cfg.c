/*
 * s2p_cfg.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Ibrahem
 */
#include"../../LIB/STD_TYPES.h"

#include"../../MCAL/GPIO/GPIO_int.h"


MGPIO_Config_t s2p_shift_pin={
		.Port=GPIO_PORTA,		.Pin=GPIO_PIN5,
		.Mode=GPIO_MODE_OUTPUT,	.OutputSpeed=GPIO_SPEED_LOW,
		.OutputType=GPIO_OTYPE_PUSHPULL

};
MGPIO_Config_t s2p_latch_pin={
		.Port=GPIO_PORTA,		.Pin=GPIO_PIN6,
		.Mode=GPIO_MODE_OUTPUT,	.OutputSpeed=GPIO_SPEED_LOW,
		.OutputType=GPIO_OTYPE_PUSHPULL

};
MGPIO_Config_t s2p_data_pin={
		.Port=GPIO_PORTA,		.Pin=GPIO_PIN7,
		.Mode=GPIO_MODE_OUTPUT,	.OutputSpeed=GPIO_SPEED_LOW,
		.OutputType=GPIO_OTYPE_PUSHPULL

};


