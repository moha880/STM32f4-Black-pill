/*
 * TFT_prg.c
 *
 *  Created on: Jun 9, 2023
 *      Author: Ibrahem
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"

#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/RCC/RCC_cfg.h"

#include "../../MCAL/SPI/SPI_prv.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "../../MCAL/SPI/SPI_cfg.h"

#include "../../MCAL/STK/STK_int.h"


#include"TFT_int.h"
#include"TFT _prv.h"
#include"TFT_cfg.h"


MGPIO_Config_t TFT_A0_pin= {
			.Port=GPIO_PORTA,
			.Pin=GPIO_PIN0,
			.Mode=GPIO_MODE_OUTPUT,
			.OutputType=GPIO_OTYPE_PUSHPULL,
			.OutputSpeed=GPIO_SPEED_VHIGH,};

MGPIO_Config_t TFT_RST_A1_pin= {
			.Port=GPIO_PORTA,
			.Pin=GPIO_PIN1,
			.Mode=GPIO_MODE_OUTPUT,
			.OutputType=GPIO_OTYPE_PUSHPULL,
			.OutputSpeed=GPIO_SPEED_VHIGH,};



static u16 current_XPos_start;
static u16 current_XPos_end;
static u16 current_YPos_start;
static u16 current_YPos_end;


void TFT_vWriteCmd(u16 cmd){

	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	MSPI_u8Transmit(&SPIconfig,cmd);

}

void TFT_vWriteData(u16 data){

	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	MSPI_u8Transmit(&SPIconfig,data);


}

void MTFT_ResetSequance(){
	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(1600);


	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(1000);


	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(1600);
	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(1600);

	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetDelayMiliSecounds(1000);

}

void TFT_vInit(void)
{

	MSPI_vInit(&SPIconfig);

	MSTK_vInit();

	MGPIO_vInit(&TFT_A0_pin);
	MGPIO_vInit(&TFT_RST_A1_pin);




	/* 2- reset sequence */
	MTFT_ResetSequance();


	/* 3- send SLEEP OUT (SLPOUT) command (0x11) */
	TFT_vWriteCmd(0X11);

	/* 4- wait 15 ms   */
	MSTK_vSetBusyWait(240000);

	/* 5- send Color Mode Command -> RGB565  */
	TFT_vWriteCmd(0X3A);
	TFT_vWriteData(0X05);


	/* 6- Display on command  DISPON (0x29)  */
	TFT_vWriteCmd(0X29);

}


void TFT_vShowImage(const u16 A_pu16Img[], u32 A_u32ImgSize){


	/* 1- set X position */
	TFT_vWriteCmd(0x2A);
	// xstart: 0, xEnd: 127
	TFT_vWriteData(0);
	TFT_vWriteData(0);
	TFT_vWriteData(0);
	TFT_vWriteData(127);

	/* 2- set Y position */
	TFT_vWriteCmd(0x2B);
	// ystart: , yEnd: 159
	TFT_vWriteData(0);
	TFT_vWriteData(0);
	TFT_vWriteData(0);
	TFT_vWriteData(159);

	/* 3- send image data */
	TFT_vWriteCmd(0x2C);

	for(u32 i=0; i<A_u32ImgSize-1; i++)
	{
		TFT_vWriteData((u8)A_pu16Img[i] >> 8); // Most-Significatn byte
		TFT_vWriteData((u8)A_pu16Img[i] & 0x00FF); // Least-Significant Byte
		MSTK_vSetBusyWait(2400);


	}

}

void TFT_vSetXPos(u16 xStart, u16 xEnd)
{
	current_XPos_start = xStart;
	current_XPos_end = xEnd;
	/* 1- set X position */
	TFT_vWriteCmd(0x2A);
	// xstart: 0, xEnd: 127
	TFT_vWriteData(0);
	TFT_vWriteData(xStart);
	TFT_vWriteData(0);
	TFT_vWriteData(xEnd);
}
void TFT_vSetYPos(u16 yStart, u16 yEnd)
{
	current_YPos_start = yStart;
	current_YPos_end  = yEnd ;
	/* 2- set Y position */
	TFT_vWriteCmd(0x2B);
	// ystart: 0, yEnd: 159
	TFT_vWriteData(0);
	TFT_vWriteData(yStart);
	TFT_vWriteData(0);
	TFT_vWriteData(yEnd);
}

void TFT_vFillRectangle(Color_t Color)
{
	u32 No_pixels = (current_XPos_end-current_XPos_start)*(current_YPos_end-current_YPos_start);
	/* 3- send image data */
	TFT_vWriteCmd(0x2C);

	for(u32 i=0; i<No_pixels; i++)
	{

		TFT_vWriteData(Color.Color >> 8); // Most-Significatn byte
		TFT_vWriteData(Color.Color & 0x00FF); // Least-Significant Byte
	}



}
void TFT_vFillBackground(Color_t Color)
{
	/* 1- set X position */
	TFT_vWriteCmd(0x2A);
		// xstart: 0, xEnd: 127
	TFT_vWriteData(0);
		TFT_vWriteData(0);
		TFT_vWriteData(0);
		TFT_vWriteData(127);

		/* 2- set Y position */
		TFT_vWriteCmd(0x2B);
		// ystart: , yEnd: 159
		TFT_vWriteData(0);
		TFT_vWriteData(0);
		TFT_vWriteData(0);
		TFT_vWriteData(159);

		TFT_vFillRectangle(Color);

}

