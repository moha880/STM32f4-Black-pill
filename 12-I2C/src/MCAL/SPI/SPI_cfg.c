/*
 * SPI_cfg.c
 *
 *  Created on: Jan 31, 2023
 *      Author: Ibrahem
 */


#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_int.h"

#include"SPI_prv.h"
#include"SPI_int.h"





	MGPIO_Config_t SP1[3]={

			/*configure MOSI1 as alt fun*/
			{.Port=GPIO_PORTA,.Pin=GPIO_PIN7,.Mode=GPIO_MODE_ALTFUN,.OutputType=GPIO_OTYPE_PUSHPULL,.OutputSpeed=GPIO_SPEED_LOW,.InputPull=GPIO_INPUT_NO_PULL,.AltFunc=ALT_FUN_5},
			/*configure MISO1 as alt fun*/
			{.Port=GPIO_PORTA,.Pin=GPIO_PIN6,.Mode=GPIO_MODE_ALTFUN,.OutputType=GPIO_OTYPE_PUSHPULL,.OutputSpeed=GPIO_SPEED_LOW,.InputPull=GPIO_INPUT_NO_PULL,.AltFunc=ALT_FUN_5},
			/*configure Sck1 as alt fun*/
			{.Port=GPIO_PORTA,.Pin=GPIO_PIN5,.Mode=GPIO_MODE_ALTFUN,.OutputType=GPIO_OTYPE_PUSHPULL,.OutputSpeed=GPIO_SPEED_LOW,.InputPull=GPIO_INPUT_NO_PULL,.AltFunc=ALT_FUN_5}
	};

	MSPI_Config_t SPIconfig = {

			(SPIx_MemMap_t *)SPI1,// this holds the base address of spix(1 ,2,3,4) peripheral
			.SPI_DeviceMode=SPI_DEVICE_MODE_MASTER,		// Refer @SPI_devicemode
			.SPI_BusConfig=SPI_BUS_CONFIG_HD,			// Refer @SPI_BusConfiguration
			.SPI_SclkSpeed=SPI_SCLK_SPEED_DIV4,			// Refer @SPI_ClockSpeed
			.SPI_DFF=SPI_DFF_8BITS,						// Refer @SPI_DFF
			.SPI_CPOL=SPI_CPOL_HIGH,					// Refer @SPI_CPOL
			.SPI_CPHA=SPI_CPHA_HIGH,						// Refer @SPI_CPHA
			.SPI_FrameForm=SPI_MSB_FORMAT,						// Refer @SPI_CPHA
			.SPI_SSM=SPI_SSM_EN,						// Refer @SPI_SSM
			.SPI_SSI=SPI_SSI_EN						// Refer @SPI_SSM

	};





