/*
 * SPI_int.h
 *
 *  Created on: Jan 31, 2023
 *      Author: Ibrahem
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_




typedef struct{
	SPIx_MemMap_t* pSPIx;	// this holds the base address of spix(1 ,2,3,4) peripheral
	u8	SPI_DeviceMode;		// Refer @SPI_devicemode
	u8	SPI_BusConfig;		// Refer @SPI_BusConfiguration
	u8	SPI_SclkSpeed;		// Refer @SPI_ClockSpeed
	u8	SPI_DFF;			// Refer @SPI_DFF
	u8	SPI_CPOL;			// Refer @SPI_CPOL
	u8	SPI_CPHA;			// Refer @SPI_CPHA
	u8	SPI_FrameForm;
	u8	SPI_SSM;			// Refer @SPI_SSM
	u8	SPI_SSI;			// Refer @SPI_SSM
}MSPI_Config_t ;



//typedef struct{
//	SPIx_MemMap_t   *pSPIx 	 ;	// this holds the base address of spix(SPI1 , SPI2 , SPI3 , SPI4) peripheral
//
//}SPI_Handle_t;

void MSPI_vInit(MSPI_Config_t* pSPIconfig);
u16   MSPI_u8Transmit__receive(MSPI_Config_t* pSPIconfig, u16 A_u16Data);
void   MSPI_u8Transmit(MSPI_Config_t* pSPIconfig, u8 A_u16Data);
//u8   MSPI_u8receive(void);



#endif /* MCAL_SPI_SPI_INT_H_ */
