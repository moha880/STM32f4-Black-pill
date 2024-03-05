/*
 * SPI_prg.c
 *
 *  Created on: Jan 31, 2023
 *      Author: Ibrahem
 */


#include "../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/STK/STK_int.h"

#include "../RCC/RCC_int.h"
#include "../RCC/RCC_cfg.h"

#include"SPI_prv.h"
#include"SPI_int.h"
#include"SPI_cfg.h"

void MSPI_vInit(MSPI_Config_t* pSPIconfig){
	MRCC_vInit();
	MRCC_vEnableClock(RCC_APB2, RCC_EN_SPI1);
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);
	MGPIO_vInit(&SP1[1]);
	MGPIO_vInit(&SP1[2]);
	MGPIO_vInit(&SP1[0]);

	u16 SPI_temp=0;

	/* ENABLE SPI1 PERIPHERAL */
	SET_BIT(SPI_temp, SPE);

	if (pSPIconfig->SPI_BusConfig == SPI_BUS_CONFIG_FD) {
		// BIDIMODE should be cleared
		SPI_temp &= ~( 1 << BIDIMODE) ;
	}else if (pSPIconfig->SPI_BusConfig == SPI_BUS_CONFIG_HD) {
		// BIDIMODE should be set
		SPI_temp |=  ( 1 << BIDIMODE) ;
		SPI_temp |=  ( 1 << BIDIOE) ;

	}else if (pSPIconfig->SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY) {
		// BIDIMODE should be cleared ;
		SPI_temp &= ~( 1 << BIDIMODE) ;
		// RXOONLY bit should be set
		SPI_temp |=  ( 1 << RXONLY) ;
	}


	SPI_temp |= (pSPIconfig->SPI_DeviceMode <<MSTR);
	// configure spi cpol
	SPI_temp |= (pSPIconfig->SPI_CPOL 		<<CPOL);
	// configure spi cpha
	SPI_temp |= (pSPIconfig->SPI_CPHA 		<<CPHA);
	// configure spi ssm
	SPI_temp |= (pSPIconfig->SPI_SSM 		<<SSM);
	// configure spi ssI

	SPI_temp |= (pSPIconfig->SPI_SSI 		<<SSI);
	// configure spi dff mode
	SPI_temp |= (pSPIconfig->SPI_DFF 		<<DFF);
	// configure spi clock speed
	SPI_temp |= (pSPIconfig->SPI_SclkSpeed	<<BR);
	// configure MSB/LSB
	SPI_temp |= (pSPIconfig->SPI_FrameForm	<<LSBFIRST);




	SET_BIT(SPI_temp, SSI);


	/* Data Format */

	pSPIconfig->pSPIx->CR1=SPI_temp;
}


void   MSPI_u8Transmit(MSPI_Config_t* pSPIconfig, u8 A_u16Data){
	pSPIconfig->pSPIx->DR=A_u16Data;
	while(GET_BIT(pSPIconfig->pSPIx->SR, BSY)==1);

}

u16   MSPI_u8receive(MSPI_Config_t* pSPIconfig){
	u16 l_data=0;
	l_data= pSPIconfig->pSPIx->DR;

	return 	l_data;
}


u16   MSPI_u8Transmit__receive(MSPI_Config_t* pSPIconfig, u16 A_u16Data){

	pSPIconfig->pSPIx->DR=A_u16Data;

//	if(A_u16Data =='M')
//	{
//		MGPIO_vSetPinVal(GPIO_PORTA, 2,GPIO_HIGH);
//
//	}
//	else
//	{
//
//	}
//
	while(GET_BIT(pSPIconfig->pSPIx->SR, BSY)==1);
//	MGPIO_vSetPinVal(GPIO_PORTA, 3,GPIO_HIGH);

	return pSPIconfig->pSPIx->DR;




}
















