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




static u16 current_XPos_start;
static u16 current_XPos_end;
static u16 current_YPos_start;
static u16 current_YPos_end;


void TFT_vWriteCmd(u16 cmd){
//int c=0;
	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	MSPI_u8Transmit__receive(&SPIconfig,cmd);

//	if (c==0X11){
//	MGPIO_vSetPinVal(GPIO_PORTA, 2,1);
//	}
}

void TFT_vWriteData(u16 data){

	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	MSPI_u8Transmit__receive(&SPIconfig,data);


}

void MTFT_ResetSequance(){
	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(160000);


	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(150);


	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(160000);
	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(160000);

	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(30000000);

}

void TFT_vInit(void)
{

	int b=0;
	MGPIO_vSetPinMode(GPIO_PORTA, b, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, b,GPIO_SPEED_VHIGH);
	MGPIO_vSetPinOutputType(GPIO_PORTA, b, GPIO_OTYPE_PUSHPULL);

	int a=1;
	MGPIO_vSetPinMode(GPIO_PORTA, a, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, a,GPIO_SPEED_VHIGH);
	MGPIO_vSetPinOutputType(GPIO_PORTA, a, GPIO_OTYPE_PUSHPULL);



	MSPI_vInit(&SPIconfig);

	MSTK_vInit();

	MTFT_ResetSequance();



	TFT_vWriteCmd(0X11);

	MSTK_vSetBusyWait(500000);
	//COLOR MODE
	TFT_vWriteCmd(0X3A);
	TFT_vWriteData(0X05);


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

