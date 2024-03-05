

#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"

#include"MCAL/GPIO/GPIO_int.h"
#include"MCAL/SPI/SPI_prv.h"
#include"MCAL/SPI/SPI_int.h"
#include"MCAL/SPI/SPI_cfg.h"
#include"HAL/TFT/TFT_int.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/STK/STK_int.h"

#include"tft_test.h"

int main(void)
{


	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB2, RCC_EN_SPI1);


	int x=2;
	MGPIO_vSetPinMode(GPIO_PORTA, x, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, x,GPIO_SPEED_LOW);
	MGPIO_vSetPinOutputType(GPIO_PORTA, x, GPIO_OTYPE_PUSHPULL);







	MSTK_vSetBusyWait(25000000);





//	Color_t bg;
//
//	bg.pixel.Blu = 0b11111 ;
//	bg.pixel.Grn = 0 ;
//	bg.pixel.Red = 0 ;
//
//	Color_t  rect_color = {
//			.pixel.Blu = 0,
//			.pixel.Grn = 0b111111,
//			.pixel.Red = 0
//	};
//







/**
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 1 1 0 0
 *   0 0 0 0 0 1 0 0
 *   0 0 0 0 0 1 0 0
 *   0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0
 */
//
//	TFT_vFillBackground(bg);
//
//
//	TFT_vSetXPos(20,20+30);
//	TFT_vSetYPos(20,20+60);
//
//	TFT_vFillRectangle(rect_color);
//
//
//
//	TFT_vInit();

	MGPIO_vSetPinVal(GPIO_PORTA, 2,1);
	MSTK_vSetBusyWait(25000000);
	u16 c=0;

	while(1)
	{
//		TFT_vShowImage(car , sizeof (car) / sizeof (car [0]));
//		MSTK_vSetBusyWait(25000000);
//

		c  =   MSPI_u8Transmit__receive(&SPIconfig,0X11);

		if (c==0){
		MGPIO_vSetPinVal(GPIO_PORTA, 2,0);
		}




	}
}
