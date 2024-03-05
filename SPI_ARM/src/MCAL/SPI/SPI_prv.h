/*
 * SPI_prv.h
 *
 *  Created on: Jan 31, 2023
 *      Author: Ibrahem
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_



#define SPI1_BASE_ADDR		0x40013000
#define SPI2_BASE_ADDR		0x40003800
#define SPI3_BASE_ADDR		0x40003C00
#define SPI4_BASE_ADDR		0x40013400



typedef struct{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPIx_MemMap_t;


#define SPI1  ((SPIx_MemMap_t*)(SPI1_BASE_ADDR))
#define SPI2  ((SPIx_MemMap_t*)(SPI2_BASE_ADDR))
#define SPI3  ((SPIx_MemMap_t*)(SPI3_BASE_ADDR))
#define SPI4  ((SPIx_MemMap_t*)(SPI4_BASE_ADDR))



/**********************************************/
/* 				CR1 BITS Mapping 			  */
/**********************************************/

#define BIDIMODE		15
#define BIDIOE			14
#define CRCEN			13
#define CRCNEXT 		12
#define DFF 			11
#define RXONLY			10
#define SSM 			9
#define SSI 			8
#define LSBFIRST 		7
#define SPE 			6
#define BR		 		3  // [2:0]
#define MSTR 			2
#define CPOL 			1
#define CPHA			0

/**********************************************/
/* 				CR2 BITS Mapping 			  */
/**********************************************/
#define TXEIE 			7
#define RXNEIE 			6
#define ERRIE 			5
#define FRF				4
#define SSOE 			2
#define TXDMAEN 		1
#define RXDMAEN			0

/**********************************************/
/* 				SR BITS Mapping 			  */
/**********************************************/
#define FRE 			8
#define BSY 			7
#define OVR 			6
#define MODF 			5
#define CRCERR			4
#define UDR				3
#define CHSIDE 			2
#define TXE 			1
#define RXNE			0

/**********************************************/
/* 				DR BITS Mapping 			  */
/* 				Is Not Mapped    			  */
/**********************************************/

/**********************************************/
/* 				CRCPR BITS Mapping 			  */
/* 				Is Not Mapped    			  */
/**********************************************/

/**********************************************/
/* 				RXCRCR BITS Mapping 			  */
/* 				Is Not Mapped    			  */
/**********************************************/

/**********************************************/
/* 				TXCRCR BITS Mapping 			  */
/* 				Is Not Mapped    			  */
/**********************************************/

/**********************************************/
/* 				I2SCFGR BITS Mapping 			  */
/**********************************************/
#define I2SMOD 			11
#define I2SE 			10
#define I2SCFG 			8
#define PCMSYNC 		7
#define I2SSTD			4
#define CKPOL 			3
#define DATLEN 	    	1
#define CHLEN			0

/**********************************************/
/* 				I2SPR BITS Mapping 			  */
/**********************************************/
#define MCKOE 			9
#define ODD 			8
#define I2SDIV			0








#define SPI_DEVICE_MODE_MASTER	1
#define SPI_DEVICE_MODE_SLAVE	0


	// @SPI_busconfig

#define SPI_BUS_CONFIG_FD				1
#define SPI_BUS_CONFIG_HD				2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	3


#define SPI_MSB_FORMAT			0
#define SPI_LSB_FORMAT			1

	//@SPI_ClockConfig

#define SPI_SCLK_SPEED_DIV2					0
#define SPI_SCLK_SPEED_DIV4					1
#define SPI_SCLK_SPEED_DIV8					2
#define SPI_SCLK_SPEED_DIV16				3
#define SPI_SCLK_SPEED_DIV32				4
#define SPI_SCLK_SPEED_DIV64				5
#define SPI_SCLK_SPEED_DIV128				6
#define SPI_SCLK_SPEED_DIV256				7

	//@SPI_DFF

#define SPI_DFF_8BITS						0
#define SPI_DFF_16BITS						1

	//@SPI_CPOL

#define SPI_CPOL_LOW						0
#define SPI_CPOL_HIGH						1

	//@SPI_CPHA

#define SPI_CPHA_LOW						0
#define SPI_CPHA_HIGH						1

//@SPI_SSM

#define SPI_SSM_DI						0
#define SPI_SSM_EN						1

//@SPI_SSM

#define SPI_SSI_DI						0
#define SPI_SSI_EN						1

// SPI flag status shifts

#define SPI_RXNE_FLAG					(1 << SPI_SR_RXNE)
#define SPI_TXE_FLAG					(1 << SPI_SR_TXE)
#define SPI_CHSIDE_FLAG					(1 << SPI_SR_CHSIDE)
#define SPI_UDR_FLAG					(1 << SPI_SR_UDR)
#define SPI_CRCERR_FLAG					(1 << SPI_SR_CRCERR)
#define SPI_MODF_FLAG					(1 << SPI_SR_MODF)
#define SPI_OVR_FLAG					(1 << SPI_SR_OVR)
#define SPI_BSY_FLAG					(1 << SPI_SR_BSY)
#define SPI_FRE_FLAG					(1 << SPI_SR_FRE)

// SPI application states

#define SPI_READY						0
#define SPI_BUSY_IN_RX					1
#define SPI_BUSY_IN_TX					2

// SPI Application events

#define SPI_EVENT_TX_CMPLT				1
#define SPI_EVENT_RX_CMPLT				2
#define SPI_EVENT_OVR_ERR				3
#define SPI_EVENT_CRC_ERR				4











#endif /* MCAL_SPI_SPI_PRV_H_ */